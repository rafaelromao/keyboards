#!/usr/bin/env python3
"""Exercise every safe binding of the real keymap through native ZMK.

Run in the ZMK toolchain with --zmk-app, --modules-dir and --build-dir.
--update intentionally regenerates the checked-in HID snapshots. Production
keymap files are copied without secret.dtsi; private macros never enter tests.
"""

import argparse
import difflib
import json
import re
import shutil
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
SNAPSHOT = Path(__file__).with_name("keymap.snapshot.jsonl")
UNSAFE = {"bootloader", "sys_reset"}


def layers():
    keymap = (ROOT / "zmk/definitions/keymap.dtsi").read_text()
    return [
        (name, display, re.findall(r"&[^&]+", body))
        for name, display, body in re.findall(
            r'(\w+_layer)\s*\{\s*display-name\s*=\s*"([^"]+)";\s*bindings\s*=\s*<(.*?)>;',
            keymap, re.S,
        )
    ]


def hold_taps():
    features = "\n".join(path.read_text() for path in (ROOT / "zmk/features").glob("*.dtsi"))
    names = {"mt", "lt", "hlt", "hsk", "sentence_alpha2"}
    names.update(re.findall(r"(?:LAYERTAP_TP|MODTAP_TP|TAPHOLD_TP|COMBO_MUST_TAP)\(\s*(\w+)", features))
    names.update(re.findall(r'(\w+):\s*\w+\s*\{\s*compatible\s*=\s*"zmk,behavior-hold-tap"', features))
    return names


def fixture(directory):
    """Keep the production definitions verbatim; append only test controls."""
    source = directory / "source"
    for name in ("definitions", "features"):
        shutil.copytree(ROOT / "zmk" / name, source / name, dirs_exist_ok=True)
    all_layers = layers()
    hold_behaviors = hold_taps()
    count = len(all_layers)
    marker, reset, wait = 36 + count, 37 + count, 38 + count
    controls = " ".join(f"&to {index}" for index in range(count))
    controls += " &test_marker 1 &test_reset &none"
    reset_bindings = "&test_marker 0 &vim_off " + " ".join(f"&lock_off {index}" for index in range(1, count)) + " &kp F23"
    text = (
        '#include <behaviors.dtsi>\n#include <dt-bindings/zmk/keys.h>\n'
        '#include <dt-bindings/zmk/bt.h>\n#include <dt-bindings/zmk/kscan_mock.h>\n'
        f'#include "{source / "definitions/keymap.dtsi"}"\n'
        '/ { behaviors { test_marker: test_marker { compatible = "test,keymap-marker"; #binding-cells = <1>; }; '
        'test_reset: test_reset { compatible = "zmk,behavior-macro"; '
        '#binding-cells = <0>; wait-ms = <0>; tap-ms = <0>; '
        f'bindings = <{reset_bindings}>; }}; }}; }};\n'
    )
    for name, _, bindings in all_layers:
        text += f'&{{/keymap/{name}}} {{ bindings = <{" ".join(bindings)} {controls}>; }};\n'
    events, cases, focused = [], [], {}

    def tap(position, delay=10, release_delay=10):
        events.extend((f"ZMK_MOCK_PRESS(0,{position},{delay})", f"ZMK_MOCK_RELEASE(0,{position},{release_delay})"))

    def start(name, expected):
        cases.append("behavior/" + name)
        focused[cases[-1]] = expected
        tap(reset)
        tap(36)  # base layer
        tap(marker)

    def finish():
        # Give all queued tap-holds/macros/sticky state time to finish.
        tap(wait, release_delay=1600)

    dot, space, a, b, shifted_a = (7, 0x37, 0), (7, 0x2C, 0), (7, 4, 0), (7, 5, 0), (7, 4, 2)
    for name, extra in (("sentence", []), ("sentence ignores shift", [34]), ("sentence ignores repeated shift", [34, 34])):
        start(name, [dot, space, shifted_a, b])
        for position in [28, 32, *extra, 17, 1]:
            tap(position)
        finish()
    start("sentence repeat", [dot, space, shifted_a, (7, 0x0B, 0)])
    for position in [28, 32, 17, 31]:
        tap(position)
    finish()
    start("sentence number hold", [dot, space, (7, 0x24, 0), a])
    tap(28)
    tap(32)
    events.append("ZMK_MOCK_PRESS(0,32,200)")
    tap(6)
    events.append("ZMK_MOCK_RELEASE(0,32,10)")
    tap(17)
    finish()
    start("sentence accent", [dot, space, (7, 0x34, 0), (7, 0xE1, 0), a, b])
    for position in [28, 32, 33, 17, 1]:
        tap(position)
    finish()
    start("sentence num word", [dot, space, (7, 0x24, 0), space, a])
    tap(28)
    tap(32)
    events.extend(["ZMK_MOCK_PRESS(0,21,10)", "ZMK_MOCK_PRESS(0,22,10)", "ZMK_MOCK_RELEASE(0,21,10)", "ZMK_MOCK_RELEASE(0,22,10)"])
    for position in [6, 32, 17]:
        tap(position)
    finish()
    start("magic vowel", [a, (7, 0x19, 0)])
    tap(17)
    tap(26)
    finish()
    start("alternate repeat", [a, (7, 0x0B, 0)])
    tap(17)
    tap(31)
    finish()
    start("caps word", [(7, 0xE1, 0), (7, 4, 0x20), (7, 5, 0x20)])
    for position in [34, 34, 17, 1]:
        tap(position)
    finish()
    start("media hold", [(7, 0x2B, 0)])
    events.append("ZMK_MOCK_PRESS(0,34,200)")
    tap(6)  # Tab on MEDIA (its hold is Shift+Tab)
    events.append("ZMK_MOCK_RELEASE(0,34,10)")
    finish()
    start("navigation hold", [(7, 0x50, 0)])
    events.append("ZMK_MOCK_PRESS(0,31,200)")
    tap(16)  # Left on NAV
    events.append("ZMK_MOCK_RELEASE(0,31,10)")
    finish()

    for index, (name, _, bindings) in enumerate(all_layers):
        for position, binding in enumerate(bindings):
            behavior = binding.split()[0].removeprefix("&")
            if behavior in UNSAFE:
                continue
            cases.append(f"{name}/{position:02d} {binding.strip()}")
            tap(reset)
            tap(36 + index)
            tap(marker)
            # Let macros, leader timeouts, and sticky state settle before the
            # next marker. This is simulated time, not wall-clock sleeping.
            tap(position, release_delay=1600)
            if behavior in hold_behaviors:
                cases.append(f"{name}/{position:02d} hold {binding.strip()}")
                tap(reset)
                tap(36 + index)
                tap(wait, release_delay=300)  # satisfy require-prior-idle
                tap(marker)
                tap(position, delay=350, release_delay=1600)
    tap(reset)
    text += f'&kscan {{ rows = <1>; columns = <{39 + count}>; events = <{" ".join(events)}>; }};\n'
    directory.mkdir(parents=True, exist_ok=True)
    (directory / "native_sim.keymap").write_text(text)
    (directory / "native_sim.conf").write_text("CONFIG_ZMK_POINTING=y\n")
    return cases, focused


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--zmk-app", type=Path, required=True)
    parser.add_argument("--modules-dir", type=Path, required=True)
    parser.add_argument("--build-dir", type=Path, required=True)
    parser.add_argument("--update", action="store_true")
    args = parser.parse_args()
    app, build = args.zmk_app.resolve(), args.build_dir.resolve()
    config = build / "config"
    cases, focused = fixture(config)
    defaults = re.search(r"^DEF_MODULES=\((.*?)\)$", (ROOT / "scripts/zmk.sh").read_text(), re.M)[1].split()
    modules = [ROOT / "zmk/modules/zmk-sentence-case", ROOT / "zmk/tests/native"] + [args.modules_dir.resolve() / name for name in defaults]
    command = ["west", "build", "-s", str(app), "-d", str(build / "firmware"), "-b", "native_sim//zmk_test_mock", "--", f"-DZMK_CONFIG={config}", f"-DZMK_EXTRA_MODULES={';'.join(map(str, modules))}", "-DCONFIG_ASSERT=y"]
    with (build / "build.log").open("w") as log:
        result = subprocess.run(command, cwd=app, stdout=log, stderr=subprocess.STDOUT)
    if result.returncode:
        raise SystemExit(f"Native keymap build failed; see {build / 'build.log'}")
    result = subprocess.run([str(build / "firmware/zephyr/zmk.exe"), "-no-rt"], text=True, capture_output=True, check=True, timeout=120)
    (build / "events.log").write_text(result.stdout + result.stderr)
    groups, active = [], False
    for line in result.stdout.splitlines():
        if "KEYMAP_RESET" in line:
            active = False
        elif "KEYMAP_CASE" in line:
            groups.append([])
            active = True
        elif active:
            match = re.search(r"hid_listener_keycode_(pressed|released): usage_page 0x([0-9A-Fa-f]+) keycode 0x([0-9A-Fa-f]+) implicit_mods 0x([0-9A-Fa-f]+) explicit_mods 0x([0-9A-Fa-f]+)", line)
            if match:
                state, *values = match.groups()
                groups[-1].append([state, *(int(value, 16) for value in values)])
            else:
                match = re.search(r"set_layer_state: layer_changed: layer (\d+) state (\d+) locked (\d+)", line)
                if match:
                    groups[-1].append(["layer", *(int(value) for value in match.groups())])
                match = re.search(r"Modifiers set to 0x([0-9A-Fa-f]+)", line)
                if match:
                    groups[-1].append(["mods", int(match[1], 16)])
                match = re.search(r"Mouse (buttons|movement|scroll) set to (.*)$", line)
                if match:
                    groups[-1].append(["mouse", *match.groups()])
    if len(groups) != len(cases):
        raise SystemExit(f"Expected {len(cases)} binding markers, got {len(groups)}; see {build / 'events.log'}")
    failures = []
    for name, group in zip(cases, groups):
        if name in focused:
            pressed = [tuple(event[1:4]) for event in group if event[0] == "pressed"]
            if pressed != focused[name]:
                failures.append(name)
                print(f"FAIL {name}\n  expected {focused[name]}\n  actual   {pressed}")
    if failures:
        raise SystemExit(f"{len(failures)} focused keymap scenarios failed; see {build / 'events.log'}")
    actual = "".join(json.dumps({"case": name, "events": events}, ensure_ascii=False) + "\n" for name, events in zip(cases, groups))
    (build / "keymap.actual.jsonl").write_text(actual)
    if args.update:
        SNAPSHOT.write_text(actual)
        print(f"Updated {SNAPSHOT}: {len(cases)} bindings across {len(layers())} layers.")
    elif SNAPSHOT.read_text() != actual:
        print("".join(difflib.unified_diff(SNAPSHOT.read_text().splitlines(True), actual.splitlines(True), fromfile=str(SNAPSHOT), tofile="actual")))
        raise SystemExit(f"Keymap HID snapshot differs; see {build / 'keymap.actual.jsonl'}")
    else:
        print(f"PASS: {len(cases)} bindings across all {len(layers())} layers; HID snapshots match.")


if __name__ == "__main__":
    main()

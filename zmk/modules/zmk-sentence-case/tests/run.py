#!/usr/bin/env python3
"""Build once, then test the real behaviors and HID event pipeline in native ZMK.

Requires the same west workspace/toolchain as ZMK's app/run-test.sh. No C mocks
or Python reimplementation of the sentence-case state machine are used.
"""

import argparse
import re
import subprocess
from pathlib import Path


MODULE = Path(__file__).resolve().parents[1]
# Matrix positions in behaviors.dtsi.
SPACE, DOT, QUESTION, EXCL, A, B, SHIFT, HRM, NUM, RAW_SHIFT, ONE, GT, COMMA, BSPC, LEFT, CTRL, LSHIFT, RSHIFT, MEDIA, QUOTE, QU, ALPHA2, K, CAPS_A, MORPH, REPEAT, SHIFT_THUMB, SPACE_THUMB, ESC, SHIFT_DOT, ALTGR, MARKER = range(32)


def tap(key, delay=10):
    return [(key, True, delay), (key, False, 10)]


def down(key, delay=10):
    return [(key, True, delay)]


def up(key, delay=10):
    return [(key, False, delay)]


# Expected presses: (usage page, HID usage, implicit modifiers). Explicit
# modifier key events are included too, so duplicate/stuck-shift regressions
# cannot hide behind a check of just the final letter.
def key(code, mods=0, page=7):
    return (page, code, mods)


dot, space, a, b = key(0x37), key(0x2C), key(4), key(5)
capital_a, capital_b = key(4, 2), key(5, 2)
prefix = tap(DOT) + tap(SPACE)
prefix_output = [dot, space]


def scenarios():
    for name, position, punctuation in (
        ("dot", DOT, dot),
        ("question", QUESTION, key(0x38, 2)),
        ("exclamation", EXCL, key(0x1E, 2)),
    ):
        yield name, tap(position) + tap(SPACE) + tap(A) + tap(B), [punctuation, space, capital_a, b]

    yield "ordinary space", tap(B) + tap(SPACE) + tap(A), [b, space, a]
    yield "no previous character", tap(SPACE) + tap(A), [space, a]
    yield "punctuation without space", tap(DOT) + tap(A), [dot, a]
    yield "only latest character counts", tap(DOT) + tap(B) + tap(SPACE) + tap(A), [dot, b, space, a]
    yield "punctuation sequence", tap(DOT) + tap(QUESTION) + tap(EXCL) + tap(SPACE) + tap(A), [dot, key(0x38, 2), key(0x1E, 2), space, capital_a]
    yield "terminator timeout", tap(DOT, 2010) + tap(SPACE) + tap(A), prefix_output + [a]
    # Delays in kscan-mock occur AFTER each event, not before it.
    yield "pending timeout", tap(DOT) + tap(SPACE, 1010) + tap(A), prefix_output + [a]
    yield "within timeout", tap(DOT) + tap(SPACE, 900) + tap(A), prefix_output + [capital_a]
    yield "extra space consumes", prefix + tap(SPACE) + tap(A), prefix_output + [space, a]
    yield "quote consumes", prefix + tap(QUOTE) + tap(A), prefix_output + [key(0x34), a]
    yield "shift tap ignored", prefix + tap(SHIFT) + tap(A) + tap(B), prefix_output + [capital_a, b]
    yield "repeated shift taps ignored", prefix + tap(SHIFT) * 3 + tap(A), prefix_output + [capital_a]
    yield "shift after expiry works normally", tap(DOT) + tap(SPACE, 1010) + tap(SHIFT) + tap(A), prefix_output + [key(0xE1), a]
    yield "shift thumb tap ignored", prefix + tap(SHIFT_THUMB) + tap(A), prefix_output + [capital_a]
    yield "shift thumb media hold", prefix + down(SHIFT_THUMB, 200) + tap(A) + up(SHIFT_THUMB) + tap(B), prefix_output + [key(0xEA, page=12), b]
    yield "ordinary sticky shift works", tap(SHIFT) + tap(A) + tap(B), [key(0xE1), a, b]
    yield "digit consumes without shift", prefix + tap(ONE) + tap(A), prefix_output + [key(0x1E), a]
    yield "number layer hold", prefix + down(NUM) + tap(A) + up(NUM) + tap(B), prefix_output + [key(0x1E), b]
    yield "home row tap", prefix + tap(HRM) + tap(B), prefix_output + [capital_a, b]
    yield "home row hold consumes", prefix + down(HRM, 200) + tap(B) + up(HRM) + tap(A), prefix_output + [key(0xE1), b, a]
    yield "held space rollover", tap(DOT) + down(SPACE) + tap(A) + up(SPACE) + tap(B), prefix_output + [capital_a, b]
    yield "release cannot rearm", tap(DOT) + down(SPACE) + tap(A) + up(SPACE) + tap(A), prefix_output + [capital_a, a]
    yield "space hold tap", tap(DOT) + tap(SPACE_THUMB) + tap(A), prefix_output + [capital_a]
    yield "space thumb number hold", tap(DOT) + down(SPACE_THUMB, 200) + tap(A) + up(SPACE_THUMB) + tap(B), [dot, key(0x1E), b]
    for name, position, event in (
        ("comma", COMMA, key(0x36)),
        ("backspace", BSPC, key(0x2A)),
        ("navigation", LEFT, key(0x50)),
        ("cancel", ESC, key(0x29)),
        ("consumer page", MEDIA, key(0xE9, page=12)),
    ):
        yield name + " consumes", prefix + tap(position) + tap(A), prefix_output + [event, a]
    yield "modifier consumes", prefix + tap(CTRL) + tap(A), prefix_output + [key(0xE0), a]
    yield "releases do not consume", down(B) + prefix + up(B) + tap(A), [b] + prefix_output + [capital_a]
    yield "uppercase binding", prefix + tap(CAPS_A) + tap(B), prefix_output + [key(4, 0x22), b]
    yield "macro shifts first letter only", prefix + tap(QU) + tap(A), prefix_output + [key(0x14, 2), key(0x18), a]
    yield "repeat remembers capital", prefix + tap(A) + tap(REPEAT), prefix_output + [capital_a, capital_a]
    yield "morph release follows press branch", prefix + tap(MORPH) + tap(A), prefix_output + [key(7, 2), a]
    yield "morph normal branch", tap(MORPH) + tap(A), [key(6), a]
    yield "letter combo", prefix + down(A) + down(B) + up(A) + up(B) + tap(A), prefix_output + [key(0x0E, 2), a]
    yield "accented sentence start", prefix + tap(ALPHA2) + tap(A) + tap(B), prefix_output + [key(0x34), key(0xE1), a, b]
    yield "ordinary accent", tap(ALPHA2) + tap(A), [key(0x34), a]
    yield "shifted qu macro", prefix + tap(ALPHA2) + tap(QU) + tap(A), prefix_output + [key(0x14, 2), key(0x18), a]
    yield "shifted dot is not terminator", tap(SHIFT_DOT) + tap(SPACE) + tap(A), [key(0x37, 2), space, a]
    for name, modifier in (("left shift", LSHIFT), ("right shift", RSHIFT), ("ctrl", CTRL), ("altgr", ALTGR)):
        modifier_code = {LSHIFT: 0xE1, RSHIFT: 0xE5, CTRL: 0xE0, ALTGR: 0xE6}[modifier]
        yield name + " dot is not terminator", down(modifier) + tap(DOT) + up(modifier) + tap(SPACE) + tap(A), [key(modifier_code), dot, space, a]
    yield "terminator key release ignored", down(DOT) + tap(SPACE) + up(DOT) + tap(A), prefix_output + [capital_a]
    yield "repeated sentences", prefix + tap(A) + prefix + tap(B), prefix_output + [capital_a] + prefix_output + [capital_b]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--zmk-app", type=Path, required=True)
    parser.add_argument("--build-dir", type=Path, required=True)
    parser.add_argument("--adaptive-module", type=Path)
    parser.add_argument("--auto-layer-module", type=Path)
    args = parser.parse_args()
    app, build = args.zmk_app.resolve(), args.build_dir.resolve()
    config = build / "config"
    config.mkdir(parents=True, exist_ok=True)
    cases = list(scenarios())
    modules = [str(MODULE)]
    defines = ""
    if args.adaptive_module:
        modules.append(str(args.adaptive_module.resolve()))
        defines += "#define SENTENCE_TEST_ADAPTIVE\n"
        cases.extend([
            ("adaptive remembers capital", prefix + tap(A) + tap(K), prefix_output + [capital_a, key(0x0B)]),
            ("adaptive strict modifiers", tap(A) + tap(K), [a, key(0x1D)]),
        ])
    if args.auto_layer_module:
        modules.append(str(args.auto_layer_module.resolve()))
        defines += "#define SENTENCE_TEST_AUTO_LAYER\n"
        cases.extend([
            ("num word consumes without shift", prefix + tap(RAW_SHIFT) + tap(A) + tap(B) + tap(A), prefix_output + [key(0x1E), b, a]),
        ])
    events = []
    for _, sequence, _ in cases:
        events.extend(tap(MARKER) + sequence)
    scan = "\n".join(f"ZMK_MOCK_{'PRESS' if state else 'RELEASE'}(0,{position},{delay})" for position, state, delay in events)
    (config / "native_sim.keymap").write_text(
        defines + f'#include "{MODULE / "tests/behaviors.dtsi"}"\n'
        f'&kscan {{ rows = <1>; columns = <32>; events = <{scan}>; }};\n'
    )
    command = ["west", "build", "-s", str(app), "-d", str(build / "firmware"), "-b", "native_sim//zmk_test_mock", "--", f"-DZMK_CONFIG={config}", f"-DZMK_EXTRA_MODULES={';'.join(modules)}", "-DCONFIG_ASSERT=y"]
    with (build / "build.log").open("w") as log:
        result = subprocess.run(command, cwd=app, stdout=log, stderr=subprocess.STDOUT)
    if result.returncode:
        raise SystemExit(f"Native build failed; see {build / 'build.log'}")
    result = subprocess.run([str(build / "firmware/zephyr/zmk.exe")], text=True, capture_output=True, check=True)
    (build / "events.log").write_text(result.stdout + result.stderr)
    groups, held = [], {}
    for state, page, code, mods in re.findall(r"hid_listener_keycode_(pressed|released): usage_page 0x([0-9A-Fa-f]+) keycode 0x([0-9A-Fa-f]+) implicit_mods 0x([0-9A-Fa-f]+)", result.stdout):
        event = tuple(int(value, 16) for value in (page, code, mods))
        if event == key(0x73):  # F24 separates cases and clears any pending state.
            if state == "pressed":
                assert not held, f"Unreleased keys before case {len(groups)}: {held}"
                groups.append([])
        elif groups:
            if not (event[0] == 7 and 0xE0 <= event[1] <= 0xE7):
                usage = event[:2]
                if state == "pressed":
                    assert usage not in held, f"Duplicate press in case {len(groups)}: {event}"
                    held[usage] = True
                else:
                    assert usage in held, f"Unmatched release in case {len(groups)}: {event}"
                    del held[usage]
            if state == "pressed":
                groups[-1].append(event)
    assert not held, f"Unreleased keys after final case: {held}"
    failures = []
    if len(groups) != len(cases):
        raise SystemExit(f"Expected {len(cases)} case markers, got {len(groups)}; see {build / 'events.log'}")
    for (name, _, expected), actual in zip(cases, groups):
        if expected != actual:
            failures.append(name)
            print(f"FAIL {name}\n  expected {expected}\n  actual   {actual}")
        else:
            print(f"PASS {name}")
    if failures:
        raise SystemExit(f"{len(failures)}/{len(cases)} failed; see {build / 'events.log'}")
    print(f"All {len(cases)} native ZMK sentence-case scenarios passed.")


if __name__ == "__main__":
    main()

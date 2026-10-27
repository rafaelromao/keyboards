#!/bin/bash
# Run inside the initialized ZMK toolchain container. Does not fetch or checkout.
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
APP="$ROOT/modules/zmkfirmware/zmk/app"
DISPLAY_MODULE="${ZMK_DONGLE_DISPLAY_MODULE:?Set to the absolute module working-tree path}"
OUTPUT="${ZMK_DISPLAY_BUILD_DIR:-$ROOT/build/display-validation}"
MODULES="$DISPLAY_MODULE"
for module in rafaelromao/zmk-sentence-case urob/zmk-leader-key urob/zmk-auto-layer \
    urob/zmk-adaptive-key rafaelromao/zmk-layer-morph rafaelromao/zmk-vim-mode \
    rafaelromao/zmk-layer-hud rafaelromao/zmk-os-detection; do
    MODULES+=";$ROOT/modules/$module"
done

build() {
    local config="$1" shield="$2" extra="${3:-}"
    local variant="${4:-$shield}"
    local directory="$OUTPUT/$variant"
    local extra_args=()
    if [[ -n "${5:-}" ]]; then
        extra_args+=("-DEXTRA_CONF_FILE=$5")
    fi
    if [[ -n "${6:-}" ]]; then
        extra_args+=("-DEXTRA_DTC_OVERLAY_FILE=$6")
    fi
    mkdir -p "$OUTPUT"
    if ! west build -s "$APP" -b nice_nano//zmk -d "$directory" -S layer-hud-usb-uart -- \
        "-DSHIELD=$shield $extra" "-DZMK_CONFIG=$ROOT/zmk/keyboards/$config" \
        "-DZMK_EXTRA_MODULES=$MODULES" "${extra_args[@]}" >"$OUTPUT/$variant.log" 2>&1; then
        tail -100 "$OUTPUT/$variant.log"
        return 1
    fi
    echo "PASS $variant"
}

build bastardkb/dilemma dilemma_central_dongle dongle_display_relay
build bastardkb/dilemma dilemma_peripheral_left dongle_display
build bastardkb/dilemma dilemma_peripheral_right
build bastardkb/dilemma dilemma_central_left dongle_display
build rafaelromao/diamond diamond_central_dongle dongle_display
build rafaelromao/choc_diamond choc_diamond_central_dongle dongle_display
build mabroum/rommana rommana_central_dongle dongle_display

# Config overrides prove that small screens do not lose optional widgets, and
# the same screen/relay supports a 128x64 display on a peripheral as well.
WIDGETS="$ROOT/zmk/tests/fixtures/display-all-widgets.conf"
TALL="$ROOT/zmk/tests/fixtures/display-128x64.overlay"
build bastardkb/dilemma dilemma_peripheral_left dongle_display dilemma_peripheral_all_32 "$WIDGETS"
build bastardkb/dilemma dilemma_peripheral_left dongle_display dilemma_peripheral_all_64 "$WIDGETS" "$TALL"
build bastardkb/dilemma dilemma_central_left dongle_display dilemma_central_all_32 "$WIDGETS"

python3 - "$OUTPUT" <<'PY'
from pathlib import Path
import os
import re
import subprocess
import sys

root = Path(sys.argv[1])
def config(shield):
    return (root / shield / "zephyr/.config").read_text()
central = config("dilemma_central_dongle")
left = config("dilemma_peripheral_left")
right = config("dilemma_peripheral_right")
for name in ("ZMK_DISPLAY", "ZMK_BATTERY", "ZMK_BATTERY_REPORTING", "LVGL"):
    assert f"CONFIG_{name}=y" not in central, name
assert "CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SYNC=y" in central
assert "CONFIG_ZMK_SPLIT_BLE_CENTRAL_PERIPHERALS=2" in central
assert "CONFIG_ZMK_SPLIT_ROLE_CENTRAL=y" not in left
assert "CONFIG_ZMK_DISPLAY=y" in left
assert "CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SYNC=y" in left
assert "CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SCREEN=y" not in left
for name in ("ZMK_WPM", "ZMK_HID_INDICATORS"):
    assert f"CONFIG_{name}=y" in central, name
    assert f"CONFIG_{name}=y" not in left, name
assert "CONFIG_ZMK_INPUT_SPLIT=y" in right
assert "CONFIG_INPUT_PINNACLE=y" in right
nm = Path(os.environ["ZEPHYR_SDK_INSTALL_DIR"]) / "arm-zephyr-eabi/bin/arm-zephyr-eabi-nm"
elf = root / "dilemma_peripheral_left/zephyr/zmk.elf"
symbols = subprocess.check_output([str(nm), str(elf)], text=True)
assert re.search(r" T zmk_display_status_screen$", symbols, re.MULTILINE)
assert re.search(r" t receive_status$", symbols, re.MULTILINE)
assert b"ddstat\0" in elf.read_bytes(), "Split receiver must use its short device name"
central_symbols = subprocess.check_output(
    [str(nm), str(root / "dilemma_central_dongle/zephyr/zmk.elf")], text=True
)
assert "zmk_battery_state_of_charge" not in central_symbols
for variant in ("dilemma_peripheral_all_32", "dilemma_peripheral_all_64", "dilemma_central_all_32"):
    built = config(variant)
    for widget in ("BONGO_CAT", "MODIFIERS", "LAYER", "WPM"):
        assert f"CONFIG_ZMK_DONGLE_DISPLAY_{widget}=y" in built, (variant, widget)
    assert "CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SCREEN=y" not in built
    symbols = subprocess.check_output([str(nm), str(root / variant / "zephyr/zmk.elf")], text=True)
    for widget in ("bongo_cat", "modifiers", "hid_indicators", "layer_status", "wpm_status", "output_status", "dongle_battery_status"):
        assert re.search(rf" T zmk_widget_{widget}_init$", symbols, re.MULTILINE), (variant, widget)
    if "peripheral" in variant:
        assert "zmk_keymap_highest_layer_active" not in symbols
        assert "zmk_wpm_get_state" not in symbols
    dts = (root / variant / "zephyr/zephyr.dts").read_text()
    height = "0x40" if variant.endswith("64") else "0x20"
    assert f"height = < {height} >" in dts, variant
print("PASS generated roles, headless central, and original widgets on 128x32/128x64")
PY

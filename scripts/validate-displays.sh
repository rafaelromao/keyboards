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
    local directory="$OUTPUT/$shield"
    mkdir -p "$OUTPUT"
    if ! west build -s "$APP" -b nice_nano//zmk -d "$directory" -S layer-hud-usb-uart -- \
        "-DSHIELD=$shield $extra" "-DZMK_CONFIG=$ROOT/zmk/keyboards/$config" \
        "-DZMK_EXTRA_MODULES=$MODULES" >"$OUTPUT/$shield.log" 2>&1; then
        tail -100 "$OUTPUT/$shield.log"
        return 1
    fi
    echo "PASS $shield"
}

build bastardkb/dilemma dilemma_central_dongle dongle_display_relay
build bastardkb/dilemma dilemma_peripheral_left dongle_display
build bastardkb/dilemma dilemma_peripheral_right
build bastardkb/dilemma dilemma_central_left dongle_display
build rafaelromao/diamond diamond_central_dongle dongle_display
build rafaelromao/choc_diamond choc_diamond_central_dongle dongle_display
build mabroum/rommana rommana_central_dongle dongle_display

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
print("PASS generated Dilemma roles and hardware settings")
PY

#!/bin/bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
APP="${ZMK_APP:-$ROOT/modules/zmkfirmware/zmk/app}"
MODULES="${ZMK_MODULES_DIR:-$ROOT/modules}"
OUTPUT="${ZMK_TEST_BUILD_DIR:-$ROOT/build/zmk-tests}"

python3 -m unittest discover -s "$ROOT/zmk/tests" -v
python3 "$ROOT/zmk/modules/zmk-sentence-case/tests/run.py" \
    --zmk-app "$APP" --build-dir "$OUTPUT/sentence"
python3 "$ROOT/zmk/tests/native_keymap.py" \
    --zmk-app "$APP" --modules-dir "$MODULES" --build-dir "$OUTPUT/keymap"

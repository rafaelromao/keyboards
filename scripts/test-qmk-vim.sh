#!/bin/bash
set -euo pipefail
ulimit -c 0

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
TEST_DIR="$(mktemp -d "${TMPDIR:-/tmp}/qmk-vim-test.XXXXXX")"
trap 'rm -f "$TEST_DIR/test"; rmdir "$TEST_DIR"' EXIT

"${CC:-cc}" -std=c11 -Wall -Wextra -Werror \
    -DRR_VIM_ENABLE -DQMK_KEYBOARD_H='"qmk_stub.h"' \
    -I"$ROOT/qmk/tests/vim" -I"$ROOT/qmk/users/rafaelromao" \
    "$ROOT/qmk/tests/vim/test.c" \
    "$ROOT/qmk/users/rafaelromao/features/vim.c" \
    -o "$TEST_DIR/test"
"$TEST_DIR/test"

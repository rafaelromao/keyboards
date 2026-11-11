#!/bin/bash
set -euo pipefail
ulimit -c 0

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
TEST_DIR="$(mktemp -d "${TMPDIR:-/tmp/opencode}/qmk-base-test.XXXXXX")"
trap 'rm -f "$TEST_DIR/test"; rmdir "$TEST_DIR"' EXIT

"${CC:-cc}" -std=c11 -Wall -Wextra -Werror \
    -DQMK_KEYBOARD_H='"qmk_stub.h"' \
    -I"$ROOT/qmk/tests/base" -I"$ROOT/qmk/users/rafaelromao" \
    "$ROOT/qmk/tests/base/test.c" \
    -o "$TEST_DIR/test"
"$TEST_DIR/test"

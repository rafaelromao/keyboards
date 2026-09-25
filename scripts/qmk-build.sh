#!/bin/bash
#
# Builds the QMK firmware for the boards that cannot run ZMK. Runs inside the
# toolchain container (through b.sh, as `b bm40` / `b xd75`) or inside the QMK
# CLI container started by scripts/qmk.sh. It only needs git, make, the AVR
# toolchain and the qmk CLI, so it also works on a host that has those.
#
#   qmk-build.sh <bm40|xd75|all> [-p]
#
# QMK is a git submodule at modules/qmk/qmk_firmware, cloned on first use into
# the modules volume and pinned to REVISION the way zmk.sh pins ZMK. The
# keymaps and the shared userspace live in qmk/, which QMK reads as an
# External Userspace (qmk.json), so nothing is symlinked into the submodule.

set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
QMK_MODULE="modules/qmk/qmk_firmware"
QMK_HOME="$PROJECT_DIR/$QMK_MODULE"
QMK_USERSPACE="$PROJECT_DIR/qmk"
ARTIFACTS="$PROJECT_DIR/build/artifacts"
# Pinned, like ZMK in zmk.sh. Moving it is a deliberate act: bump it, rebuild
# both boards, and check the userspace still compiles. Keep the gitlink that is
# committed for modules/qmk/qmk_firmware in sync with it.
REVISION="0.34.4"
KEYMAP="rafaelromao"

usage() {
    echo "Usage: $(basename "$0") <bm40|xd75|all> [-p]"
    echo
    echo "  bm40   kprepublic/bm40hsrgb/rev1"
    echo "  xd75   xiudi/xd75"
    echo "  all    both boards"
    echo "  -p     pristine build (qmk clean first)"
    exit 1
}

[[ $# -ge 1 ]] || usage
TARGET="$1"
shift
PRISTINE=""
while getopts "p" opt; do
    case $opt in
        p) PRISTINE="true" ;;
        *) usage ;;
    esac
done

case "$TARGET" in
    bm40) BOARDS=(kprepublic/bm40hsrgb/rev1) ;;
    xd75) BOARDS=(xiudi/xd75) ;;
    all|a) BOARDS=(kprepublic/bm40hsrgb/rev1 xiudi/xd75) ;;
    *) echo "Unknown target: '$TARGET'"; usage ;;
esac

cd "$PROJECT_DIR"

# --- QMK submodule ---
# The test is for the Makefile rather than the directory: a clone that failed
# part way leaves a directory behind, and a mere existence check would treat
# it as "already cloned" forever (same guard as zmk.sh).
if [[ ! -f "$QMK_HOME/Makefile" ]]; then
    echo "Add git sub-module: qmk/qmk_firmware"
    if [[ -d "$QMK_HOME" ]]; then
        echo "  (clearing incomplete clone at $QMK_HOME)"
        rm -rf "$QMK_HOME"
        git submodule deinit -f "$QMK_MODULE" 2>/dev/null || true
        rm -rf "$PROJECT_DIR/.git/modules/$QMK_MODULE"
    fi
    git submodule update --init "$QMK_MODULE"
fi

echo "Checking out qmk_firmware $REVISION..."
cd "$QMK_HOME"
git fetch --tags --force
git checkout -f "$REVISION"
# QMK's own submodules (ChibiOS, LUFA, ...). Cheap when already in place.
make git-submodule
cd "$PROJECT_DIR"

# --- QMK CLI configuration ---
export QMK_HOME QMK_USERSPACE
qmk config user.qmk_home="$QMK_HOME" user.overlay_dir="$QMK_USERSPACE" >/dev/null

# --- Build ---
mkdir -p "$ARTIFACTS"
SUMMARY=()
for BOARD in "${BOARDS[@]}"; do
    echo
    echo "--- Building $BOARD:$KEYMAP ---"
    if [[ -n "$PRISTINE" ]]; then
        qmk clean
    fi
    LOG="$(mktemp)"
    set +e
    qmk compile -kb "$BOARD" -km "$KEYMAP" 2>&1 | tee "$LOG"
    STATUS=${PIPESTATUS[0]}
    set -e
    SIZE_LINE="$(grep -E 'firmware size|The firmware is too large' "$LOG" | tail -1 || true)"
    rm -f "$LOG"
    # With an overlay dir, qmk copies the firmware next to qmk.json; keep it
    # with the ZMK artifacts instead.
    ARTIFACT_NAME="${BOARD//\//_}_${KEYMAP}"
    for f in "$QMK_USERSPACE/$ARTIFACT_NAME".hex "$QMK_HOME/.build/$ARTIFACT_NAME".hex; do
        if [[ -f "$f" ]]; then
            mv -f "$f" "$ARTIFACTS/$ARTIFACT_NAME.hex"
            break
        fi
    done
    if [[ $STATUS -ne 0 ]]; then
        SUMMARY+=("$BOARD: FAILED  ${SIZE_LINE}")
    else
        SUMMARY+=("$BOARD: ${SIZE_LINE:-built} -> build/artifacts/$ARTIFACT_NAME.hex")
    fi
done

echo
echo "=== Summary ==="
printf '%s\n' "${SUMMARY[@]}"
for line in "${SUMMARY[@]}"; do
    [[ "$line" == *FAILED* ]] && exit 1
done
exit 0

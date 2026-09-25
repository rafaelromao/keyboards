#!/bin/bash

set -euo pipefail

# --- Build Functions ---

build_reset() {
    echo "--- Building Reset ---"
    ./scripts/zmk.sh "-s" "settings_reset" "$@"
}

build_rommana() {
    echo "--- Building Rommana ---"
    ./scripts/zmk.sh "mabroum/rommana" "cl" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/zmk.sh "mabroum/rommana" "pr" "$@"
        ./scripts/zmk.sh "mabroum/rommana" "pl" "$@"
        ./scripts/zmk.sh "mabroum/rommana" "cd" "-e" "dongle_display" "-m" "englmaxi/zmk-dongle-display" "$@"
    fi
}

build_wired_rommana() {
    echo "--- Building Wired Rommana ---"
    ./scripts/zmk.sh "mabroum/wired_rommana" "l" "-b" "xiao_rp2040//zmk" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/zmk.sh "mabroum/wired_rommana" "r" "-b" "xiao_rp2040//zmk" "$@"
    fi
}

build_diamond() {
    echo "--- Building Diamond ---"
    ./scripts/zmk.sh "rafaelromao/diamond" "cd" "-e" "dongle_display" "-m" "englmaxi/zmk-dongle-display" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/zmk.sh "rafaelromao/diamond" "pr" "$@"
        ./scripts/zmk.sh "rafaelromao/diamond" "pl" "$@"
        ./scripts/zmk.sh "rafaelromao/diamond" "cl" "$@"
    fi
}

build_wired_diamond() {
    echo "--- Building Wired Diamond ---"
    ./scripts/zmk.sh "rafaelromao/wired_diamond" "l" "-b" "xiao_rp2040//zmk" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/zmk.sh "rafaelromao/wired_diamond" "r" "-b" "xiao_rp2040//zmk" "$@"
    fi
}

build_choc_diamond() {
    echo "--- Building Choc Diamond ---"
    ./scripts/zmk.sh "rafaelromao/choc_diamond" "cl" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/zmk.sh "rafaelromao/choc_diamond" "pr" "$@"
        ./scripts/zmk.sh "rafaelromao/choc_diamond" "pl" "$@"
        ./scripts/zmk.sh "rafaelromao/choc_diamond" "cd" "-e" "dongle_display" "-m" "englmaxi/zmk-dongle-display" "$@"
    fi
}

build_zen() {
    echo "--- Building Corneish Zen ---"
    ./scripts/zmk.sh "lowprokb.ca/corneish-zen" "-b" "corneish_zen_left//zmk" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/zmk.sh "lowprokb.ca/corneish-zen" "-b" "corneish_zen_right//zmk" "$@"
        ./scripts/zmk.sh "lowprokb.ca/corneish-zen-with-dongle" "corneish_zen_dongle" "$@"
        ./scripts/zmk.sh "lowprokb.ca/corneish-zen-with-dongle" "-b" "corneish_zen_left//zmk" "$@"
        ./scripts/zmk.sh "lowprokb.ca/corneish-zen-with-dongle" "-b" "corneish_zen_right//zmk" "$@"
    fi
}

build_dilemma() {
    echo "--- Building Dilemma ---"
    ./scripts/zmk.sh "bastardkb/dilemma" "cl" "-e" "dongle_display" "-m" "englmaxi/zmk-dongle-display" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/zmk.sh "bastardkb/dilemma" "pr" "$@"
        ./scripts/zmk.sh "bastardkb/dilemma" "pl" "$@"
        ./scripts/zmk.sh "bastardkb/dilemma" "cd" "$@"
    fi
}

# The QMK boards build with the QMK toolchain that the image carries next to
# the ZMK one. qmk-build.sh takes only -p (pristine), so the zmk.sh options
# that `b all -v` or similar pass along are dropped here rather than rejected.
build_qmk() {
    local board="$1"
    shift
    if ! command -v qmk >/dev/null 2>&1; then
        echo "The qmk CLI is not in this image. Rebuild it from the Containerfile:"
        echo "  podman build -t zmk-toolchain:0.17.0 ."
        echo "or build from the host with: scripts/qmk.sh $board"
        exit 1
    fi
    local args=()
    for arg in "$@"; do
        if [[ "$arg" == "-p" ]]; then
            args+=("-p")
        fi
    done
    ./scripts/qmk-build.sh "$board" ${args[@]+"${args[@]}"}
}

build_bm40() {
    echo "--- Building BM40 (QMK) ---"
    build_qmk "bm40" "$@"
}

build_xd75() {
    echo "--- Building XD75 (QMK) ---"
    build_qmk "xd75" "$@"
}

# --- Main Script ---

complete=false

if [[ -z "${1:-}" || "${1:-}" == "-h" || "${1:-}" == "--help" ]]; then
    echo "Usage: $(basename "$0") <keyboard> [-c|--complete] [zmk.sh options]"
    echo
    echo "This script builds the firmware for a given keyboard, calling the underlying"
    echo "zmk.sh script (ZMK boards) or qmk-build.sh script (QMK boards) with the"
    echo "correct parameters."
    echo "Additional arguments are passed to zmk.sh; the QMK boards only take -p."
    echo
    echo "Available keyboards: all, reset, rommana, wired_rommana, diamond, wired_diamond, choc_diamond, zen, dilemma, bm40, xd75"
    echo
    echo "Examples:"
    echo "  $(basename "$0") rommana"
    echo "  $(basename "$0") rommana -c"
    echo "  $(basename "$0") rommana -c -v"
    echo "  $(basename "$0") bm40 -p"
    exit 1
fi

if [[ "${2:-}" == "-c" || "${2:-}" == "--complete" ]]; then
    complete=true
    KEYBOARD="$1"
    shift 2
else
    KEYBOARD="$1"
    shift 1
fi

case "$KEYBOARD" in
    all|a)
        build_reset "$@"
        build_rommana "$@"
        build_wired_rommana "$@"
        build_diamond "$@"
        build_wired_diamond "$@"
        build_choc_diamond "$@"
        build_zen "$@"
        build_dilemma "$@"
        build_bm40 "$@"
        build_xd75 "$@"
        ;;
    reset|s)
        build_reset "$@"
        ;;
    rommana|r)
        build_rommana "$@"
        ;;
    wired_rommana|wr)
        build_wired_rommana "$@"
        ;;
    diamond|d)
        build_diamond "$@"
        ;;
    wired_diamond|wd)
        build_wired_diamond "$@"
        ;;
    choc_diamond|cd|c)
        build_choc_diamond "$@"
        ;;
    zen|z)
        build_zen "$@"
        ;;
    dilemma|m)
        build_dilemma "$@"
        ;;
    bm40|bm)
        build_bm40 "$@"
        ;;
    xd75|xd)
        build_xd75 "$@"
        ;;
    *)
        echo "Unknown Keyboard: '$KEYBOARD'"
        exit 1
        ;;
esac

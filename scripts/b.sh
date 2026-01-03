#!/bin/bash

set -euo pipefail

# --- Build Functions ---

build_reset() {
    echo "--- Building Reset ---"
    ./scripts/build.sh "-s" "settings_reset" "$@"
}

build_rommana() {
    echo "--- Building Rommana ---"
    ./scripts/build.sh "mabroum/rommana" "cl" "$@"
}

build_wired_rommana() {
    echo "--- Building Wired Rommana ---"
    ./scripts/build.sh "mabroum/wired_rommana" "l" "LINUX" "-b" "xiao_rp2040" "$@"
}

build_diamond() {
    echo "--- Building Diamond ---"
    ./scripts/build.sh "rafaelromao/diamond" "cl" "$@"
}

build_wired_diamond() {
    echo "--- Building Wired Diamond ---"
    ./scripts/build.sh "rafaelromao/wired_diamond" "l" "LINUX" "-b" "xiao_rp2040" "$@"
}

build_choc_diamond() {
    echo "--- Building Choc Diamond ---"
    ./scripts/build.sh "rafaelromao/choc_diamond" "cd" "LINUX" "-e" "dongle_display" "-m" "rafaelromao/zmk-dongle-display" "$@"
}

build_zen() {
    echo "--- Building Corneish Zen ---"
    ./scripts/build.sh "lowprokb.ca/corneish-zen" "-b" "corneish_zen_v2_left" "-o" "LINUX" "-z" "caksoylar/zmk" "-r" "caksoylar/zen-v1+v2" "$@"
}

build_zen_dongle() {
    echo "--- Building Corneish Zen Dongle ---"
    ./scripts/build.sh "lowprokb.ca/corneish-zen-with-dongle" "corneish_zen_dongle" "LINUX" "$@"
}

build_dilemma() {
    echo "--- Building Dilemma ---"
    ./scripts/build.sh "bastardkb/dilemma" "l" "LINUX" "-e" "dongle_display" "-m" "rafaelromao/zmk-dongle-display" "$@"
}

build_dilemma_right() {
    echo "--- Building Dilemma Right Side ---"
    ./scripts/build.sh "bastardkb/dilemma" "r" "LINUX" "$@"
}

# Building Corneish Zen peripherals
# build lowprokb.ca/corneish-zen -b corneish_zen_v2_left -o LINUX -z caksoylar/zmk -r caksoylar/zen-v1+v2
# build lowprokb.ca/corneish-zen-with-dongle -b corneish_zen_v2_left -o LINUX -z caksoylar/zmk -r caksoylar/zen-v1+v2
# build lowprokb.ca/corneish-zen-with-dongle -b corneish_zen_v2_right -o LINUX -z caksoylar/zmk -r caksoylar/zen-v1+v2
#
# Building Dilemma peripherals
# build bastardkb/dilemma r LINUX -m petejohanson/cirque-input-module

# --- Main Script ---

if [[ $# -lt 1 || "$1" == "-h" || "$1" == "--help" ]]; then
    echo "Usage: $(basename "$0") <keyboard> [build.sh options]"
    echo
    echo "This script builds the firmware for a given keyboard, calling the underlying"
    echo "build.sh script with the correct parameters."
    echo "Additional arguments are passed to the underlying build.sh script."
    echo
    echo "Available keyboards: all, rommana, wired_rommana, diamond, wired_diamond, choc_diamond, zen, dilemma"
    echo
    echo "Examples:"
    echo "  $(basename "$0") rommana"
    echo "  $(basename "$0") all -v"
    exit 1
fi

KEYBOARD="$1"
shift # The rest of the arguments are passed to build.sh

case "$KEYBOARD" in
    all|a)
        build_reset "$@"
        build_rommana "$@"
        build_wired_rommana "$@"
        build_diamond "$@"
        build_wired_diamond "$@"
        build_choc_diamond "$@"
        build_zen "$@"
        build_zen_dongle "$@"
        build_dilemma "$@"
        build_dilemma_right "$@"
        ;;
    rommana|s)
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
    zen_dongle|zd)
        build_zen_dongle "$@"
        ;;
    zen|z)
        build_zen "$@"
        ;;
    dilemma|m)
        build_dilemma "$@"
        ;;
    dilemma_right|mr)
        build_dilemma_right "$@"
        ;;
    *)
        echo "Unknown Keyboard: '$KEYBOARD'"
        exit 1
        ;;
esac

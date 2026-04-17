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
    if [[ "$complete" == "true" ]]; then
        ./scripts/build.sh "mabroum/rommana" "pr" "$@"
        ./scripts/build.sh "mabroum/rommana" "pl" "$@"
        ./scripts/build.sh "mabroum/rommana" "cd" "$@"
    fi
}

build_wired_rommana() {
    echo "--- Building Wired Rommana ---"
    ./scripts/build.sh "mabroum/wired_rommana" "l" "LINUX" "-b" "xiao_rp2040//zmk" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/build.sh "mabroum/wired_rommana" "r" "LINUX" "-b" "xiao_rp2040//zmk" "$@"
    fi
}

build_diamond() {
    echo "--- Building Diamond ---"
    ./scripts/build.sh "rafaelromao/diamond" "cd" "LINUX" "-e" "dongle_display" "-m" "englmaxi/zmk-dongle-display" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/build.sh "rafaelromao/diamond" "pr" "LINUX" "$@"
        ./scripts/build.sh "rafaelromao/diamond" "pl" "LINUX" "$@"
        ./scripts/build.sh "rafaelromao/diamond" "cl" "LINUX" "$@"
    fi
}

build_wired_diamond() {
    echo "--- Building Wired Diamond ---"
    ./scripts/build.sh "rafaelromao/wired_diamond" "l" "LINUX" "-b" "xiao_rp2040//zmk" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/build.sh "rafaelromao/wired_diamond" "r" "LINUX" "-b" "xiao_rp2040//zmk" "$@"
    fi
}

build_choc_diamond() {
    echo "--- Building Choc Diamond ---"
    ./scripts/build.sh "rafaelromao/choc_diamond" "cl" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/build.sh "rafaelromao/choc_diamond" "pr" "$@"
        ./scripts/build.sh "rafaelromao/choc_diamond" "pl" "$@"
        ./scripts/build.sh "rafaelromao/choc_diamond" "cd" "LINUX" "-e" "dongle_display" "-m" "englmaxi/zmk-dongle-display" "$@"
    fi
}

build_zen() {
    echo "--- Building Corneish Zen ---"
    ./scripts/build.sh "lowprokb.ca/corneish-zen" "-b" "corneish_zen_left//zmk" "-o" "LINUX" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/build.sh "lowprokb.ca/corneish-zen" "-b" "corneish_zen_right//zmk" "-o" "LINUX" "$@"
        ./scripts/build.sh "lowprokb.ca/corneish-zen-with-dongle" "corneish_zen_dongle" "LINUX" "$@"
        ./scripts/build.sh "lowprokb.ca/corneish-zen-with-dongle" "corneish_zen_v2_left" "LINUX" "$@"
        ./scripts/build.sh "lowprokb.ca/corneish-zen-with-dongle" "corneish_zen_v2_right" "LINUX" "$@"
    fi
}

build_dilemma() {
    echo "--- Building Dilemma ---"
    ./scripts/build.sh "bastardkb/dilemma" "cl" "LINUX" "-e" "dongle_display" "-m" "englmaxi/zmk-dongle-display" "$@"
    if [[ "$complete" == "true" ]]; then
        ./scripts/build.sh "bastardkb/dilemma" "pr" "LINUX" "$@"
        ./scripts/build.sh "bastardkb/dilemma" "pl" "LINUX" "$@"
        ./scripts/build.sh "bastardkb/dilemma" "cd" "LINUX" "$@"
    fi
}

# --- Main Script ---

complete=false

if [[ -z "${1:-}" || "${1:-}" == "-h" || "${1:-}" == "--help" ]]; then
    echo "Usage: $(basename "$0") <keyboard> [-c|--complete] [build.sh options]"
    echo
    echo "This script builds the firmware for a given keyboard, calling the underlying"
    echo "build.sh script with the correct parameters."
    echo "Additional arguments are passed to the underlying build.sh script."
    echo
    echo "Available keyboards: all, rommana, wired_rommana, diamond, wired_diamond, choc_diamond, zen, dilemma"
    echo
    echo "Examples:"
    echo "  $(basename "$0") rommana"
    echo "  $(basename "$0") rommana -c"
    echo "  $(basename "$0") rommana -c -v"
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
    zen|z)
        build_zen "$@"
        ;;
    dilemma|m)
        build_dilemma "$@"
        ;;
    *)
        echo "Unknown Keyboard: '$KEYBOARD'"
        exit 1
        ;;
esac

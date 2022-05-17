#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export ZMK_HOME="$KEYBOARD_HOME/zmk-config-Corne-ish-Zen"

if [[ ! -d "$ZMK_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/LOWPROKB/zmk-config-Corne-ish-Zen
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

if [[ ! -d "$KEYBOARD_HOME/.github/workflows" ]]
then
    echo "Creating workflow symbolic link..."
    ln -s "$ZMK_HOME/.github/workflows" "$KEYBOARD_HOME/.github"
    echo "Removing default config..."
    rm -rf "$ZMK_HOME/config"
    echo "Creating config symbolic link..."
    ln -s "$KEYBOARD_HOME/src/zmk/config" "$ZMK_HOME/config"
fi
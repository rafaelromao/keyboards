#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
MJ64="keyboards/melgeek/mj64/keymaps"

if [[ ! -d "$QMK_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/qmk/qmk_firmware
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

if [[ ! -d "$QMK_HOME/$MJ64/clopes.le" ]]
then
    echo "Creating MJ64 symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$MJ64/clopes.le" "$QMK_HOME/$MJ64"
fi
echo "Checking out qmk v0.18.1..."
cd $QMK_HOME
git fetch
git checkout 0.18.1
cd ..
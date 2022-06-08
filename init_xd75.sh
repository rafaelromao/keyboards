#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
QMK_USER_SPACE="$QMK_HOME/users"

XD75="keyboards/xiudi/xd75/keymaps"

# Prepare QMK home

if [[ ! -d "$QMK_HOME" ]]
then
    echo "Add git QMK sub-module..."
    git submodule add -f https://github.com/qmk/qmk_firmware
fi

# Update sub-modules

echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

# Symlink QMK custom code

if [[ ! -d "$QMK_USER_SPACE/rafaelromao" ]]
then
    echo "Creating QMK userspace symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/users/rafaelromao" "$QMK_USER_SPACE"
fi

if [[ ! -d "$QMK_HOME/$XD75/rafaelromao" ]]
then
    echo "Creating XD75 symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$XD75/rafaelromao" "$QMK_HOME/$XD75"
fi

echo "Checking out qmk v0.17.0..."
cd $QMK_HOME
git checkout 0.17.0
cd ..
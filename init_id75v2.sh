#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
USER_SPACE="$QMK_HOME/users"
ID75="keyboards/idobao/id75/keymaps"

if [[ ! -d "$QMK_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/qmk/qmk_firmware
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

if [[ ! -d "$USER_SPACE/arturgoms" ]]
then
    echo "Creating userspace symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/users/arturgoms" "$USER_SPACE"
fi
if [[ ! -d "$QMK_HOME/$ID75/arturgoms" ]]
then
    echo "Creating ID75 symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$ID75/arturgoms" "$QMK_HOME/$ID75"
fi
echo "Checking out qmk v0.17.0..."
cd $QMK_HOME
git checkout 0.17.0
cd ..

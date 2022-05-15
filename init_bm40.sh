#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
USER_SPACE="$QMK_HOME/users"
BM40="keyboards/kprepublic/bm40hsrgb/keymaps"

if [[ ! -d "$QMK_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/qmk/qmk_firmware
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

if [[ ! -d "$USER_SPACE/rafaelromao" ]]
then
    echo "Creating userspace symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/users/rafaelromao" "$USER_SPACE"
fi
if [[ ! -d "$QMK_HOME/$BM40/rafaelromao" ]]
then
    echo "Creating BM40 symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$BM40/rafaelromao" "$QMK_HOME/$BM40"
fi
echo "Checking out qmk v0.15.4..."
cd $QMK_HOME
git checkout 0.15.4
cd ..
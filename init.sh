#!/bin/bash

KEYBOARD_HOME="$(pwd)"
QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
USER_SPACE="$QMK_HOME/users"
BM40="keyboards/kprepublic/bm40hsrgb/keymaps"
XD75="keyboards/xiudi/xd75/keymaps"

if [[ ! -d "$QMK_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/rafaelromao/qmk_firmware
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

if [[ ! -d "$USER_SPACE/rafaelromao" ]]
then
    echo "Creating userspace symbolic link..."
    ln -s "$KEYBOARD_HOME/qmk/users/rafaelromao" "$USER_SPACE"
fi
if [[ ! -d "$QMK_HOME/$BM40/rafaelromao" ]]
then
    echo "Creating BM40 symbolic link..."
    ln -s "$KEYBOARD_HOME/qmk/$BM40/rafaelromao" "$QMK_HOME/$BM40"
fi
if [[ ! -d "$QMK_HOME/$XD75/rafaelromao" ]]
then
    echo "Creating XD75 symbolic link..."
    ln -s "$KEYBOARD_HOME/qmk/$XD75/rafaelromao" "$QMK_HOME/$XD75"
fi
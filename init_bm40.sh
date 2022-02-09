#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
export KMONAD_HOME="$KEYBOARD_HOME/kmonad"
QMK_USER_SPACE="$QMK_HOME/users"
KMONAD_USER_SPACE="$KMONAD_HOME/keymap/user"

BM40="keyboards/kprepublic/bm40hsrgb/keymaps"

# Prepare QMK home

if [[ ! -d "$QMK_HOME" ]]
then
    echo "Add git QMK sub-module..."
    git submodule add -f https://github.com/qmk/qmk_firmware
fi

# Prepare KMONAD home

if [[ ! -d "$KMONAD_HOME" ]]
then
    echo "Add git KMONAD sub-module..."
    git submodule add -f https://github.com/kmonad/kmonad
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
if [[ ! -d "$QMK_HOME/$BM40/rafaelromao" ]]
then
    echo "Creating BM40 symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$BM40/rafaelromao" "$QMK_HOME/$BM40"
fi

echo "Checking out qmk v0.17.0..."
cd $QMK_HOME
git checkout 0.17.0
cd ..
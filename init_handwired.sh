#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
USER_SPACE="$QMK_HOME/users"
HANDWIRED="keyboards/handwired"

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
if [[ ! -d "$QMK_HOME/$HARDWIRED/rafaelromao" ]]
then
    echo "Creating Handwired symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$HANDWIRED/rafaelromao" "$QMK_HOME/$HANDWIRED"
fi
echo "Checking out qmk v0.18.15..."
cd $QMK_HOME
git fetch
git checkout 0.18.15
cd ..
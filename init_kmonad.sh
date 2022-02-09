#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export KMONAD_HOME="$KEYBOARD_HOME/kmonad"
KMONAD_USER_SPACE="$KMONAD_HOME/keymap/user"

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

# Symlink KMONAD custom code

if [[ ! -d "$KMONAD_USER_SPACE/rafaelromao" ]]
then
    echo "Creating KMONAD userspace symbolic link..."
    ln -s "$KEYBOARD_HOME/src/kmonad/keymap/user/rafaelromao" "$KMONAD_USER_SPACE"
fi
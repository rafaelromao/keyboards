#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export KMONAD_HOME="$KEYBOARD_HOME/kmonad"
KMONAD_USER_SPACE="$KMONAD_HOME/keymap/user"
export PATH=$PATH:"$KMONAD_HOME/.stack-work/install/x86_64-osx/f330fe7099647d32bfed19f5c6310f7213f09c37320656c17d5929e9db589014/8.10.4/bin"
KEYMAP="keymap/user/rafaelromao"

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
    ln -s "$KEYBOARD_HOME/src/kmonad/$KEYMAP" "$KMONAD_USER_SPACE"
fi

# Run KMonad
kmonad "$KMONAD_HOME/$KEYMAP/apple.kbd"
#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export KMONAD_HOME="$KEYBOARD_HOME/kmonad"
KMONAD_USER_SPACE="$KMONAD_HOME/keymap/user"
KMONAD_BIN="$KMONAD_HOME/.stack-work/install/x86_64-osx/f330fe7099647d32bfed19f5c6310f7213f09c37320656c17d5929e9db589014/8.10.4/bin"
KEYMAP="keymap/user/rafaelromao"

if [[ ! -d "$KMONAD_HOME" ]]
then
    echo "Add git KMONAD sub-module..."
    git submodule add -f https://github.com/kmonad/kmonad
    
    echo "Update git sub-modules..."
    git submodule sync --recursive
    git submodule update --init --recursive --progress
fi

if [[ ! -d "$KMONAD_USER_SPACE/rafaelromao" ]]
then
    echo "Creating KMONAD userspace symbolic link..."
    ln -s "$KEYBOARD_HOME/src/kmonad/$KEYMAP" "$KMONAD_USER_SPACE"
    ln -s "$KMONAD_BIN" "$KMONAD_HOME"
    echo "Installing Kernel Extension..."
    cd kmonad
    cd c_src/mac/Karabiner-VirtualHIDDevice
    make install
    cd ../../..
    echo "Building KMonad..."
    stack build --flag kmonad:kext --extra-include-dirs=c_src/mac/Karabiner-VirtualHIDDevice/dist/include
    cd ..
    echo "Configuring PATH..."
    case ":${PATH}:" in
		*":$KMONAD_HOME/bin:"*);;            #Directory already in PATH
		*) PATH="${PATH}:$KMONAD_HOME/bin";; #Append directory to PATH
	esac
    echo $PATH
fi

sudo kmonad "$KMONAD_HOME/$KEYMAP/apple.kbd"
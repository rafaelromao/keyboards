#!/bin/bash

KEYBOARD_HOME="$(pwd)"
ZMK_MODULE="modules/rafaelromao/zmk"
export ZMK_HOME="$KEYBOARD_HOME/$ZMK_MODULE"

INIT=false
if [[ ! -d "$ZMK_HOME/.west" ]]
then
    INIT=true
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/rafaelromao/zmk $ZMK_MODULE
fi

echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

if [[ "${INIT}" == "true" ]]
then
    echo "Initializing West..."
    cd $ZMK_HOME
    west init -l app/
    west update
    west zephyr-export
    cd $KEYBOARD_HOME
fi

echo "Exporting Zephyr Toolchain..."
cd $ZMK_HOME
unset ZEPHYR_TOOLCHAIN_VARIANT
unset GNUARMEMB_TOOLCHAIN_PATH
export ZEPHYR_SDK_INSTALL_DIR=~/zephyr-sdk-0.16.3
cd $KEYBOARD_HOME

alias build=./build.sh
alias draw=./draw.sh

python3 -m venv .venv
source .venv/bin/activate
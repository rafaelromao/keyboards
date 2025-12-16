#!/bin/bash

KEYBOARD_HOME="$(pwd)"
ZMK="${1:-zmkfirmware/zmk}"
REVISION="${2:-v0.3}"
SDK="${3:-~/zephyr-sdk-0.16.3}"
ZMK_MODULE="modules/$ZMK"
export ZMK_HOME="$KEYBOARD_HOME/$ZMK_MODULE"

echo "ZMK: $ZMK"
echo "ZMK_HOME: $ZMK_HOME"
echo "REVISION: $REVISION"
echo "SDK: $SDK"

INIT=false
if [[ ! -d "$ZMK_HOME/.west" ]]
then
    INIT=true
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/$ZMK $ZMK_MODULE
fi

echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress --remote

if [[ "${INIT}" == "true" ]]
then
    echo "Initializing West..."
    cd $ZMK_HOME
    git checkout $REVISION
    west init -l app/
    west update
    west zephyr-export
    cd $KEYBOARD_HOME
fi

echo "Exporting Zephyr Toolchain..."
cd $ZMK_HOME
git checkout $REVISION
unset ZEPHYR_TOOLCHAIN_VARIANT
unset GNUARMEMB_TOOLCHAIN_PATH
export ZEPHYR_SDK_INSTALL_DIR=$SDK
echo "ZEPHYR_SDK_INSTALL_DIR = $ZEPHYR_SDK_INSTALL_DIR"
cd $KEYBOARD_HOME

echo "Creating Aliases..."
alias build=./scripts/build.sh
alias draw=./scripts/draw.sh
alias b=./scripts/b.sh

echo "Configuring venv..."
python3 -m venv .venv
source .venv/bin/activate
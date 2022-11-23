#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export ZMK_HOME="$KEYBOARD_HOME/zmk"

INIT=false
if [[ ! -d "$ZMK_HOME" ]]
then
    INIT=true
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/LOWPROKB/zmk.git
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

echo "Checking out zmk..."
cd $ZMK_HOME
git fetch
git checkout corne-ish-zen-v2
cd ..

if $INIT
then
    echo "Initializing West..."
    cd $ZMK_HOME
    west init -l app/
    west update
    west zephyr-export
    cd ..
fi

echo "Exporting Zephyr Toolchain..."
cd $ZMK_HOME
export ZEPHYR_TOOLCHAIN_VARIANT=gnuarmemb
export GNUARMEMB_TOOLCHAIN_PATH=/Applications/ArmGNUToolchain/11.3.rel1/arm-none-eabi
cd ..

echo "Creating build aliases..."
alias build_zen_default="west build -p -s zmk/app -b corneish_zen_v2_left -- -DZMK_CONFIG=$ZMK_HOME/keyboards/zen/default/config"
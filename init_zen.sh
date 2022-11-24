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
build_left="west build -p -s zmk/app -b corneish_zen_v2_left -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/keyboards/zen/"
build_right="west build -p -s zmk/app -b corneish_zen_v2_right -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/keyboards/zen/"
archive_left="mkdir build/artifacts;[ -f build/zephyr/zmk.uf2 ];cp build/zephyr/zmk.uf2 build/artifacts/corneish_zen_v2_left-zmk.uf2"
archive_right="mkdir build/artifacts;[ -f build/zephyr/zmk.uf2 ];cp build/zephyr/zmk.uf2 build/artifacts/corneish_zen_v2_right-zmk.uf2"
alias build_zen_default="${build_left}default;${build_right}default;${archive_left};${archive_right}"
alias build_zen="${build_left}rafaelromao;${build_right}rafaelromao;${archive_left};${archive_right}"
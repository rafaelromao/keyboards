#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export ZMK_HOME="$KEYBOARD_HOME/zmk"

INIT=false
if [[ ! -d "$ZMK_HOME" ]]
then
    INIT=true
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/rafaelromao/zmk
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

echo "Checking out zmk..."
cd $ZMK_HOME
git fetch
git checkout 20230706/rafaelromao/main
git pull
cd ..

if [[ "${INIT}" == "true" ]]
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
unset ZEPHYR_TOOLCHAIN_VARIANT
unset GNUARMEMB_TOOLCHAIN_PATH
export ZEPHYR_SDK_INSTALL_DIR=~/zephyr-sdk-0.15.0
cd ..

echo "Creating build aliases..."
build_left="west build -s app -b corneish_zen_v2_left --build-dir build/left -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/keyboards/lowprokb.ca/corneish-zen/"
build_right="west build -s app -b corneish_zen_v2_right --build-dir build/right -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/keyboards/lowprokb.ca/corneish-zen/"
archive_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/left/zephyr/zmk.uf2 ] && mv build/left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/corneish_zen_v2_left-zmk.uf2"
archive_right="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/right/zephyr/zmk.uf2 ] && mv build/right/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/corneish_zen_v2_right-zmk.uf2"
alias build_zen="cd zmk && ${build_left} && ${archive_left} && ${build_right} && ${archive_right} && cd .."

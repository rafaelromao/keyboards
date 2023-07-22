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

echo "Creating Zen build alias..."
build_zen_left="west build -s app -b corneish_zen_v2_left --build-dir build/corneish_zen_left -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/config/boards/shields/lowprokb.ca/corneish-zen"
build_zen_right="west build -s app -b corneish_zen_v2_right --build-dir build/corneish_zen_right -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/config/boards/shields/lowprokb.ca/corneish-zen"
archive_zen_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/corneish_zen_left/zephyr/zmk.uf2 ] && mv build/corneish_zen_left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/corneish_zen_v2_left-zmk.uf2"
archive_zen_right="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/corneish_zen_right/zephyr/zmk.uf2 ] && mv build/corneish_zen_right/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/corneish_zen_v2_right-zmk.uf2"
alias build_zen="cd zmk && ${build_zen_left} && ${archive_zen_left} && ${build_zen_right} && ${archive_zen_right} && cd .."

echo "Creating Hummingbird build alias..."
build_hummingbird_unibody="west build --pristine -s app -b xiao_ble --build-dir build/hummingbird -- -DSHIELD=hummingbird -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/config/boards/shields/handwired/hummingbird"
archive_hummingbird_unibody="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/hummingbird/zephyr/zmk.uf2 ] && mv build/hummingbird/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/hummingbird-zmk.uf2"
alias build_hummingbird="cd zmk && ${build_hummingbird_unibody} && ${archive_hummingbird_unibody} && cd .."

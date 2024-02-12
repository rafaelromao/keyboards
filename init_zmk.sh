#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export ZMK_HOME="$KEYBOARD_HOME/modules/rafaelromao/zmk"

INIT=false
if [[ ! -d "$ZMK_HOME" ]]
then
    INIT=true
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/rafaelromao/zmk modules/rafaelromao/zmk
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

echo "Checking out zmk..."
cd $ZMK_HOME
git fetch
git checkout 20240122/rafaelromao/main
git pull
cd $KEYBOARD_HOME

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
export ZEPHYR_SDK_INSTALL_DIR=~/zephyr-sdk-0.15.0
cd $KEYBOARD_HOME

echo "Creating Zen build alias..."
build_zen_left="west build -s app -b corneish_zen_v2_left --build-dir build/corneish_zen_left -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/config/boards/lowprokb.ca/corneish-zen"
build_zen_right="west build -s app -b corneish_zen_v2_right --build-dir build/corneish_zen_right -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/config/boards/lowprokb.ca/corneish-zen"
archive_zen_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/corneish_zen_left/zephyr/zmk.uf2 ] && mv build/corneish_zen_left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/corneish_zen_v2_left-zmk.uf2"
archive_zen_right="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/corneish_zen_right/zephyr/zmk.uf2 ] && mv build/corneish_zen_right/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/corneish_zen_v2_right-zmk.uf2"
alias build_zen_both_sides="cd ${ZMK_HOME} && ${build_zen_left} && ${archive_zen_left} && ${build_zen_right} && ${archive_zen_right} && cd ${KEYBOARD_HOME}"
alias build_zen="cd ${ZMK_HOME} && ${build_zen_left} && ${archive_zen_left} && cd ${KEYBOARD_HOME}"

echo "Creating Hummingbird build alias..."
build_hummingbird_unibody="west build --pristine -s app -b seeeduino_xiao_ble --build-dir build/hummingbird -- -DSHIELD='hw_hummingbird rgbled_widget' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/config/boards/handwired"
archive_hummingbird_unibody="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/hummingbird/zephyr/zmk.uf2 ] && mv build/hummingbird/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/hummingbird-zmk.uf2"
alias build_hummingbird="cd ${ZMK_HOME} && ${build_hummingbird_unibody} && ${archive_hummingbird_unibody} && cd $KEYBOARD_HOME"

echo "Creating Testpad build alias..."
build_testpad_unibody="west build --pristine -s app -b seeeduino_xiao_ble --build-dir build/testpad -- -DSHIELD='testpad' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/config/boards/handwired"
archive_testpad_unibody="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/testpad/zephyr/zmk.uf2 ] && mv build/testpad/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/testpad-zmk.uf2"
alias build_testpad="cd ${ZMK_HOME} && ${build_testpad_unibody} && ${archive_testpad_unibody} && cd $KEYBOARD_HOME"

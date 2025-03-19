#!/bin/bash

KEYBOARD_HOME="$(pwd)"
ZMK_MODULE="modules/rafaelromao/zmk"
RGBWIDGET_MODULE="modules/caksoylar/zmk-rgbled-widget"
DONGLE_DISPLAY_MODULE="modules/englmaxi/zmk-dongle-display"
AUTOLAYER_MODULE="modules/urob/zmk-auto-layer"
ANTECEDENT_MODULE="modules/ssbb/zmk-antecedent-morph"
export ZMK_HOME="$KEYBOARD_HOME/$ZMK_MODULE"
RGBWIDGET_HOME="$KEYBOARD_HOME/$RGBWIDGET_MODULE"
DONGLE_DISPLAY_HOME="$KEYBOARD_HOME/$DONGLE_DISPLAY_MODULE"
AUTOLAYER_HOME="$KEYBOARD_HOME/$AUTOLAYER_MODULE"
ANTECEDENT_HOME="$KEYBOARD_HOME/$ANTECEDENT_MODULE"

if [[ ! -d "$DONGLE_DISPLAY_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/englmaxi/zmk-dongle-display $DONGLE_DISPLAY_MODULE
fi

if [[ ! -d "$RGBWIDGET_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/caksoylar/zmk-rgbled-widget $RGBWIDGET_MODULE
fi

if [[ ! -d "$ANTECEDENT_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/ssbb/zmk-antecedent-morph $ANTECEDENT_MODULE
fi

if [[ ! -d "$AUTOLAYER_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/urob/zmk-auto-layer $AUTOLAYER_MODULE
fi

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
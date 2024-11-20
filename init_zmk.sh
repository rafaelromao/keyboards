#!/bin/bash

KEYBOARD_HOME="$(pwd)"
ZMK_MODULE="modules/rafaelromao/zmk"
RGBWIDGET_MODULE="modules/caksoylar/zmk-rgbled-widget"
DONGLE_MODULE="modules/englmaxi/zmk-dongle-display"
AUTOLAYER_MODULE="modules/urob/zmk-auto-layer"
ANTECEDENT_MODULE="modules/ssbb/zmk-antecedent-morph"
export ZMK_HOME="$KEYBOARD_HOME/$ZMK_MODULE"
RGBWIDGET_HOME="$KEYBOARD_HOME/$RGBWIDGET_MODULE"
DONGLE_HOME="$KEYBOARD_HOME/$DONGLE_MODULE"
AUTOLAYER_HOME="$KEYBOARD_HOME/$AUTOLAYER_MODULE"
ANTECEDENT_HOME="$KEYBOARD_HOME/$ANTECEDENT_MODULE"
BEHAVIOR_MODULES=""

if [[ ! -d "$DONGLE_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/englmaxi/zmk-dongle-display $DONGLE_MODULE
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

echo "Checking out zmk..."
cd $ZMK_HOME
git fetch
git checkout 20240328/rafaelromao/wired-split
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
export ZEPHYR_SDK_INSTALL_DIR=~/zephyr-sdk-0.16.3
cd $KEYBOARD_HOME

echo "Creating Testpad build alias..."
build_testpad_unibody="west build -s app -b seeeduino_xiao_ble --build-dir build/testpad -- -DSHIELD='testpad rgbled_adapter' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES=$RGBWIDGET_HOME"
archive_testpad_unibody="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/testpad/zephyr/zmk.uf2 ] && mv build/testpad/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/testpad-zmk.uf2"
alias build_testpad="cd ${ZMK_HOME} && ${build_testpad_unibody} && ${archive_testpad_unibody} && cd $KEYBOARD_HOME"

echo "Creating Reset build alias..."
build_reset_unibody="west build -s app -b nice_nano_v2 --build-dir build/reset -- -DSHIELD='settings_reset'"
archive_reset_unibody="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/reset/zephyr/zmk.uf2 ] && mv build/reset/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/reset-zmk.uf2"
alias build_reset="cd ${ZMK_HOME} && ${build_reset_unibody} && ${archive_reset_unibody} && cd $KEYBOARD_HOME"

echo "Creating Zen build alias..."
build_zen_left="west build -s app -b corneish_zen_v2_left --build-dir build/corneish_zen_left -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/lowprokb.ca/corneish-zen -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
build_zen_right="west build -s app -b corneish_zen_v2_right --build-dir build/corneish_zen_right -- -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/lowprokb.ca/corneish-zen -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
archive_zen_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/corneish_zen_left/zephyr/zmk.uf2 ] && mv build/corneish_zen_left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/corneish_zen_v2_left-zmk.uf2"
archive_zen_right="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/corneish_zen_right/zephyr/zmk.uf2 ] && mv build/corneish_zen_right/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/corneish_zen_v2_right-zmk.uf2"
alias build_zen_all="cd ${ZMK_HOME} && ${build_zen_left} && ${archive_zen_left} && ${build_zen_right} && ${archive_zen_right} && cd ${KEYBOARD_HOME}"
alias build_zen="cd ${ZMK_HOME} && ${build_zen_left} && ${archive_zen_left} && cd ${KEYBOARD_HOME}"

echo "Creating Rommana build alias..."
build_rommana_unibody="west build -p -s app -b seeeduino_xiao_rp2040 --build-dir build/rommana -- -DSHIELD='rommana' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
archive_rommana_unibody="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/rommana/zephyr/zmk.uf2 ] && mv build/rommana/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/rommana-zmk.uf2"
alias build_rommana="cd ${ZMK_HOME} && ${build_rommana_unibody} && ${archive_rommana_unibody} && cd $KEYBOARD_HOME"

echo "Creating Cygnus build alias..."
build_cygnus_central_dongle="west build -s app -b nice_nano_v2 --build-dir build/cygnus_central_dongle -- -DSHIELD='cygnus_central_dongle dongle_display' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$DONGLE_HOME;$BEHAVIOR_MODULES'"
build_cygnus_central_left="west build -s app -b nice_nano_v2 --build-dir build/cygnus_central_left -- -DSHIELD='cygnus_central_left' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
build_cygnus_peripheral_left="west build -s app -b nice_nano_v2 --build-dir build/cygnus_peripheral_left -- -DSHIELD='cygnus_peripheral_left' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
build_cygnus_peripheral_right="west build -s app -b nice_nano_v2 --build-dir build/cygnus_peripheral_right -- -DSHIELD='cygnus_peripheral_right' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
archive_cygnus_central_dongle="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/cygnus_central_dongle/zephyr/zmk.uf2 ] && mv build/cygnus_central_dongle/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/cygnus_central_dongle-zmk.uf2"
archive_cygnus_central_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/cygnus_central_left/zephyr/zmk.uf2 ] && mv build/cygnus_central_left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/cygnus_central_left-zmk.uf2"
archive_cygnus_peripheral_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/cygnus_peripheral_left/zephyr/zmk.uf2 ] && mv build/cygnus_peripheral_left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/cygnus_peripheral_left-zmk.uf2"
archive_cygnus_peripheral_right="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/cygnus_peripheral_right/zephyr/zmk.uf2 ] && mv build/cygnus_peripheral_right/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/cygnus_peripheral_right-zmk.uf2"
alias build_cygnus_all="cd ${ZMK_HOME} && ${build_cygnus_central_left} && ${archive_cygnus_central_left} && ${build_cygnus_central_dongle} && ${archive_cygnus_central_dongle} && ${build_cygnus_peripheral_left} && ${archive_cygnus_peripheral_left} && ${build_cygnus_peripheral_right} && ${archive_cygnus_peripheral_right} && cd ${KEYBOARD_HOME}"
alias build_cygnus="cd ${ZMK_HOME} && ${build_cygnus_central_dongle} && ${archive_cygnus_central_dongle} && ${build_cygnus_central_left} && ${archive_cygnus_central_left} && cd $KEYBOARD_HOME"
#alias build_cygnus="cd ${ZMK_HOME} && ${build_cygnus_central_left} && ${archive_cygnus_central_left} && cd $KEYBOARD_HOME"

echo "Creating Diamond build alias..."
build_diamond_central_dongle="west build -s app -b nice_nano_v2 --build-dir build/diamond_central_dongle -- -DSHIELD='diamond_central_dongle dongle_display' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$DONGLE_HOME;$BEHAVIOR_MODULES'"
build_diamond_central_left="west build -s app -b nice_nano_v2 --build-dir build/diamond_central_left -- -DSHIELD='diamond_central_left' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
build_diamond_peripheral_left="west build -s app -b nice_nano_v2 --build-dir build/diamond_peripheral_left -- -DSHIELD='diamond_peripheral_left' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
build_diamond_peripheral_right="west build -s app -b nice_nano_v2 --build-dir build/diamond_peripheral_right -- -DSHIELD='diamond_peripheral_right' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
archive_diamond_central_dongle="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/diamond_central_dongle/zephyr/zmk.uf2 ] && mv build/diamond_central_dongle/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/diamond_central_dongle-zmk.uf2"
archive_diamond_central_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/diamond_central_left/zephyr/zmk.uf2 ] && mv build/diamond_central_left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/diamond_central_left-zmk.uf2"
archive_diamond_peripheral_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/diamond_peripheral_left/zephyr/zmk.uf2 ] && mv build/diamond_peripheral_left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/diamond_peripheral_left-zmk.uf2"
archive_diamond_peripheral_right="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/diamond_peripheral_right/zephyr/zmk.uf2 ] && mv build/diamond_peripheral_right/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/diamond_peripheral_right-zmk.uf2"
alias build_diamond_all="cd ${ZMK_HOME} && ${build_diamond_central_left} && ${archive_diamond_central_left} && ${build_diamond_central_dongle} && ${archive_diamond_central_dongle} && ${build_diamond_peripheral_left} && ${archive_diamond_peripheral_left} && ${build_diamond_peripheral_right} && ${archive_diamond_peripheral_right} && cd ${KEYBOARD_HOME}"
alias build_diamond="cd ${ZMK_HOME} && ${build_diamond_central_left} && ${archive_diamond_central_left} && cd $KEYBOARD_HOME"
#alias build_diamond="cd ${ZMK_HOME} && ${build_diamond_central_left} && ${archive_diamond_central_left} && cd $KEYBOARD_HOME"

echo "Creating Wired Diamond build alias..."
build_wired_diamond_left="west build -p -s app -b seeeduino_xiao_rp2040 --build-dir build/wired_diamond_left -- -DSHIELD='wired_diamond_left' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
build_wired_diamond_right="west build -p -s app -b seeeduino_xiao_rp2040 --build-dir build/wired_diamond_right -- -DSHIELD='wired_diamond_right' -DZMK_CONFIG=$KEYBOARD_HOME/src/zmk/boards/handwired -DZMK_EXTRA_MODULES='$BEHAVIOR_MODULES'"
archive_wired_diamond_left="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/wired_diamond_left/zephyr/zmk.uf2 ] && mv build/wired_diamond_left/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/wired_diamond_left-zmk.uf2"
archive_wired_diamond_right="mkdir -p $KEYBOARD_HOME/build/artifacts; [ -f build/wired_diamond_right/zephyr/zmk.uf2 ] && mv build/wired_diamond_right/zephyr/zmk.uf2 $KEYBOARD_HOME/build/artifacts/wired_diamond_right-zmk.uf2"
alias build_wired_diamond_all="cd ${ZMK_HOME} && ${build_wired_diamond_left} && ${archive_wired_diamond_left} && ${build_wired_diamond_right} && ${archive_wired_diamond_right} && cd ${KEYBOARD_HOME}"
alias build_wired_diamond="cd ${ZMK_HOME} && ${build_wired_diamond_left} && ${archive_wired_diamond_left} && cd $KEYBOARD_HOME"

echo "Creating Keymap Drawer alias..."
prepare_tmp="mkdir -p ./tmp ; mkdir -p ./tmp"
prepare_no_separate_combos="\cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-noseparatecombos.yaml"
prepare_only_separate_combos="\cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-onlyseparatecombos.yaml"
prepare_only_vim_combos="\cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-onlyvimcombos.yaml"
write_no_separate_combos="yq -i 'del(.combos[] | select(.draw_separate == true))' ./tmp/keymap-drawer-noseparatecombos.yaml"
write_only_separate_combos="yq -i 'del(.combos[] | select(.draw_separate != true))' ./tmp/keymap-drawer-onlyseparatecombos.yaml"
write_only_vim_combos="yq -i 'del(.combos[] | select(.k.s != \"vim\"))' ./tmp/keymap-drawer-onlyvimcombos.yaml"
draw_overview="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -o ./tmp/overview.svg ./docs/keymap-drawer/keymap-drawer.yaml"
draw_separate_combos="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s alpha1 --combos-only -o ./tmp/separatecombos.svg ./tmp/keymap-drawer-onlyseparatecombos.yaml"
draw_alphas="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s alpha1 alpha2 ç-extension -o ./tmp/alphas.svg ./tmp/keymap-drawer-noseparatecombos.yaml"
draw_shifted="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s shifted1 shifted2 -o ./tmp/shifted.svg ./tmp/keymap-drawer-noseparatecombos.yaml"
draw_symbols="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s lower raise -o ./tmp/symbols.svg ./tmp/keymap-drawer-noseparatecombos.yaml"
draw_functions="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s functions smartcases -o ./tmp/functions.svg ./tmp/keymap-drawer-noseparatecombos.yaml"
draw_shortcuts="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s shortcuts custom -o ./tmp/shortcuts.svg ./tmp/keymap-drawer-noseparatecombos.yaml"
draw_navigation="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s nav media -o ./tmp/navigation.svg ./tmp/keymap-drawer-noseparatecombos.yaml"
draw_vim="keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s alpha1_vim_bindings lower media -o ./tmp/vim.svg ./tmp/keymap-drawer-onlyvimcombos.yaml"
convert_overview="inkscape --export-type png --export-filename ./img/overview.png --export-dpi 300 --export-background=white ./tmp/overview.svg"
convert_separate_combos="inkscape --export-type png --export-filename ./img/separatecombos.png --export-dpi 300 --export-background=white ./tmp/separatecombos.svg"
convert_alphas="inkscape --export-type png --export-filename ./img/alphas.png --export-dpi 300 --export-background=white ./tmp/alphas.svg"
convert_shifted="inkscape --export-type png --export-filename ./img/shifted.png --export-dpi 300 --export-background=white ./tmp/shifted.svg"
convert_symbols="inkscape --export-type png --export-filename ./img/symbols.png --export-dpi 300 --export-background=white ./tmp/symbols.svg"
convert_functions="inkscape --export-type png --export-filename ./img/functions.png --export-dpi 300 --export-background=white ./tmp/functions.svg"
convert_shortcuts="inkscape --export-type png --export-filename ./img/shortcuts.png --export-dpi 300 --export-background=white ./tmp/shortcuts.svg"
convert_navigation="inkscape --export-type png --export-filename ./img/navigation.png --export-dpi 300 --export-background=white ./tmp/navigation.svg"
convert_vim="inkscape --export-type png --export-filename ./img/vim.png --export-dpi 300 --export-background=white ./tmp/vim.svg"
prepare="\
${prepare_tmp} ; 
${prepare_no_separate_combos} ; ${prepare_only_separate_combos} ; ${prepare_only_vim_combos} ; \
${write_no_separate_combos} ; ${write_only_separate_combos} ; ${write_only_vim_combos}\
"
draw="\
${draw_overview} ; ${draw_separate_combos} ; ${draw_alphas} ; ${draw_shifted} ; \
${draw_symbols} ; ${draw_functions} ; ${draw_shortcuts} ;  ${draw_navigation} ; ${draw_vim}\
"
convert="\
${convert_overview} ; ${convert_separate_combos} ; ${convert_alphas} ; ${convert_shifted} ; \
${convert_symbols} ; ${convert_functions} ; ${convert_shortcuts} ;  ${convert_navigation} ; ${convert_vim} \
"
alias build_diagram="${prepare} ; ${draw} ; ${convert}"
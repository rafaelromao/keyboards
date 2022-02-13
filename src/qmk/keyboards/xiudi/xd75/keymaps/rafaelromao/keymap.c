/* Copyright 2021 Rafael Romão @rafaelromao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "rafaelromao.h"

#define LAYOUT_wrapper(...) LAYOUT_ortho_5x15(__VA_ARGS__)

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_ROMAK] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ROMAK_L1____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________ROMAK_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ROMAK_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________ROMAK_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ROMAK_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________ROMAK_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____ROMAK_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____ROMAK_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|

     [_QWERTY] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L1___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________QWERTY_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L2___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________QWERTY_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L3___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________QWERTY_R3___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____QWERTY_L4____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____QWERTY_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|

     [_LOWER] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L1____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________LOWER_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________LOWER_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________LOWER_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____LOWER_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____LOWER_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|

     [_RAISE] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L1____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________RAISE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________RAISE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________RAISE_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____RAISE_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____RAISE_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|

     [_NAVIGATION] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L1_______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L3_______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R3_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __NAVIGATION_L4__ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , __NAVIGATION_R4__ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|

     [_MOUSE] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MOUSE_L1____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MOUSE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MOUSE_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MOUSE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MOUSE_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MOUSE_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____MOUSE_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____MOUSE_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_FUNCTIONS] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________FUNCTIONS_L1________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R1________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________FUNCTIONS_L2________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R2________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________FUNCTIONS_L3________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R3________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____FUNCTIONS_L4_ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____FUNCTIONS_R4_ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|

     [_MEDIA] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |_______________________________________________________________________________________________________________________|
      ___________________MEDIA_L1____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MEDIA_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MEDIA_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MEDIA_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____MEDIA_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____MEDIA_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|

     [_MAINTENANCE] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L1______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L2______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L3______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R3______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __MAINTENANCE_L4_ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , __MAINTENANCE_R4_ , XXXXXXX , XXXXXXX , XXXXXXX)
 // |_____________________________________________________________________________________________________________________________________________________|
};

// RGB Indicators

extern leader_t leader;

void set_rgblight_by_layer(uint32_t layer) {
    switch (layer) {
        case _ROMAK:
        case _QWERTY:
            rgblight_setrgb(RGB_BLUE);
            break;
        case _LOWER:
        case _RAISE:
        case _FUNCTIONS:
        case _NAVIGATION:
        case _MOUSE:
        case _MEDIA:
            rgblight_setrgb(RGB_TURQUOISE);
            break;
        case _MAINTENANCE:
            rgblight_setrgb(RGB_RED);
            break;
        default:
            break;
    }
}

void set_current_layer_rgb(void) {
    set_rgblight_by_layer(get_highest_layer(layer_state|default_layer_state));
}

uint32_t layer_state_set_user(uint32_t state) {
    set_rgblight_by_layer(biton32(state));
    return state;
}

void set_mod_indicators(void) {
    uint8_t mods = get_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();

    bool isShift = mods & MOD_MASK_SHIFT || oneshot_mods & MOD_MASK_SHIFT || oneshot_locked_mods & MOD_MASK_SHIFT;
    bool isCtrl = mods & MOD_MASK_CTRL || oneshot_mods & MOD_MASK_CTRL || oneshot_locked_mods & MOD_MASK_CTRL;
    bool isAlt = mods & MOD_MASK_ALT || oneshot_mods & MOD_MASK_ALT || oneshot_locked_mods & MOD_MASK_ALT;
    bool isGui = mods & MOD_MASK_GUI || oneshot_mods & MOD_MASK_GUI || oneshot_locked_mods & MOD_MASK_GUI;

    bool isCapsLocked = host_keyboard_led_state().caps_lock;

    if (leader.isLeading) {
        rgblight_setrgb(RGB_GREEN);
    } else if (isCapsLocked) {
        rgblight_setrgb(RGB_YELLOW);
    } else if (isShift) {
        rgblight_setrgb(RGB_TURQUOISE);
    } else if (isCtrl || isAlt || isGui) {
        rgblight_setrgb(RGB_WHITE);
    } else {
        set_current_layer_rgb();
    }
}

void matrix_scan_keymap(void) {
    set_mod_indicators();
}
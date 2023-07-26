#include QMK_KEYBOARD_H

#include "rafaelromao.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x5(__VA_ARGS__)

// clang-format off

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_ROMAK] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________ROMAK_L1__________           ,           _________ROMAK_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ROMAK_L2____________________ , ___________________ROMAK_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________ROMAK_L3____________________ , ___________________ROMAK_R3__________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ____ROMAK_L4_____ , ____ROMAK_R4_____),
 // |___________________________________________________________________________________________________|

     [_NUMPAD] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________NUMPAD_L1_________           ,           _________NUMPAD_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NUMPAD_L2___________________ , ___________________NUMPAD_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________NUMPAD_L3___________________ , ___________________NUMPAD_R3_________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ____NUMPAD_L4____ , ____NUMPAD_R4____),
 // |___________________________________________________________________________________________________|

     [_MACROS] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________MACROS_L1_________           ,           _________MACROS_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MACROS_L2___________________ , ___________________MACROS_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________MACROS_L3___________________ , ___________________MACROS_R3_________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____MACROS_L4____ , ____MACROS_R4____),
 // |___________________________________________________________________________________________________|

     [_NOMOD] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________NOMOD_L1__________           ,           _________NOMOD_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NOMOD_L2____________________ , ___________________NOMOD_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________NOMOD_L3____________________ , ___________________NOMOD_R3__________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ____NOMOD_L4_____ , ____NOMOD_R4_____),
 // |___________________________________________________________________________________________________|

     [_ACCENT] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________ACCENT_L1_________           ,           _________ACCENT_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ACCENT_L2___________________ , ___________________ACCENT_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________ACCENT_L3___________________ , ___________________ACCENT_R3_________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ____ACCENT_L4____ , ____ACCENT_R4____),
 // |___________________________________________________________________________________________________|

     [_FIXED_ACCENT] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________ACCENT_L1_________           ,           _________ACCENT_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ACCENT_L2___________________ , ___________________ACCENT_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________ACCENT_L3___________________ , ___________________ACCENT_R3_________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ____ACCENT_L4____ , ____ACCENT_R4____),
 // |___________________________________________________________________________________________________|

     [_LOWER] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________LOWER_L1__________           ,           _________LOWER_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L2____________________ , ___________________LOWER_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________LOWER_L3____________________ , ___________________LOWER_R3__________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ____LOWER_L4_____ , ____LOWER_R4_____),
 // |___________________________________________________________________________________________________|

     [_RAISE] = LAYOUT_wrapper(
 // |_______________________________ ____________________________________________________________________|
      ___________________RAISE_L1__________           ,           _________RAISE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L2____________________ , ___________________RAISE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________RAISE_L3____________________ , ___________________RAISE_R3__________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ____RAISE_L4_____ , ____RAISE_R4_____),
 // |___________________________________________________________________________________________________|

     [_FIXED_NAV] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_____           ,           _________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________NAVIGATION_L3_______________ , ___________________NAVIGATION_R3_____ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    __NAVIGATION_L4__ , __FIXED_NAV__R4__),
 // |___________________________________________________________________________________________________|

     [_MEDIA] = LAYOUT_wrapper(
 // |_______________________________ ____________________________________________________________________|
      ___________________MEDIA_L1__________           ,           _________MEDIA_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L2____________________ , ___________________MEDIA_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________MEDIA_L3____________________ , ___________________MEDIA_R3__________           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ____MEDIA_L4_____ , ____MEDIA_R4_____),
 // |___________________________________________________________________________________________________|

     [_NAVIGATION] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_____           ,           _________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________NAVIGATION_L3_______________ , ___________________NAVIGATION_R3_____           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    __NAVIGATION_L4__ , __NAVIGATION_R4__),
 // |___________________________________________________________________________________________________|

     [_LOCK] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      _______________________LOCK____L1____           ,           _____________LOCK____R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______________________LOCK____L2______________ , _______________________LOCK____R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _____________LOCK____L3______________ , _______________________LOCK____R3____           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    ______LOCK____L4_ , ______LOCK____R4_),
 // |___________________________________________________________________________________________________|

     [_MAINTENANCE] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________MAINTENANCE_L1____           ,           _________MAINTENANCE_R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L2______________ , ___________________MAINTENANCE_R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                _________MAINTENANCE_L3______________ , ___________________MAINTENANCE_R3____           ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                                    __MAINTENANCE_L4_ ,  __MAINTENANCE_R4_)
 // |___________________________________________________________________________________________________|
};

// clang-format on

// RGB Indicators

extern leader_t      leader;
extern select_word_t select_word;
extern dyn_macro_t   dyn_macro;
extern swapper_t     swapper;
static bool          is_suspended;

void suspend_wakeup_init_kb(void) {
    is_suspended = false;
}

void suspend_power_down_kb(void) {
    is_suspended = true;
}

void set_rgblight_by_layer(uint32_t layer) {
    if (is_suspended) {
        return;
    }
    switch (layer) {
        case _ROMAK:
        case _MAINTENANCE:
            rgblight_reload_from_eeprom();
            break;
        case _LOCK:
            rgblight_setrgb(RGB_OFF);
            break;
        case _NUMPAD:
            rgblight_setrgb(RGB_PURPLE);
            break;
        default:
            rgblight_setrgb(RGB_SPRINGGREEN);
            break;
    }
}

void set_current_layer_rgb(void) {
    set_rgblight_by_layer(get_highest_layer(layer_state | default_layer_state));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_rgblight_by_layer(biton32(state));
    return state;
}

void set_mod_indicators(void) {
    uint8_t mods                = get_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();

    bool isShift = mods & MOD_MASK_SHIFT || oneshot_mods & MOD_MASK_SHIFT || oneshot_locked_mods & MOD_MASK_SHIFT;
    bool isCtrl  = mods & MOD_MASK_CTRL || oneshot_mods & MOD_MASK_CTRL || oneshot_locked_mods & MOD_MASK_CTRL;
    bool isAlt   = mods & MOD_MASK_ALT || oneshot_mods & MOD_MASK_ALT || oneshot_locked_mods & MOD_MASK_ALT;
    bool isGui   = mods & MOD_MASK_GUI || oneshot_mods & MOD_MASK_GUI || oneshot_locked_mods & MOD_MASK_GUI;

    if (swapper.state != NONE || leader.isLeading || select_word.state != STATE_NONE || dyn_macro.recording != 0) {
        rgblight_setrgb(RGB_GREEN);
    } else if (has_any_smart_case()) {
        rgblight_setrgb(RGB_YELLOW);
    } else if (isShift) {
        rgblight_setrgb(RGB_TEAL);
    } else if (isCtrl || isAlt || isGui) {
        rgblight_setrgb(RGB_WHITE);
    } else {
        set_current_layer_rgb();
    }
}

void matrix_scan_keymap(void) {
    set_mod_indicators();
}

void keyboard_post_init_kb(void) {
    setPinOutput(RGB_POWER_PIN);
    writePinHigh(RGB_POWER_PIN);
    rgblight_enable_noeeprom();
}
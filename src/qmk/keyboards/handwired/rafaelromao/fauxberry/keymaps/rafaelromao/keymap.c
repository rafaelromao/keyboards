#include QMK_KEYBOARD_H

#include "rafaelromao.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

// clang-format off

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_ALPHA1] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      __________________ALPHA1_L1__________ , KC_K    , KC_X    , ________ALPHA1_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      __________________ALPHA1_L2____________________ , __________________ALPHA1_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Q    , ________ALPHA1_L3____________________ , __________________ALPHA1_R3__________ , KC_Y    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ___ALPHA1_L4_____ , HYPR_L  , HYPR_R  , ___ALPHA1_R4_____),
 // |___________________________________________________________________________________________________|

     [_NUMPAD] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________NUMPAD_L1_________ , XXXXXXX , XXXXXXX , _________NUMPAD_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NUMPAD_L2___________________ , ___________________NUMPAD_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NUMPAD_L3___________________ , ___________________NUMPAD_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____NUMPAD_L4____ , XXXXXXX , XXXXXXX , ____NUMPAD_R4____),
 // |___________________________________________________________________________________________________|

     [_SHORTCUTS] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ________________SHORTCUTS_L1_________ , XXXXXXX , XXXXXXX , ______SHORTCUTS_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ________________SHORTCUTS_L2___________________ , ________________SHORTCUTS_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , ______SHORTCUTS_L3___________________ , ________________SHORTCUTS_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          _SHORTCUTS_L4____ , XXXXXXX , XXXXXXX , _SHORTCUTS_R4____),
 // |___________________________________________________________________________________________________|

     [_NOMOD] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________NOMOD_L1__________ , KC_K    , KC_X    , _________NOMOD_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NOMOD_L2____________________ , ___________________NOMOD_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Q    , _________NOMOD_L3____________________ , ___________________NOMOD_R3__________ , KC_Y    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____NOMOD_L4_____ , HYPR_L  , HYPR_R  , ____NOMOD_R4_____),
 // |___________________________________________________________________________________________________|

     [_ALPHA2] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________ALPHA2_L1_________ , XXXXXXX , XXXXXXX , _________ALPHA2_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ALPHA2_L2___________________ , ___________________ALPHA2_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________ALPHA2_L3___________________ , ___________________ALPHA2_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____ALPHA2_L4____ , XXXXXXX , XXXXXXX , ____ALPHA2_R4____),
 // |___________________________________________________________________________________________________|

     [_FIXED_ALPHA2] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________ALPHA2_L1_________ , XXXXXXX , XXXXXXX , _________ALPHA2_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ALPHA2_L2___________________ , ___________________ALPHA2_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________ALPHA2_L3___________________ , ___________________ALPHA2_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____ALPHA2_L4____ , XXXXXXX , XXXXXXX , ____ALPHA2_R4____),
 // |___________________________________________________________________________________________________|

     [_SYMBOLS] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      _________________SYMBOLS_L1__________ , XXXXXXX , XXXXXXX , _______SYMBOLS_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _________________SYMBOLS_L2____________________ , _________________SYMBOLS_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _______SYMBOLS_L3____________________ , _________________SYMBOLS_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          __SYMBOLS_L4_____ , XXXXXXX , XXXXXXX , __SYMBOLS_R4_____),
 // |___________________________________________________________________________________________________|

     [_LOWER] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________LOWER_L1__________ , XXXXXXX , XXXXXXX , _________LOWER_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L2____________________ , ___________________LOWER_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________LOWER_L3____________________ , ___________________LOWER_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____LOWER_L4_____ , XXXXXXX , XXXXXXX , ____LOWER_R4_____),
 // |___________________________________________________________________________________________________|

     [_RAISE] = LAYOUT_wrapper(
 // |_______________________________ ____________________________________________________________________|
      ___________________RAISE_L1__________ , XXXXXXX , XXXXXXX , _________RAISE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L2____________________ , ___________________RAISE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________RAISE_L3____________________ , ___________________RAISE_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____RAISE_L4_____ , XXXXXXX , XXXXXXX , ____RAISE_R4_____),
 // |___________________________________________________________________________________________________|

     [_FIXED_NAV] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_____ , XXXXXXX , XXXXXXX , _________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NAVIGATION_L3_______________ , ___________________NAVIGATION_R3_____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          __NAVIGATION_L4__ , XXXXXXX , XXXXXXX , __FIXED_NAV__R4__),
 // |___________________________________________________________________________________________________|

     [_MEDIA] = LAYOUT_wrapper(
 // |_______________________________ ____________________________________________________________________|
      ___________________MEDIA_L1__________ , XXXXXXX , XXXXXXX , _________MEDIA_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L2____________________ , ___________________MEDIA_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________MEDIA_L3____________________ , ___________________MEDIA_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____MEDIA_L4_____ , XXXXXXX , XXXXXXX , ____MEDIA_R4_____),
 // |___________________________________________________________________________________________________|

     [_NAVIGATION] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_____ , XXXXXXX , XXXXXXX , _________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NAVIGATION_L3_______________ , ___________________NAVIGATION_R3_____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          __NAVIGATION_L4__ , XXXXXXX , XXXXXXX , __NAVIGATION_R4__),
 // |___________________________________________________________________________________________________|

     [_LOCK] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      _______________________LOCK____L1____ , XXXXXXX , XXXXXXX , _____________LOCK____R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______________________LOCK____L2______________ , _______________________LOCK____R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _____________LOCK____L3______________ , _______________________LOCK____R3____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ______LOCK____L4_ , XXXXXXX , XXXXXXX , ______LOCK____R4_),
 // |___________________________________________________________________________________________________|

     [_SYSTEM] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ______________________SYSTEM___L1____ , XXXXXXX , XXXXXXX , ____________SYSTEM___R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ______________________SYSTEM___L2______________ , ______________________SYSTEM___R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , ____________SYSTEM___L3______________ , ______________________SYSTEM___R3____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          _____SYSTEM___L4_ , XXXXXXX , XXXXXXX , _____SYSTEM___R4_)
 // |___________________________________________________________________________________________________|
};

// clang-format on

extern leader_t      leader;
extern select_word_t select_word;
extern dyn_macro_t   dyn_macro;
extern swapper_t     swapper;
static bool          is_suspended;

// RGB Indicators

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
        case _ALPHA1:
        case _SYSTEM:
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
    uint16_t layer = get_highest_layer(layer_state | default_layer_state);
    set_rgblight_by_layer(layer);
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

layer_state_t layer_state_set_user(layer_state_t state) {
    uint16_t layer = biton32(state);
    set_rgblight_by_layer(layer);
    return state;
}

// Encoder Map

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_ALPHA1]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_NUMPAD]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_ALPHA2]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_SHORTCUTS]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_SYMBOLS]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_LOWER]      = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_RAISE]      = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_FIXED_NAV]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_NAVIGATION] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_MEDIA]      = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_LOCK]       = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))},
    [_SYSTEM]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN))}};

// Oled

void clear_oled(void) {
    oled_write("                ", false);
}

void set_oled_by_layer(uint32_t layer) {
    if (is_suspended) {
        oled_set_cursor(0, 0);
        clear_oled();
        return;
    }
    switch (layer) {
        case _ALPHA1:
        case _NOMOD:
            oled_write("        ROMAK     ", false);
            break;
        case _NUMPAD:
            oled_write("        NUMPAD    ", false);
            break;
        case _ALPHA2:
            oled_write("        ALPHA2    ", false);
            break;
        case _SHORTCUTS:
            oled_write("      SHORTCUTS   ", false);
            break;
        case _SYMBOLS:
            oled_write("      SYMBOLS     ", false);
            break;
        case _LOWER:
            oled_write("        LOWER     ", false);
            break;
        case _RAISE:
            oled_write("        RAISE     ", false);
            break;
        case _FIXED_NAV:
        case _NAVIGATION:
            oled_write("      NAVIGATION  ", false);
            break;
        case _MEDIA:
            oled_write("        MEDIA     ", false);
            break;
        case _SYSTEM:
            oled_write("       SYSTEM     ", false);
            break;
        default:
            break;
    }
}

void set_current_layer_oled(void) {
    uint16_t layer = get_highest_layer(layer_state | default_layer_state);
    set_oled_by_layer(layer);
}

void set_oled_text(void) {
    uint8_t mods                = get_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();

    bool isShift = mods & MOD_MASK_SHIFT || oneshot_mods & MOD_MASK_SHIFT || oneshot_locked_mods & MOD_MASK_SHIFT;
    bool isCtrl  = mods & MOD_MASK_CTRL || oneshot_mods & MOD_MASK_CTRL || oneshot_locked_mods & MOD_MASK_CTRL;
    bool isAlt   = mods & MOD_MASK_ALT || oneshot_mods & MOD_MASK_ALT || oneshot_locked_mods & MOD_MASK_ALT;
    bool isGui   = mods & MOD_MASK_GUI || oneshot_mods & MOD_MASK_GUI || oneshot_locked_mods & MOD_MASK_GUI;

    oled_set_cursor(0, 0);

    if (swapper.state != NONE || leader.isLeading || select_word.state != STATE_NONE || dyn_macro.recording != 0) {
        if (swapper.state != NONE) {
            oled_write("Swapper", false);
        } else if (leader.isLeading) {
            oled_write("Leader Key", false);
        } else if (select_word.state != STATE_NONE) {
            oled_write("Select Word / Line", false);
        } else if (dyn_macro.recording != 0) {
            oled_write("Dynamic Macro", false);
        }
    } else if (has_any_smart_case()) {
        oled_write("Smart Case", false);
    } else if (isShift || isCtrl || isAlt || isGui) {
        if (isShift) {
            oled_write("Shift ", false);
        }
        if (isCtrl) {
            oled_write("Ctrl ", false);
        }
        if (isGui) {
            if (is_macos()) {
                oled_write("Cmd ", false);
            } else {
                oled_write("Win ", false);
            }
        }
        if (isAlt) {
            oled_write("Alt ", false);
        }
    } else {
        set_current_layer_oled();
    }

    clear_oled();
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    set_oled_text();
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}
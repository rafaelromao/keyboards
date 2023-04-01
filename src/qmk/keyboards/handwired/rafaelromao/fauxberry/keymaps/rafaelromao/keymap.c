#include QMK_KEYBOARD_H

#include "rafaelromao.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

// clang-format off

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_ROMAK] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________ROMAK_L1__________ , XXXXXXX , XXXXXXX , _________ROMAK_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ROMAK_L2____________________ , ___________________ROMAK_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KCR_MAC , _________ROMAK_L3____________________ , ___________________ROMAK_R3__________ , KCI_MAC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____ROMAK_L4_____ , HYPR_L  , HYPR_H  , ____ROMAK_R4_____),
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

     [_ACCENT] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________ACCENT_L1_________ , XXXXXXX , XXXXXXX , _________ACCENT_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ACCENT_L2___________________ , ___________________ACCENT_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________ACCENT_L3___________________ , ___________________ACCENT_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____ACCENT_L4____ , XXXXXXX , XXXXXXX , ____ACCENT_R4____),
 // |___________________________________________________________________________________________________|

     [_FIXED_ACCENT] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________ACCENT_L1_________ , XXXXXXX , XXXXXXX , _________ACCENT_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ACCENT_L2___________________ , ___________________ACCENT_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________ACCENT_L3___________________ , ___________________ACCENT_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____ACCENT_L4____ , XXXXXXX , XXXXXXX , ____ACCENT_R4____),
 // |___________________________________________________________________________________________________|

     [_MACROS] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________MACROS_L1_________ , XXXXXXX , XXXXXXX , _________MACROS_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MACROS_L2___________________ , ___________________MACROS_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________MACROS_L3___________________ , ___________________MACROS_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          ____MACROS_L4____ , XXXXXXX , XXXXXXX , ____MACROS_R4____),
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

     [_MAINTENANCE] = LAYOUT_wrapper(
 // |___________________________________________________________________________________________________|
      ___________________MAINTENANCE_L1____ , XXXXXXX , XXXXXXX , _________MAINTENANCE_R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L2______________ , ___________________MAINTENANCE_R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________MAINTENANCE_L3______________ , ___________________MAINTENANCE_R3____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
                          __MAINTENANCE_L4_ , XXXXXXX , XXXXXXX , __MAINTENANCE_R4_)
 // |___________________________________________________________________________________________________|
};

// clang-format on

extern leader_t      leader;
extern select_word_t select_word;
extern dyn_macro_t   dyn_macro;
extern swapper_t     swapper;
extern os_t          os;
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
    [_ROMAK]       = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NUMPAD]      = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_ACCENT]      = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MACROS]      = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LOWER]       = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_RAISE]       = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FIXED_NAV]   = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAVIGATION]  = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MEDIA]       = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LOCK]        = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MAINTENANCE] = {ENCODER_CCW_CW(S(KC_PGUP), S(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}};

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
        case _ROMAK:
            oled_write("        ROMAK     ", false);
            break;
        case _NUMPAD:
            oled_write("        NUMPAD    ", false);
            break;
        case _ACCENT:
        case _FIXED_ACCENT:
            oled_write("        ACCENT    ", false);
            break;
        case _MACROS:
            oled_write("        MACROS    ", false);
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
        case _MAINTENANCE:
            oled_write("     MAINTENANCE  ", false);
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
        if (isGui) {
            if (os.type == MACOS) {
                oled_write("Cmd ", false);
            } else {
                oled_write("Win ", false);
            }
        }
        if (isAlt) {
            oled_write("Alt ", false);
        }
        if (isCtrl) {
            oled_write("Ctrl ", false);
        }
        if (isShift) {
            oled_write("Shift ", false);
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
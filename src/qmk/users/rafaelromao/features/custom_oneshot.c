#include QMK_KEYBOARD_H

#include "custom_oneshot.h"

extern os_t os;

static custom_oneshots_t custom_oneshots = {.timer = 0};
static uint16_t          repeat_key_timer = 0;

// Custom oneshot mods

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods) {
        custom_oneshots.timer = timer_read();
    } else {
        custom_oneshots.timer = 0;
    }
}

void clear_locked_and_oneshot_mods(void) {
    uint8_t oneshot_mods        = get_oneshot_mods();
    if (oneshot_mods) {
        clear_oneshot_mods();
        clear_oneshot_locked_mods();
        unregister_mods(MOD_LSFT);
        unregister_mods(MOD_LCTL);
        unregister_mods(MOD_LALT);
        unregister_mods(MOD_RALT);
        unregister_mods(MOD_LGUI);
    }
#ifdef DYNAMIC_MACRO_ENABLE
    dyn_macro_reset();
#endif
}

void clear_oneshot_mods_state(void) {
    uint8_t oneshot_mods        = get_oneshot_mods();
    if (!(oneshot_mods & MOD_LSFT)) {
        del_oneshot_mods(MOD_LSFT);
        unregister_mods(MOD_LSFT);
    }
    if (!(oneshot_mods & MOD_LCTL)) {
        del_oneshot_mods(MOD_LCTL);
        unregister_mods(MOD_LCTL);
    }
    if (!(oneshot_mods & MOD_LGUI)) {
        del_oneshot_mods(MOD_LGUI);
        unregister_mods(MOD_LGUI);
    }
    if (!(oneshot_mods & MOD_LALT)) {
        del_oneshot_mods(MOD_LALT);
        unregister_mods(MOD_LALT);
    }
    if (!(oneshot_mods & MOD_RALT)) {
        del_oneshot_mods(MOD_RALT);
        unregister_mods(MOD_RALT);
    }
}

void disable_oneshot_layer(void) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    custom_oneshots.timer = 0;
}

void disable_oneshot_mods(void) {
    clear_oneshot_mods_state();
    custom_oneshots.timer = 0;
}

bool check_disable_oneshot(uint16_t keycode) {
    switch (keycode) {
        case RAI_A2:
        case RAI_TA2:
        case ACT_SPC:
        case LOW_SPC:
        case MED_CAS:
        case NAV_CAS:
        case NAV_FCA:
        case OS_LSFT:
            return false;
        default:
            disable_oneshot_layer();
            return true;
    }
}

// Custom oneshot timeout

bool custom_oneshots_expired(void) {
    return custom_oneshots.timer > 0 && (timer_elapsed(custom_oneshots.timer) > ONESHOT_TIMEOUT);
}

void check_oneshot_timeout(void) {
    if (custom_oneshots_expired()) {
        disable_oneshot_mods();
        disable_oneshot_layer();
    }
}

// Custom oneshot keycodes

void reset_oneshot_timer(void) {
    custom_oneshots.timer = timer_read();
}

bool should_send_ctrl(bool isMacOS, bool isOneShotShift) {
    return (!isMacOS && !isOneShotShift) || (isMacOS && isOneShotShift);
}

// Custom Shift Repeat Magic Keys

bool repeat_key_expired(void) {
    return repeat_key_timer == 0 || (timer_elapsed(repeat_key_timer) > REPEAT_KEY_TIMEOUT);
}

void check_repeat_key_timeout(void) {
    if (repeat_key_expired()) {
        clear_repeat_key();
    }
}

void clear_repeat_key(void) {
    repeat_key_timer = 0;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case RAI_A2:
        case MED_CAS:
        case NAV_CAS:
        case NAV_FCA:
            return false;
    }
    repeat_key_timer = timer_read();
    return true;
}

bool in_mid_word(uint16_t key) {
    if (repeat_key_timer == 0) {
        // Used to signal that the last key to repeat/magic expired
        return false;
    }
    switch (key) {
        // Avoid repeat/magic after navigation
        case KC_LEFT:
        case KC_RIGHT:
        case KC_DOWN:
        case KC_UP:
        case KC_HOME:
        case KC_END:
        // Avoid repeat/magic for new sentences
        case KC_SPC:
        case KC_BSPC:
        case KC_TAB:
        case KC_ENT:
        case KC_ESC:
        // not necessary to repeat/magic, so skip to work better with remapped VIM bindings
        case KC_H:
        case KC_O:
        // avoid recursive calls
        case MED_CAS:
        case NAV_CAS:
        case NAV_FCA:
            return false;
    }
    return true;
}

void process_shift_repeat(uint16_t keycode) {
    uint16_t key = extract_tapping_keycode(keycode);
    if (in_mid_word(key)) {
        // repeat only simple tapping keycodes
        tap_code16(key);
    } else {
        add_oneshot_mods(MOD_LSFT);
    }
}

void process_shift_magic(uint16_t keycode) {
    uint16_t key = extract_tapping_keycode(keycode);
    if (in_mid_word(key)) {
        // magic for macros
        switch (keycode) {
            case MC_SQ_A:
            case MC_SQ_E:
            case MC_SQ_O:
            case MC_SQ_I:
            case MC_SQ_U:
                tap_code(KC_V);
                return;
        }
        // magic only simple tapping keycodes
        switch (key) {
            case KC_D:
                tap_code(KC_Y);
                break;
            case KC_N:
                tap_code(KC_D);
                break;
            case KC_S:
                tap_code(KC_M);
                break;
            case KC_X:
                tap_code(KC_C);
                break;
            case KC_A:
                tap_code(KC_O);
                break;
            case KC_U:
                tap_code(KC_E);
                break;
            case KC_E:
                tap_code(KC_I);
                break;
            case KC_T:
                tap_code(KC_W);
                break;
            case KC_K:
                tap_code(KC_W);
                break;
            case KC_L:
                tap_code(KC_R);
                break;
            case KC_R:
                tap_code(KC_H);
                break;
            case KC_J:
                process_accents(MC_SQ_A, NULL);
                break;
            case KC_I:
                tap_code(KC_BSPC);
                SEND_STRING("I' ");
                break;
            default:
                tap_code16(key);
        }
    } else {
        add_oneshot_mods(MOD_LSFT);
    }
}

void activate_shift_repeat_or_magic_key(uint16_t keycode) {
    switch (keycode) {
        case MED_CAS:
            process_shift_magic(get_last_keycode());
            break;
        case NAV_CAS:
        case NAV_FCA:
            process_shift_repeat(get_last_keycode());
            break;
    }
}

process_record_result_t process_custom_oneshot(uint16_t keycode, keyrecord_t *record) {
    if (keycode != OS_SYM && record->event.pressed && IS_LAYER_ON(_ALPHA2) && check_disable_oneshot(keycode)) {
        if (is_string_macro_keycode(keycode)) {
            if (process_accents(keycode, NULL) == PROCESS_RECORD_CONTINUE) {
                process_macros(keycode, NULL);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        } else {
            tap_code16(keycode);
            return PROCESS_RECORD_RETURN_FALSE;
        }
    }

    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isOneShotCtrl        = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt         = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui         = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShotButShift = isOneShotCtrl || isOneShotAlt || isOneShotGui;

    switch (keycode) {
        case OS_SYM:
            if (record->tap.count > 0) {
                disable_oneshot_layer();
                return PROCESS_RECORD_RETURN_TRUE;
            }
        case RAI_A2:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (get_mods() != 0) {
                        set_smart_case_for_mods();
                    } else {
                        reset_oneshot_timer();
                        return PROCESS_RECORD_RETURN_TRUE;
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            } else {
                if (record->event.pressed) {
                    layer_on(_RAISE);
                } else {
                    layer_off(_RAISE);
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
        case NAV_CAS:
        case NAV_FCA:
        case MED_CAS:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (has_any_smart_case()) {
                        disable_smart_case();
                        clear_shift();
                    } else {
                        if (isAnyOneShotButShift) {
                            clear_locked_and_oneshot_mods();
                        } else if (!isOneShotShift) {
                            activate_shift_repeat_or_magic_key(keycode);
                        } else {
                            set_smart_case_for_mods();
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}

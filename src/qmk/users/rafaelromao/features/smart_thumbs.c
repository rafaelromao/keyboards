#include QMK_KEYBOARD_H

#include "smart_thumbs.h"

extern os_t os;

static custom_oneshots_t custom_oneshots  = {.timer = 0};
static uint16_t          custom_repeat_key_timer = 0;

// Custom oneshot mods

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods) {
        custom_oneshots.timer = timer_read();
    } else {
        custom_oneshots.timer = 0;
    }
}

void clear_oneshot_shift(void) {
    uint8_t oneshot_mods = get_oneshot_mods();
    if (oneshot_mods) {
        clear_oneshot_mods();
        unregister_mods(MOD_LSFT);
    }
}

void clear_oneshot_mods_state(void) {
    uint8_t oneshot_mods = get_oneshot_mods();
    if (!(oneshot_mods & MOD_LSFT)) {
        del_oneshot_mods(MOD_LSFT);
        unregister_mods(MOD_LSFT);
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
        case COD_SPC:
        case LOW_SPC:
        case MED_CAS:
        case NAV_REP:
        case FNA_REP:
        case ALT_MAG:
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

// Custom Repeat and Magic Keys

bool custom_repeat_key_expired(void) {
    return custom_repeat_key_timer == 0 || (timer_elapsed(custom_repeat_key_timer) > CUSTOM_ALT_REPEAT_KEY_TIMEOUT);
}

void check_repeat_key_timeout(void) {
    if (custom_repeat_key_expired()) {
        clear_repeat_key();
    }
}

void clear_repeat_key(void) {
    custom_repeat_key_timer = 0;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case RAI_A2:
        case MED_CAS:
        case NAV_REP:
        case FNA_REP:
        case ALT_MAG:
            return false;
    }
    custom_repeat_key_timer = timer_read();
    return true;
}

keyrecord_t make_keyevent(bool press, uint16_t keycode) {
    keyrecord_t result = {
        .event   = MAKE_COMBOEVENT(press),
        .keycode = keycode,
    };
    return result;
}

void action_tap(uint16_t keycode) {
    action_tapping_process(make_keyevent(true, keycode));
    action_tapping_process(make_keyevent(false, keycode));
}

void process_repeat(uint16_t keycode) {
    uint16_t next_key = extract_tapping_keycode(keycode);
    switch (next_key) {
        case KC_H:
            next_key = MC_AH;
            break;
        case MC_SQ_C:
            next_key = OSL_A2;
            break;
        case MC_QU:
            next_key = MC_CR_E;
            break;
        case MC_SQUO:
            next_key = KC_V;
            break;
    }
    if (next_key != keycode) {
        action_tap(next_key);
    } else {
        action_tap(QK_REP);
    }
}

void process_magic(uint16_t keycode) {
    uint16_t next_key = extract_tapping_keycode(keycode);
    switch (next_key) {
        case MC_TL_A:
        case MC_TL_O:
        case MC_CR_A:
            next_key = KC_NO;
            break;
        case MC_GV_A:
            next_key = MC_QU;
            break;
        case MC_QU:
            next_key = OSL_A2;
            break;
        case KC_DOT:
            next_key = KC_SLSH;
            break;
        case KC_A:
        case KC_E:
        case KC_I:
        case KC_O:
        case KC_U:
        case MC_SQ_E:
        case MC_SQ_A:
        case MC_SQ_O:
        case MC_SQ_I:
        case MC_SQ_U:
        case MC_CR_E:
        case MC_CR_O:
        case MC_SQUO:
            next_key = KC_V;
            break;
        case KC_B:
        case KC_D:
        case KC_M:
        case KC_F:
            next_key = KC_Y;
            break;
        case MC_SQ_C:
        case KC_H:
        case KC_J:
        case KC_K:
        case KC_V:
        case KC_X:
        case KC_Z:
            next_key = OSL_A2;
            break;
    }
    if (next_key != keycode && next_key != extract_tapping_keycode(keycode)) {
        action_tap(next_key);
    } else {
        action_tap(KC_H);
    }
}

void activate_repeat_or_magic_key(bool isMagic) {
    if (isMagic) {
        process_magic(get_last_keycode());
    } else {
        process_repeat(get_last_keycode());
    }
}

process_record_result_t process_smart_thumbs(uint16_t keycode, keyrecord_t *record) {
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

    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT;

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
        case NAV_REP:
        case FNA_REP:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    activate_repeat_or_magic_key(false);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
        case MED_CAS:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (has_smart_case(WORD_CASE) || has_smart_case(CAPS_LOCK)) {
                        disable_smart_case();
                        clear_shift();
                    } else {
                        if (!isOneShotShift) {
                            add_oneshot_mods(MOD_LSFT);
                        } else {
                            set_smart_case_for_mods();
                        }
                    }
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
    }

    return PROCESS_RECORD_CONTINUE;
}

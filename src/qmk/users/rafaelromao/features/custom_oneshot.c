#include QMK_KEYBOARD_H

#include "custom_oneshot.h"

extern os_t os;

static custom_oneshots_t custom_oneshots = {.timer = 0};

// Custom oneshot mods

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods) {
        custom_oneshots.timer = timer_read();
    } else {
        custom_oneshots.timer = 0;
    }
}

void clear_locked_and_oneshot_mods(void) {
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    if (oneshot_locked_mods || oneshot_mods) {
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
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    if (!(oneshot_locked_mods & MOD_LSFT) && (oneshot_mods & MOD_LSFT)) {
        del_oneshot_mods(MOD_LSFT);
        unregister_mods(MOD_LSFT);
    }
    if (!(oneshot_locked_mods & MOD_LCTL) && (oneshot_mods & MOD_LCTL)) {
        del_oneshot_mods(MOD_LCTL);
        unregister_mods(MOD_LCTL);
    }
    if (!(oneshot_locked_mods & MOD_LGUI) && (oneshot_mods & MOD_LGUI)) {
        del_oneshot_mods(MOD_LGUI);
        unregister_mods(MOD_LGUI);
    }
    if (!(oneshot_locked_mods & MOD_LALT) && (oneshot_mods & MOD_LALT)) {
        del_oneshot_mods(MOD_LALT);
        unregister_mods(MOD_LALT);
    }
    if (!(oneshot_locked_mods & MOD_RALT) && (oneshot_mods & MOD_RALT)) {
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
        case RAI_ACT:
        case RAI_TAC:
        case ACT_SPC:
        case LOW_SPC:
        case LOW_NSE:
        case MED_CAS:
        case NAV_REP:
        case OS_LSFT:
        case OS_LCTL:
        case OS_LALT:
        case OS_LGUI:
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

process_record_result_t process_custom_oneshot(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && (IS_LAYER_ON(_ACCENT) || IS_LAYER_ON(_SEN_CASE)) && check_disable_oneshot(keycode)) {
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

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT || isOneShotLockedShift;
    bool isOneShotCtrl        = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt         = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui         = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShotButShift = isOneShotCtrl || isOneShotAlt || isOneShotGui;

    switch (keycode) {
        case RAI_ACT:
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
        case MED_CAS:
        case MAI_CAS:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (has_any_smart_case()) {
                        disable_smart_case();
                        clear_shift();
                    } else {
                        if (isAnyOneShotButShift || isOneShotLockedShift) {
                            clear_locked_and_oneshot_mods();
                        } else if (!isOneShotShift) {
                            add_oneshot_mods(MOD_LSFT);
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

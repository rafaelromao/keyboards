#include QMK_KEYBOARD_H

#include "custom_oneshot.h"

extern os_t              os;
extern custom_oneshots_t custom_oneshots;

static oneshot_mods_timer_t oneshot_mods_timer = {.timer = 0};

// Custom oneshot mods

void clear_expired_oneshot_mods(void) {
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

void disable_expired_oneshot_mods(void) {
    clear_expired_oneshot_mods();
    oneshot_mods_timer.timer = 0;
}

bool oneshot_mods_timer_expired(void) {
    return oneshot_mods_timer.timer > 0 && (timer_elapsed(oneshot_mods_timer.timer) > CUSTOM_ONESHOT_TIMEOUT);
}

void check_oneshot_mods_timeout(void) {
    if (oneshot_mods_timer_expired()) {
        disable_expired_oneshot_mods();
    }
}

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods) {
        oneshot_mods_timer.timer = timer_read();
    } else {
        oneshot_mods_timer.timer = 0;
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
    dyn_macro_reset();
}

// Custom oneshot keycodes

bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift) {
    return (isWindowsOrLinux && !isOneShotShift) || (!isWindowsOrLinux && isOneShotShift);
}

process_record_result_t process_custom_oneshot(uint16_t keycode, keyrecord_t *record) {
    bool isWindowsOrLinux     = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotDefaultMod  = (!isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_GUI)) || (isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_CTRL));
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT || isOneShotLockedShift;
    bool isOneShotCtrl        = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt         = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui         = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShotButShift = isOneShotCtrl || isOneShotAlt || isOneShotGui;

    switch (keycode) {
        case OS_RAI:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (IS_LAYER_ON(_RAISE)) {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    } else {
                        set_oneshot_layer(_RAISE, ONESHOT_START);
                        custom_oneshots.timer = timer_read();
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        case OS_LOW:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (IS_LAYER_ON(_LOWER)) {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    } else {
                        set_oneshot_layer(_LOWER, ONESHOT_START);
                        custom_oneshots.timer = timer_read();
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        case NAV_NG:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (IS_LAYER_ON(_NGRAMS)) {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    } else {
                        set_oneshot_layer(_NGRAMS, ONESHOT_START);
                        custom_oneshots.timer = timer_read();
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        case MED_SFT:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (has_any_smart_case()) {
                        disable_smart_case();
                        clear_shift();
                    } else {
                        if (isAnyOneShotButShift || isOneShotLockedShift) {
                            clear_locked_and_oneshot_mods();
                        } else if (!isOneShotShift && get_mods() == 0) {
                            add_oneshot_mods(MOD_BIT(KC_LSFT));
                        } else {
                            set_smart_case_for_mods(record);
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        case MAI_ALT:
        case MED_ALT:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShotButShift || isOneShotLockedShift) {
                        clear_locked_and_oneshot_mods();
                    } else if (!isOneShotAlt) {
                        if (isOneShotShift) {
                            clear_locked_and_oneshot_mods();
                        }
                        add_oneshot_mods(MOD_RALT);
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

        case MAI_MOD:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShotButShift || isOneShotLockedShift) {
                        clear_locked_and_oneshot_mods();
                    } else if (!isOneShotDefaultMod) {
                        if (isOneShotShift) {
                            clear_locked_and_oneshot_mods();
                        }
                        if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                            add_oneshot_mods(MOD_LCTL);
                        } else {
                            add_oneshot_mods(MOD_LGUI);
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;
    }

    return PROCESS_RECORD_CONTINUE;
}

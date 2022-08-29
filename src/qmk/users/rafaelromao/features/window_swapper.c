#include QMK_KEYBOARD_H

#include "window_swapper.h"

extern os_t os;

static bool swapping = false;
static bool tabbing  = false;

process_record_result_t process_window_swapper(uint16_t keycode, keyrecord_t *record) {
    if (start_long_press(record)) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isMacOS = os.type == MACOS;
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Back and Forth in the browser

    if (!swapping && is_long_press()) {
        switch (keycode) {
            case MC_SWLE:
                if (isMacOS) {
                    SEND_STRING(SS_LGUI("["));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
                }
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_SWRI:
                if (isMacOS) {
                    SEND_STRING(SS_LGUI("]"));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_RGHT)));
                }
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }

    // Back and Forth in the open applications or tabs

    if (swapping && keycode != MC_SWLE && keycode != MC_SWRI) {
        unregister_mods(MOD_LSFT);
        if (isMacOS) {
            if (tabbing) {
                unregister_mods(MOD_LCTL);
            } else {
                unregister_mods(MOD_LGUI);
            }
        } else {
            if (tabbing) {
                unregister_mods(MOD_LCTL);
            } else {
                unregister_mods(MOD_LALT);
            }
        }
        swapping = false;
        tabbing  = false;
    }

    switch (keycode) {
        case MC_SWLE:
            register_mods(MOD_LSFT);
            break;
        case MC_SWRI:
            unregister_mods(MOD_LSFT);
            break;
    }

    switch (keycode) {
        case MC_SWLE:
        case MC_SWRI:
            if (!record->event.pressed) {
                if (!swapping) {
                    swapping = true;
                    if (isMacOS) {
                        if (isShifted) {
                            tabbing = true;
                            register_mods(MOD_LCTL);
                        } else {
                            register_mods(MOD_LGUI);
                        }
                    } else {
                        if (isShifted) {
                            tabbing = true;
                            register_mods(MOD_LCTL);
                        } else {
                            register_mods(MOD_LALT);
                        }
                    }
                }
                tap_code(KC_TAB);
            }
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}

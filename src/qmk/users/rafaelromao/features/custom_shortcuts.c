#include QMK_KEYBOARD_H

#include "custom_shortcuts.h"

extern os_t os;

process_record_result_t process_custom_shortcuts(uint16_t keycode, keyrecord_t *record) {
    bool isMacOS        = os.type == MACOS;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (keycode) {
            // Zoom shortcuts

        case MC_MODP:
            if (record->event.pressed) {
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("+"));
                } else {
                    SEND_STRING(SS_LGUI("+"));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_MODM:
            if (record->event.pressed) {
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("-"));
                } else {
                    SEND_STRING(SS_LGUI("-"));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_SELC:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("a"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case MC_SAVE:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("s"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case MC_UNDO:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("z"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case MC_COPY:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("c"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case MC_PAST:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("v"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case MC_LOCK:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LGUI("l"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case MC_FULL:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    tap_code(KC_F11);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case MC_FIND:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isMacOS, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("f"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;
    }

    return PROCESS_RECORD_CONTINUE;
}

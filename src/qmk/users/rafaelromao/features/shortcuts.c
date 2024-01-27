#include QMK_KEYBOARD_H

#include "shortcuts.h"

process_record_result_t process_shortcuts(uint16_t keycode, keyrecord_t *record) {
    if (!is_shift_macro_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    if (record != NULL && record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted      = isOneShotShift || get_mods() & MOD_MASK_SHIFT;
    bool isMacOS        = is_macos();

    switch (keycode) {
            // Select All

        case MC_SELC:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("a"));
            } else {
                SEND_STRING(SS_LGUI("a"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Save

        case MC_SAVE:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("s"));
            } else {
                SEND_STRING(SS_LGUI("s"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Undo

        case MC_UNDO:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("z"));
            } else {
                SEND_STRING(SS_LGUI("z"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Copy

        case MC_COPY:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("c"));
            } else {
                SEND_STRING(SS_LGUI("c"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Selec All + Copy

        case MC_SCOP:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("a"));
                SEND_STRING(SS_LCTL("c"));
            } else {
                SEND_STRING(SS_LGUI("a"));
                SEND_STRING(SS_LGUI("c"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Selec All + Paste

        case MC_SPAS:
            clear_locked_and_oneshot_mods();
            if (isShifted) {
                clear_shift();
            }
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("a"));
                if (isShifted) {
                    register_mods(MOD_LSFT);
                }
                SEND_STRING(SS_LCTL("v"));
                if (isShifted) {
                    unregister_mods(MOD_LSFT);
                }
            } else {
                SEND_STRING(SS_LGUI("a"));
                if (isShifted) {
                    register_mods(MOD_LSFT);
                }
                SEND_STRING(SS_LGUI("v"));
                if (isShifted) {
                    unregister_mods(MOD_LSFT);
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Paste

        case MC_PAST:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("v"));
            } else {
                SEND_STRING(SS_LGUI("v"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find

        case MC_FIND:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("f"));
            } else {
                SEND_STRING(SS_LGUI("f"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Lock

        case MC_LOCK:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LGUI("l"));
            } else {
                SEND_STRING(SS_LGUI(SS_LCTL("q")));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Full Screen

        case MC_FULL:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                tap_code(KC_F11);
            } else {
                SEND_STRING(SS_LGUI(SS_LCTL("f")));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Esc, Tab, Enter

        case MC_ESCC:
            clear_shift();
            tap_code(KC_ESC);
            layer_clear();
            disable_smart_case();
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_ESC:
            clear_shift();
            tap_code(KC_ESC);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_TAB:
            clear_shift();
            tap_code(KC_TAB);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_ENT:
            clear_shift();
            tap_code(KC_ENT);
            return PROCESS_RECORD_RETURN_FALSE;

            // Save + Esc

        case MC_ESAV:
            process_shortcuts(MC_SAVE, NULL);
            process_shortcuts(MC_ESC, NULL);
            return PROCESS_RECORD_RETURN_FALSE;

            // NumWord

        case TG_NUMC:
            set_smart_case(NUM_CASE);
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}

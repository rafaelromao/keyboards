#include QMK_KEYBOARD_H

#include "macros.h"

extern os_t os;

process_record_result_t process_macro_keycode(uint16_t keycode, bool isOneShotShift, bool isShifted) {
    bool isMacOS = os.type == MACOS;

    switch (keycode) {
            // Inverted underscore and minus

        case MC_UNDS:
            if (isShifted) {
                clear_shift();
                tap_code(KC_MINS);
            } else {
                tap_code16(KC_UNDS);
            }
            return PROCESS_RECORD_RETURN_FALSE;

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

            // Conditional operators

        case MC_DAND:
            tap_code16(KC_AMPR);
            if (!isShifted) {
                tap_code16(KC_AMPR);
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_DPIP:
            tap_code16(KC_PIPE);
            if (!isShifted) {
                tap_code16(KC_PIPE);
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Rename / Refactor

        case MC_REFC:
            if (isShifted) {
                clear_shift();
                if (isMacOS) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_T)));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT(SS_TAP(X_T)))));
                }
            } else {
                SEND_STRING(SS_LSFT(SS_TAP(X_F6)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Quick Actions

        case MC_QUIK:
            SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
            return PROCESS_RECORD_RETURN_FALSE;

            // Project Files / Recent Files

        case MC_PROJ:
            if (isShifted) {
                clear_shift();
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_E)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_E)));
                }
                return PROCESS_RECORD_RETURN_FALSE;
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI("1"));
                } else {
                    SEND_STRING(SS_LCTL("1"));
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

            // Search Everything

        case MC_SEEV:
            tap_code16(KC_LSFT);
            tap_code16(KC_LSFT);
            return PROCESS_RECORD_RETURN_FALSE;

            // Run Anything

        case MC_RUAN:
            tap_code16(KC_LCTL);
            tap_code16(KC_LCTL);
            return PROCESS_RECORD_RETURN_FALSE;

            // Build

        case MC_BUID:
            if (isMacOS) {
                SEND_STRING(SS_LGUI(SS_TAP(X_F9)));
            } else {
                SEND_STRING(SS_LCTL(SS_TAP(X_F9)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Complete Statement / Generete Code

        case MC_COMP:
            if (isShifted) {
                clear_shift();
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_N)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_INS)));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_ENT))));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_ENT))));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Type-matching Auto Complete / Basic Auto Complete

        case MC_AUCO:
            if (isShifted) {
                clear_shift();
                SEND_STRING(SS_LCTL(" "));
            } else {
                SEND_STRING(SS_LCTL(SS_LSFT(" ")));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Next Error / Next Warning

        case MC_NEER:
            if (isShifted) {
                clear_shift();
                SEND_STRING(SS_TAP(X_F2));
            } else {
                SEND_STRING(SS_LSFT(SS_TAP(X_F2)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find Usages / Go To Definition

        case MC_FIUS:
            if (isShifted) {
                clear_shift();
                if (isMacOS) {
                    SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_B))));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_B))));
                    break;
                }
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_F7)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Join Lines

        case MC_JOIN:
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_DEL));
            return PROCESS_RECORD_RETURN_FALSE;

            // Comment Lines

        case MC_COMT:
            if (isMacOS) {
                SEND_STRING(SS_LGUI("/"));
            } else {
                SEND_STRING(SS_LCTL("/"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // END { ENTER }

        case MC_CUR:
            SEND_STRING(SS_TAP(X_END) "{}" SS_DELAY(50) SS_TAP(X_LEFT) SS_TAP(X_ENT));
            return PROCESS_RECORD_RETURN_FALSE;

            // END ; ENTER

        case MC_SENT:
            tap_code(KC_END);
            tap_code(KC_SCLN);
            tap_code(KC_ENT);
            return PROCESS_RECORD_RETURN_FALSE;

            // Refresh / Clear Cache

        case MC_REF:
            if (isShifted) {
                clear_shift();
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_R))));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_F5)));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_R)));
                } else {
                    tap_code(KC_F5);
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Esc, Close Window, Close Tab

        case MC_ESC:
            if (isShifted) {
                clear_shift();
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_W)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F4)));
                    break;
                }
            } else {
                tap_code(KC_ESC);
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_ESAV:
            process_macro_keycode(MC_SAVE, false, false);
            process_macro_keycode(MC_ESC, false, false);
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Macros

    switch (process_macro_keycode(keycode, isOneShotShift, isShifted)) {
        case PROCESS_RECORD_RETURN_FALSE:
            return PROCESS_RECORD_RETURN_FALSE;
        default:
            break;
    };

    return PROCESS_RECORD_CONTINUE;
}

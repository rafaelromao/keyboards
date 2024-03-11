#include QMK_KEYBOARD_H

#include "shortcuts.h"

process_record_result_t process_shortcut_keycode(uint16_t keycode, bool isOneShotShift, bool isShifted) {
    bool isMacOS = is_macos();

    switch (keycode) {
            // Select All

        case MC_SELC:
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("a"));
            } else {
                SEND_STRING(SS_LGUI("a"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Save

        case MC_SAVE:
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("s"));
            } else {
                SEND_STRING(SS_LGUI("s"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Undo

        case MC_UNDO:
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("z"));
            } else {
                SEND_STRING(SS_LGUI("z"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Copy

        case MC_COPY:
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("c"));
            } else {
                SEND_STRING(SS_LGUI("c"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Selec All + Copy

        case MC_SCOP:
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
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("v"));
            } else {
                SEND_STRING(SS_LGUI("v"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find

        case MC_FIND:
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("f"));
            } else {
                SEND_STRING(SS_LGUI("f"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Lock

        case MC_LOCK:
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LGUI("l"));
            } else {
                SEND_STRING(SS_LGUI(SS_LCTL("q")));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Full Screen

        case MC_FULL:
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                tap_code(KC_F11);
            } else {
                SEND_STRING(SS_LGUI(SS_LCTL("f")));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Esc, Tab, Enter

        case MC_ESCC:
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

            // App Shortcuts

        case MC_PREV:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("s"))));
            } else {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("p"))));
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_TABS:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("f"))));
            } else {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT(SS_LGUI("t")))));
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_CALC:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("t"))));
            } else {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("c"))));
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_MIC:
            if (isShifted) {
                tap_code(KC_MUTE);
            } else {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT(SS_LGUI("m")))));
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_CAM:
            SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT(SS_LGUI("c")))));
            return PROCESS_RECORD_RETURN_FALSE;

            // CODING

            // Quick Actions / Generate

        case MC_QUIK:
            if (isShifted) {
                SEND_STRING(SS_LGUI(SS_TAP(X_N)));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Refactor / Reformat

        case MC_REFC:
            if (isShifted) {
                SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_L))));
            } else {
                SEND_STRING(SS_LCTL(SS_TAP(X_T)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Comment Lines

        case MC_COMT:
            SEND_STRING(SS_LGUI("/"));
            return PROCESS_RECORD_RETURN_FALSE;

            // Type-matching Auto Complete / Basic Auto Complete

        case MC_AUCO:
            if (isShifted) {
                SEND_STRING(SS_LCTL(SS_TAP(X_SPC)));
            } else {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_SPC))));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Quick Docs / Parameter Info

        case MC_QDOC:
            if (isShifted) {
                SEND_STRING(SS_LGUI(SS_TAP(X_P)));
            } else {
                tap_code(KC_F1);
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find Symbol / Find Action

        case MC_FSYM:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_A))));
            } else {
                SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_O))));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Toggle Breakpoint / View Breakpoints

        case MC_BREK:
            if (isShifted) {
                SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_F8))));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_F8)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Run / Stop

        case MC_RUN:
            if (isShifted) {
                SEND_STRING(SS_LCTL(SS_TAP(X_F2)));
            } else {
                SEND_STRING(SS_LCTL(SS_TAP(X_R)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Debug / Resume

        case MC_DBUG:
            if (isShifted) {
                SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_R))));
            } else {
                SEND_STRING(SS_LCTL(SS_TAP(X_D)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Build / Rebuild

        case MC_BUID:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_F9))));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_F9)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Recent Files / Previous Error

        case MC_RECE:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F2)));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_E)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Swapper / Next Error

        case MC_SWAP:
            if (isShifted) {
                SEND_STRING(SS_TAP(X_F2));
            } else {
                SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Arrow Down / Complete Statement

        case MC_DOWN:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_ENT))));
            } else {
                tap_code(KC_DOWN);
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Show Usages / Quick Definition

        case MC_FIUS:
            if (isShifted) {
                SEND_STRING(SS_LALT(SS_TAP(X_SPC)));
            } else {
                SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_F7))));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Project Files / Select In

        case MC_PROJ:
            if (isShifted) {
                SEND_STRING(SS_LALT(SS_TAP(X_F1)));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_1)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Step Over / Evaluate

        case MC_STOV:
            if (isShifted) {
                SEND_STRING(SS_LALT(SS_TAP(X_F8)));
            } else {
                SEND_STRING(SS_TAP(X_F8));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Step Into / Step Out

        case MC_STIN:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F8)));
            } else {
                SEND_STRING(SS_TAP(X_F7));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Reset Zoom / Refresh

        case MC_Z0R:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_R)));
                } else {
                    tap_code(KC_F5);
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_0)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_0)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Esc / Close Tab

        case MC_CLOS:
            if (isShifted) {
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

            // Delete Word

        case MC_DELW:
            if (isMacOS) {
                tap_code16(LALT(KC_BSPC));
            } else {
                tap_code16(LCTL(KC_BSPC));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // VIM

            // Shift V

        case MC_SVI:
            register_mods(MOD_MASK_SHIFT);
            tap_code(KC_V);
            unregister_mods(MOD_MASK_SHIFT);
            return PROCESS_RECORD_RETURN_FALSE;

            // Ctrl V

        case MC_CVI:
            register_mods(MOD_MASK_CTRL);
            tap_code(KC_V);
            unregister_mods(MOD_MASK_CTRL);
            return PROCESS_RECORD_RETURN_FALSE;

            // "0p

        case MC_0P:
            tap_code16(KC_DQUO);
            tap_code(KC_0);
            tap_code(KC_P);
            return PROCESS_RECORD_RETURN_FALSE;

            // ESC + O + ESC

        case MC_OESC:
            if (isShifted) {
                register_mods(MOD_MASK_SHIFT);
                tap_code(KC_O);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_ESC);
            } else {
                tap_code(KC_O);
                tap_code(KC_ESC);
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // ESC + LShift(O) + ESC

        case MC_SOES:
            register_mods(MOD_MASK_SHIFT);
            tap_code(KC_O);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code(KC_ESC);
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_shortcuts(uint16_t keycode, keyrecord_t *record) {
    if (!is_shift_macro_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    if (record != NULL && !record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted      = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Macros

    int8_t mods = get_mods();
    if (isShifted) {
        clear_oneshot_shift();
        unregister_mods(mods);
    }
    process_record_result_t result = process_shortcut_keycode(keycode, isOneShotShift, isShifted);
    if (isShifted) {
        wait_ms(100);
        register_mods(mods);
    }

    return result;
}
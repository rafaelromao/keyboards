#include QMK_KEYBOARD_H

#include "macros.h"

process_record_result_t process_macro_keycode(uint16_t keycode, bool isOneShotShift, bool isShifted) {
    bool isMacOS = is_macos();

    switch (keycode) {
            // Quotes

        case MC_BTIC:
            tap_code(KC_GRV);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_DQUO:
            tap_code16(KC_DQUO);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_SQUO:
            if (!isShifted) {
                tap_code(KC_QUOT);
                tap_code(KC_SPC);
            } else {
                tap_code16(KC_DQUO);
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_CIRC:
            tap_code16(KC_CIRC);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_TILD:
            tap_code16(KC_TILD);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_DAR:
            tap_code16(KC_EQL);
            tap_code16(KC_GT);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_SAR:
            tap_code16(KC_MINS);
            tap_code16(KC_GT);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_DEQ:
            tap_code16(KC_EQL);
            tap_code16(KC_EQL);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_NEQ:
            tap_code16(KC_EXLM);
            tap_code16(KC_EQL);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_LTE:
            tap_code16(KC_LT);
            tap_code16(KC_EQL);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_GTE:
            tap_code16(KC_GT);
            tap_code16(KC_EQL);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_DDS:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            tap_code16(KC_SLSH);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_TISL:
            tap_code16(KC_TILD);
            tap_code(KC_SPC);
            tap_code16(KC_SLSH);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_DEG:
            if (isMacOS) {
                tap_code16(LSFT(RALT(KC_8)));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_SEC:
            if (isMacOS) {
                SEND_STRING(SS_LALT(SS_TAP(X_6)));
            } else {
                SEND_STRING(SS_RALT(SS_LSFT(SS_TAP(X_S))));
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_ORDO:
            if (isMacOS) {
                tap_code16(RALT(KC_0));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7)));
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_ORDA:
            if (isMacOS) {
                tap_code16(RALT(KC_9));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_6)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

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

            // END ; ENTER

        case MC_SENT:
            tap_code(KC_END);
            tap_code(KC_SCLN);
            tap_code(KC_ENT);
            disable_smart_case();
            return PROCESS_RECORD_RETURN_FALSE;

            // []

        case MC_BRAC:
            tap_code16(KC_LBRC);
            tap_code16(KC_RBRC);
            return PROCESS_RECORD_RETURN_FALSE;

            // {}

        case MC_CURS:
            tap_code16(KC_LCBR);
            tap_code16(KC_RCBR);
            return PROCESS_RECORD_RETURN_FALSE;

            // END { ENTER }

        case MC_CUR:
            SEND_STRING(SS_TAP(X_END) "{}" SS_DELAY(50) SS_TAP(X_LEFT) SS_TAP(X_ENT));
            disable_smart_case();
            return PROCESS_RECORD_RETURN_FALSE;

            // Join Lines

        case MC_JOIN:
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_DEL));
            return PROCESS_RECORD_RETURN_FALSE;

            // Conditional operators

        case MC_DAND:
            tap_code16(KC_AMPR);
            tap_code16(KC_AMPR);
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_DPIP:
            tap_code16(KC_PIPE);
            tap_code16(KC_PIPE);
            return PROCESS_RECORD_RETURN_FALSE;

            // Quick Actions / Breakpoint

        case MC_QUIK:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_F8)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F8)));
                    break;
                }
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
            }
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
                if (isMacOS) {
                    SEND_STRING(SS_LCMD(SS_TAP(X_P)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_P)));
                    break;
                }
            } else {
                if (isMacOS) {
                    tap_code(KC_F1);
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_Q)));
                    break;
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find Symbol / Find Action

        case MC_FSYM:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_A))));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_A))));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_O))));
                } else {
                    SEND_STRING(SS_LALT(SS_LSFT(SS_LCTL(SS_TAP(X_N)))));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Run / Stop

        case MC_RUN:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_F2)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F2)));
                    break;
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_R)));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_F10)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Debug / Resume

        case MC_DBUG:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_R))));
                } else {
                    SEND_STRING(SS_TAP(X_F9));
                    break;
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_D)));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_F9)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Build / Rebuild

        case MC_BUID:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_F9))));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_F9))));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_F9)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F9)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Project Files / Select In

        case MC_PROJ:
            if (isShifted) {
                SEND_STRING(SS_LALT(SS_TAP(X_F1)));
                return PROCESS_RECORD_RETURN_FALSE;
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_1)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_1)));
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

            // Recent Files / Previous Error

        case MC_RECE:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F2)));
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_E)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_E)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Complete Statement / Next Error

        case MC_COMP:
            if (isShifted) {
                SEND_STRING(SS_TAP(X_F2));
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_ENT))));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_ENT))));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find Usages / Quick Definition

        case MC_FIUS:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LALT(SS_TAP(X_SPC)));
                } else {
                    SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_I))));
                    break;
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_F7))));
                } else {
                    SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_F7))));
                    break;
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Refactor / Reformat

        case MC_REFC:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_L))));
                } else {
                    SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_L))));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_T)));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT(SS_TAP(X_T)))));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Comment Lines

        case MC_COMT:
            if (isMacOS) {
                SEND_STRING(SS_LGUI("/"));
            } else {
                SEND_STRING(SS_LCTL("/"));
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

            // Close Window / Close Tab

        case MC_CLOS:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_W)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F4)));
                    break;
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_Q)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_F4)));
                    break;
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Question Mark with Sentence Case

        case MC_QUES:
            tap_code16(KC_QUES);
            start_sentence_case();
            return PROCESS_RECORD_RETURN_FALSE;

            // Exclamation with Sentence Case

        case MC_EXLM:
            tap_code16(KC_EXLM);
            start_sentence_case();
            return PROCESS_RECORD_RETURN_FALSE;

            // Euro Sign

        case MC_EUR:
            if (isMacOS) {
                tap_code16(LSFT(RALT(KC_2)));
            } else {
                tap_code16(LCTL(LALT(KC_5)));
            }
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {
    if (!is_shift_macro_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    if (record != NULL && !record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Macros

    int8_t mods = get_mods();
    if (isShifted) {
        clear_oneshot_shift();
        unregister_mods(mods);
    }
    process_record_result_t result = process_macro_keycode(keycode, isOneShotShift, isShifted);
    if (isShifted) {
        wait_ms(100);
        register_mods(mods);
    }

    return result;
}

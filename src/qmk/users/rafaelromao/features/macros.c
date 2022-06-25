#include QMK_KEYBOARD_H

#include "macros.h"

extern os_t os;

ngrams_timer_t ngrams_timer = {.timer = 0};

void disable_ngrams_layer(void) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    ngrams_timer.timer = 0;
}

bool ngrams_timer_expired(void) {
    return ngrams_timer.timer > 0 && (timer_elapsed(ngrams_timer.timer) > CUSTOM_ONESHOT_TIMEOUT);
}

void check_ngrams_timeout(void) {
    if (ngrams_timer_expired()) {
        disable_ngrams_layer();
    }
}

void tap_accent_dead_key(uint16_t keycode) {
    switch (keycode) {
        case MC_GV_A:
            tap_code16(KC_GRV);
            break;
        case MC_CR_A:
        case MC_CR_E:
        case MC_CR_O:
            tap_code16(KC_CIRC);
            break;
        case MC_TL_A:
        case MC_TL_O:
            tap_code16(KC_TILD);
            break;
        case MC_SQ_C:
        case MC_SQ_A:
        case MC_SQ_E:
        case MC_SQ_I:
        case MC_SQ_O:
        case MC_SQ_U:
            tap_code(KC_QUOT);
            break;
    }
}

void tap_accent_tap_key(uint32_t keycode) {
    switch (keycode) {
        case MC_GV_A:
        case MC_CR_A:
        case MC_TL_A:
        case MC_SQ_A:
            tap_code(KC_A);
            break;
        case MC_CR_E:
        case MC_SQ_E:
            tap_code(KC_E);
            break;
        case MC_TL_O:
        case MC_CR_O:
        case MC_SQ_O:
            tap_code(KC_O);
            break;
        case MC_SQ_I:
            tap_code(KC_I);
            break;
        case MC_SQ_U:
            tap_code(KC_U);
            break;
        case MC_SQ_C:
            tap_code(KC_C);
            break;
    }
}

bool is_accentuated_keycode(uint16_t keycode) {
    switch (keycode) {
        case MC_GV_A:
        case MC_CR_A:
        case MC_TL_A:
        case MC_SQ_A:
        case MC_CR_E:
        case MC_SQ_E:
        case MC_SQ_I:
        case MC_TL_O:
        case MC_CR_O:
        case MC_SQ_O:
        case MC_SQ_U:
        case MC_SQ_C:
            return true;
    }
    return false;
}

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed && keycode != NAV_NG && keycode != MED_SFT) {
        disable_ngrams_layer();
    }

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;
    bool isWindowsOrLinux     = os.type == WINDOWS || os.type == LINUX;

    if (!record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    switch (keycode) {
        // Accents
        case MC_BTIC:
            clear_shift();
            tap_code(KC_GRV);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_DQUO:
            clear_shift();
            tap_code16(KC_DQUO);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_SQUO:
            clear_shift();
            tap_code(KC_QUOT);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_CIRC:
            clear_shift();
            tap_code16(KC_CIRC);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_TILD:
            clear_shift();
            tap_code16(KC_TILD);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Tild combos

        case MC_AO:
            clear_shift();
            tap_code16(KC_TILD);
            tap_code(KC_A);
            tap_code(KC_O);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_CAO:
            clear_shift();
            tap_code16(KC_QUOT);
            tap_code(KC_C);
            tap_code16(KC_TILD);
            tap_code(KC_A);
            tap_code(KC_O);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_OES:
            clear_shift();
            tap_code16(KC_TILD);
            tap_code(KC_O);
            tap_code(KC_E);
            tap_code(KC_S);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_COES:
            clear_shift();
            tap_code16(KC_QUOT);
            tap_code(KC_C);
            tap_code16(KC_TILD);
            tap_code(KC_O);
            tap_code(KC_E);
            tap_code(KC_S);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_EM:
            clear_shift();
            tap_code16(KC_QUOT);
            tap_code(KC_E);
            tap_code(KC_M);
            return PROCESS_RECORD_RETURN_FALSE;

            // N-Grams

        case MC_QU:
            SEND_STRING("qu");
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_LH:
            SEND_STRING("lh");
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_PH:
            SEND_STRING("ph");
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_TH:
            SEND_STRING("th");
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_CH:
            SEND_STRING("ch");
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_WH:
            SEND_STRING("wh");
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_GH:
            SEND_STRING("gh");
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_NH:
            SEND_STRING("nh");
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_SH:
            SEND_STRING("sh");
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_THE:
            SEND_STRING("the");
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_CHE:
            SEND_STRING("che");
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_ION:
            SEND_STRING("ion");
            return PROCESS_RECORD_RETURN_FALSE;

            // Degree symbol

        case MC_DEG:
            if (os.type == MACOS) {
                tap_code16(LSFT(RALT(KC_8)));
            } else {
                tap_code16(LSFT(LCTL(KC_2)));
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

            // Recent Files

        case MC_REFI:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LCTL(SS_TAP(X_E)));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_E)));
                break;
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Refactor This

        case MC_REFC:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT(SS_TAP(X_T)))));
            } else {
                SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_T)))));
                break;
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Quick Actions

        case MC_QUIK:
            SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
            return PROCESS_RECORD_RETURN_FALSE;

            // Project Files

        case MC_PROJ:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LCTL("1"));
            } else {
                SEND_STRING(SS_LGUI("1"));
                break;
            }
            return PROCESS_RECORD_RETURN_FALSE;

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
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LCTL(SS_TAP(X_F9)));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_F9)));
                break;
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Complete Statement

        case MC_COMP:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_ENT))));
            } else {
                SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_ENT))));
                break;
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Autocomplete Options

        case MC_AUCO:
            SEND_STRING(SS_LCTL(" "));
            return PROCESS_RECORD_RETURN_FALSE;

            // Next Error

        case MC_NEER:
            SEND_STRING(SS_LSFT(SS_TAP(X_F2)));
            return PROCESS_RECORD_RETURN_FALSE;

            // Find Usages

        case MC_FIUS:
            SEND_STRING(SS_LALT(SS_TAP(X_F7)));
            return PROCESS_RECORD_RETURN_FALSE;

            // Join Lines

        case MC_JOIN:
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_DEL));
            return PROCESS_RECORD_RETURN_FALSE;

            // Comment

        case MC_COMT:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LCTL("/"));
            } else {
                SEND_STRING(SS_LGUI("/"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Vim replace

        case MC_VIMR:
            SEND_STRING(":%s//g");
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            return PROCESS_RECORD_RETURN_FALSE;
    }

    // Accentuated characters

    if (!is_accentuated_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    clear_locked_and_oneshot_mods();

    tap_accent_dead_key(keycode);
    if (isShifted) {
        register_mods(MOD_LSFT);
    }
    tap_accent_tap_key(keycode);
    if (isShifted) {
        unregister_mods(MOD_LSFT);
    }

    return PROCESS_RECORD_CONTINUE;
}

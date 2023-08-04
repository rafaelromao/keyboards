#include QMK_KEYBOARD_H

#include "sentence_case.h"

sentence_case_t sentence_case = {.state = SENTENCE_CASE_NONE};

void start_sentence_case(void) {
    // Called after . ? and !
    sentence_case.state = SENTENCE_CASE_STARTED;
}

process_record_result_t process_sentence_case(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && sentence_case.state != SENTENCE_CASE_NONE) {
        switch (keycode) {
            // Navigation
            case KC_HOME:
            case KC_END:
            case KC_LEFT:
            case KC_RIGHT:
            case KC_ENT:
            case KC_TAB:
            case TD_DOT:
            case TD_COMM:
                clear_shift();
                sentence_case.state = SENTENCE_CASE_NONE;
                return PROCESS_RECORD_CONTINUE;
        }
    }
    if (record->tap.count && record->event.pressed) {
        uint16_t key = extract_base_tapping_keycode(keycode);
        switch (key) {
            // Space
            case KC_SPC:
                if (sentence_case.state == SENTENCE_CASE_STARTED) {
                    tap_code(KC_SPC);
                    add_oneshot_mods(MOD_LSFT);
                    sentence_case.state = SENTENCE_CASE_FINISHING;
                    return PROCESS_RECORD_RETURN_FALSE;
                }
        }
        switch (keycode) {
            // Cancel
            case NAV_REP:
            case QK_REP:
                if (sentence_case.state != SENTENCE_CASE_NONE) {
                    clear_shift();
                    sentence_case.state = SENTENCE_CASE_NONE;
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            // One Shot Shift
            case MED_CAS:
                if (sentence_case.state != SENTENCE_CASE_NONE) {
                    add_oneshot_mods(MOD_LSFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            default:
                sentence_case.state = SENTENCE_CASE_NONE;
                return PROCESS_RECORD_CONTINUE;
        }
    }
    return PROCESS_RECORD_CONTINUE;
}
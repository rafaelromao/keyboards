#include QMK_KEYBOARD_H

#include "sentence_case.h"

sentence_case_t sentence_case = {.state = SENTENCE_CASE_NONE};

void start_sentence_case(void) {
    // Called after . ? and !
    sentence_case.state = SENTENCE_CASE_STARTED;
    sentence_case.start_time = timer_read();
}

bool is_expired(void) {
    return timer_elapsed(sentence_case.start_time) > ONESHOT_TIMEOUT;
}

process_record_result_t process_sentence_case(uint16_t keycode, keyrecord_t *record) {
    // Cancel after timeout
    if (sentence_case.state != SENTENCE_CASE_NONE && is_expired()) {
        sentence_case.state = SENTENCE_CASE_NONE;
        return PROCESS_RECORD_CONTINUE;
    }
    // Process next capitalized key
    if (record->event.pressed && sentence_case.state != SENTENCE_CASE_NONE) {
        if (sentence_case.state == SENTENCE_CASE_FINISHING) {
            // Process macros
            switch (keycode) {
                // Skip dot and comma
                case TD_DOT:
                case TD_COMM:
                    sentence_case.state = SENTENCE_CASE_NONE;
                    return PROCESS_RECORD_CONTINUE;
                // Process alpha macros
                case MC_QU:
                    add_oneshot_mods(MOD_LSFT);
                    sentence_case.state = SENTENCE_CASE_NONE;
                    return PROCESS_RECORD_CONTINUE;
            }
            // Process alphas
            uint16_t key = extract_tapping_keycode(keycode);
            switch (key) {
                case KC_A ... KC_Z:
                    add_oneshot_mods(MOD_LSFT);
                    sentence_case.state = SENTENCE_CASE_NONE;
                    return PROCESS_RECORD_CONTINUE;
            }
        }
    }
    // Handle the Sentence Case state
    if (record->tap.count && record->event.pressed) {
        uint16_t key = extract_tapping_keycode(keycode);
        switch (key) {
            // Space
            case KC_SPC:
                if (sentence_case.state == SENTENCE_CASE_STARTED) {
                    tap_code(KC_SPC);
                    sentence_case.state = SENTENCE_CASE_FINISHING;
                    return PROCESS_RECORD_RETURN_FALSE;
                }
        }
        switch (keycode) {
            // Continue to Alpha2 layer
            case RAI_A2:
                return PROCESS_RECORD_CONTINUE;
            // Cancel
            case NAV_REP:
            case FNA_REP:
            case NAV_MAG:
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
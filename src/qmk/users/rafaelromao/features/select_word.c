#include "select_word.h"

extern os_t os;

enum { STATE_NONE, STATE_LINE_SELECTED, STATE_WORD_SELECTED, STATE_WORD, STATE_FIRST_LINE, STATE_LINE };

static uint8_t state = STATE_NONE;

process_record_result_t process_select_word(uint16_t keycode, keyrecord_t* record) {

    if (keycode == SS_SELW && record->event.pressed) {
        bool isShifted = get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
        if (isShifted || state == STATE_LINE_SELECTED) {
            // Select Line
            clear_mods();
            clear_locked_and_oneshot_mods();
            if (state == STATE_NONE) {
                tap_code(KC_HOME);
                register_mods(MOD_LSFT);
                tap_code(KC_END);
                state = STATE_FIRST_LINE;
            } else {
                register_mods(MOD_LSFT);
                register_code(KC_DOWN);
                state = STATE_LINE;
            }
        } else {
            // Select Word
            if (os.type == MACOS) {
                register_code(KC_LALT);
            } else {
                register_code(KC_LCTL);
            }
            if (state == STATE_NONE) {
                tap_code(KC_RIGHT);
                tap_code(KC_LEFT);
            }
            register_mods(MOD_LSFT);
            register_code(KC_RGHT);
            state = STATE_WORD;
        }
        return PROCESS_RECORD_RETURN_FALSE;
    }

    switch (state) {
        case STATE_WORD:
            unregister_code(KC_RGHT);
            unregister_mods(MOD_LSFT);
            if (os.type == MACOS) {
                unregister_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
            }
            state = STATE_WORD_SELECTED;
            break;

        case STATE_FIRST_LINE:
            unregister_mods(MOD_LSFT);
            state = STATE_LINE_SELECTED;
            break;

        case STATE_LINE:
            unregister_mods(MOD_LSFT);
            unregister_code(KC_DOWN);
            state = STATE_LINE_SELECTED;
            break;

        case STATE_WORD_SELECTED:
        case STATE_LINE_SELECTED:
            if (keycode != SS_SELW && record->event.pressed) {
                unregister_mods(MOD_LSFT);
                tap_code(KC_RGHT);
                state = STATE_NONE;
                return PROCESS_RECORD_CONTINUE;
            }
        default:
            state = STATE_NONE;
    }

    return PROCESS_RECORD_CONTINUE;
}

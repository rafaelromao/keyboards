#include QMK_KEYBOARD_H

#include "custom_shift.h"

extern os_t os;

process_record_result_t process_custom_shift(uint16_t keycode, keyrecord_t *record) {
    if (start_long_press(record)) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    bool isMacOS = os.type == MACOS;

    switch (keycode) {
            // Inverted colon and semicolon
        case MC_COLN:
            if (is_long_press()) {
                if (isMacOS) {
                    tap_code16(LSFT(RALT(KC_8)));
                } else {
                    tap_code16(LSFT(LCTL(KC_2)));
                }
            } else {
                if (isShifted) {
                    clear_shift();
                    tap_code(KC_SCLN);
                } else {
                    tap_code16(KC_COLN);
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Inverted underscore and minus
        case MC_UNDS:
            if (isShifted) {
                clear_shift();
                tap_code(KC_MINS);
            } else {
                tap_code16(KC_UNDS);
            }
            return PROCESS_RECORD_RETURN_FALSE;
    }

    uint16_t key = extract_base_tapping_keycode(keycode);

    switch (key) {
            // Shifted numrow = numpad

        case KC_1 ... KC_0:
            if (isShifted) {
                tap_code(key + 59);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_CONTINUE;
    }

    return PROCESS_RECORD_CONTINUE;
}

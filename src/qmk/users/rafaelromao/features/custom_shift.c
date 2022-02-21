#include QMK_KEYBOARD_H

#include "custom_shift.h"

extern os_t os;

process_record_result_t process_custom_shift(uint16_t keycode, keyrecord_t *record) {

    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;
    uint16_t key = extract_base_tapping_keycode(keycode);

    switch (key) {

        // Shift+Backspace for Delete (when not one-shot)

        case KC_BSPC:
            if (record->event.pressed) {
                if (isShifted && !isOneShotShift) {
                    tap_code(KC_DEL);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_RETURN_TRUE;

        // Ignore space for one-shot shift

        case KC_SPC:
            if (record->event.pressed) {
                if (isOneShotShift) {
                    tap_code(KC_SPC);
                    add_oneshot_mods(MOD_LSFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_CONTINUE;

    }

    return PROCESS_RECORD_CONTINUE;
}

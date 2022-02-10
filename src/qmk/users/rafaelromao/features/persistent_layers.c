#include QMK_KEYBOARD_H

#include "persistent_layers.h"

process_record_result_t process_persistent_layers(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case DF_ROM:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ROMAK);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case DF_QWE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return PROCESS_RECORD_RETURN_FALSE;

    }

    return PROCESS_RECORD_CONTINUE;
}

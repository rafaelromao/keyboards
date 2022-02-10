#include QMK_KEYBOARD_H

#include "mouselayer_toggle.h"

static mouselayer_t mouselayer = {
    .enabled = true
};

process_record_result_t process_mouselayer(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // Enable/Disable the Mouse Layer

        case TG_M_ON:
            if (record->event.pressed) {
                mouselayer.enabled = true;
                layer_off(_MOUSE);
                layer_off(_NAVIGATION);
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case TG_M_OF:
            if (record->event.pressed) {
                mouselayer.enabled = false;
                layer_off(_MOUSE);
                layer_off(_NAVIGATION);
            }
            return PROCESS_RECORD_RETURN_FALSE;

        // Check if the mouselayer should be replaced by the navigation layer

        case MOU_CAP:
        case MOU_0:
            // If it is starting or finishing holding, and the mouse layer is disabled,
            // activate or deactivate the navigation layer instead, otherwise continue with normal behavior
            if (!record->tap.count) {
                if (!mouselayer.enabled) {
                    if (record->event.pressed) {
                        layer_on(_NAVIGATION);
                        return PROCESS_RECORD_RETURN_FALSE;
                    } else {
                        layer_off(_NAVIGATION);
                        return PROCESS_RECORD_RETURN_FALSE;
                    }
                }
                return PROCESS_RECORD_RETURN_TRUE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}

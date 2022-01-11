/* Copyright 2021 Rafael Romão @rafaelromao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

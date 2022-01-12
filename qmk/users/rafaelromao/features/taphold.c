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

#include "taphold.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_DOTC:
        case TD_DOTD:
            return 140;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press_result(uint16_t keycode) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_BSP:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
bool get_tapping_force_hold_result(uint16_t keycode) {
    switch (keycode) {
        case KCA_FUN:
        case KCO_MED:
        case UND_MED:
        case LSFTT_S:
        case LCTLT_D:
        case LALTT_F:
        case LGUIT_V:
        case LSFTT_R:
        case LCTLT_S:
        case LALTT_T:
        case LGUIT_D:
        case RSFTT_L:
        case RCTLT_K:
        case RALTT_J:
        case RGUIT_M:
        case RSFTT_I:
        case RCTLT_E:
        case RALTT_N:
        case RGUIT_H:
            return true;
        default:
            return false;
    }
}

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

#include "dynamic_macro.h"

dyn_macro_t dyn_macro = {
    .recording = false
};

void dyn_macro_play(void) {
    keyrecord_t kr;
    if (dyn_macro.recording) {
        dyn_macro.recording = false;
        kr.event.pressed = true;
        process_dynamic_macro(DYN_REC_STOP, &kr);
    }
    kr.event.pressed = false;
    process_dynamic_macro(DYN_MACRO_PLAY1, &kr);
}

void dyn_macro_toggle(void) {
    keyrecord_t kr;
    if (dyn_macro.recording) {
        dyn_macro.recording = false;
        kr.event.pressed = true;
        process_dynamic_macro(DYN_REC_STOP, &kr);
    } else {
        dyn_macro.recording = true;
        kr.event.pressed = false;
        process_dynamic_macro(DYN_REC_START1, &kr);
    }
}

void dyn_macro_reset(void) {
    if (dyn_macro.recording) {
        keyrecord_t kr;
        kr.event.pressed = true;
        process_dynamic_macro(DYN_REC_STOP, &kr);
        kr.event.pressed = false;
        process_dynamic_macro(DYN_REC_START1, &kr);
        kr.event.pressed = true;
        process_dynamic_macro(DYN_REC_STOP, &kr);
    }
}

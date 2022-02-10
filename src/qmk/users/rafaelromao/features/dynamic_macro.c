#include QMK_KEYBOARD_H

#include "dynamic_macro.h"

dyn_macro_t dyn_macro = {
    .recording = false
};

void dyn_macro_play(void) {
    #ifdef DYNAMIC_MACRO_ENABLE
        keyrecord_t kr;
        if (dyn_macro.recording) {
            dyn_macro.recording = false;
            kr.event.pressed = true;
            process_dynamic_macro(DYN_REC_STOP, &kr);
        }
        kr.event.pressed = false;
        process_dynamic_macro(DYN_MACRO_PLAY1, &kr);
    #endif
}

void dyn_macro_toggle(void) {
    #ifdef DYNAMIC_MACRO_ENABLE
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
    #endif
}

void dyn_macro_reset(void) {
    #ifdef DYNAMIC_MACRO_ENABLE
        if (dyn_macro.recording) {
            keyrecord_t kr;
            kr.event.pressed = true;
            process_dynamic_macro(DYN_REC_STOP, &kr);
            kr.event.pressed = false;
            process_dynamic_macro(DYN_REC_START1, &kr);
            kr.event.pressed = true;
            process_dynamic_macro(DYN_REC_STOP, &kr);
        }
    #endif
}

#include QMK_KEYBOARD_H

#include "dynamic_macro.h"

dyn_macro_t dyn_macro = {.recording = 0};

void dyn_macro_start(uint16_t keycode) {
#ifdef DYNAMIC_MACRO_ENABLE
    keyrecord_t kr;
    kr.event.pressed    = false;
    dyn_macro.recording = keycode;
    process_dynamic_macro(keycode, &kr);
#endif
}

void dyn_macro_stop(void) {
#ifdef DYNAMIC_MACRO_ENABLE
    keyrecord_t kr;
    dyn_macro.recording = 0;
    kr.event.pressed    = true;
    process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_STOP, &kr);
#endif
}

void dyn_macro_play(uint16_t keycode) {
#ifdef DYNAMIC_MACRO_ENABLE
    keyrecord_t kr;
    dyn_macro_stop();
    kr.event.pressed = false;
    process_dynamic_macro(keycode, &kr);
#endif
}

void dyn_macro_toggle(uint16_t keycode) {
#ifdef DYNAMIC_MACRO_ENABLE
    if (dyn_macro.recording != 0) {
        dyn_macro_stop();
    } else {
        dyn_macro_start(keycode);
    }
#endif
}

void dyn_macro_reset(void) {
#ifdef DYNAMIC_MACRO_ENABLE
    if (dyn_macro.recording != 0) {
        dyn_macro_stop();
        dyn_macro_start(dyn_macro.recording);
        dyn_macro_stop();
    }
#endif
}

#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"

typedef struct {
    bool recording;
} dyn_macro_t;

void dyn_macro_play(void);
void dyn_macro_toggle(void);
void dyn_macro_reset(void);

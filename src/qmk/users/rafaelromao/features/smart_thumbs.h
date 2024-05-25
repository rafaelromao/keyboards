#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "os_toggle.h"
#include "macros.h"
#include "accents.h"
#include "dynamic_macro.h"
#include "smart_case.h"

typedef struct {
    uint16_t timer;
} custom_oneshots_t;

void check_oneshot_timeout(void);
void clear_oneshot_shift(void);
bool should_send_ctrl(bool isMacOS, bool isOneShotShift);
void reset_oneshot_timer(void);
void disable_oneshot_layer(void);
void check_repeat_key_timeout(void);
void clear_repeat_key(void);

process_record_result_t process_smart_thumbs(uint16_t keycode, keyrecord_t *record);
void                    activate_repeat_or_magic_key(bool isMagic);
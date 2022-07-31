#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "os_toggle.h"
#include "macros.h"
#include "dynamic_macro.h"
#include "smart_case.h"

typedef struct {
    uint16_t timer;
} oneshot_mods_timer_t;

typedef struct {
    uint16_t timer;
} custom_oneshots_t;

void disable_oneshot_layer(void);
void check_oneshot_timeout(void);
void check_oneshot_mods_timeout(void);
void clear_locked_and_oneshot_mods(void);
bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift);

process_record_result_t process_custom_oneshot(uint16_t keycode, keyrecord_t *record);

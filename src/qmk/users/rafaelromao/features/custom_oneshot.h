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
} custom_oneshots_t;

void disable_oneshots(void);
void check_oneshot_timeout(void);
void clear_locked_and_oneshot_mods(void);
void check_disable_oneshot(uint16_t keycode);
bool should_send_ctrl(bool isMacOS, bool isOneShotShift);

process_record_result_t process_custom_oneshot(uint16_t keycode, keyrecord_t *record);

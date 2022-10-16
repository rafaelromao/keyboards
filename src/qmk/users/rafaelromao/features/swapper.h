#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "os_toggle.h"
#include "custom_oneshot.h"

typedef enum {
  INITIAL_STATE,
  SWAPPING,
  TABBING,
  ZOOMING,
  BROWSING
} swapper_state_t;

process_record_result_t process_swapper(uint16_t keycode, keyrecord_t *record);

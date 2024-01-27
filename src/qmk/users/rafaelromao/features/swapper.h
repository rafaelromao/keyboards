#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "os_toggle.h"
#include "smart_thumbs.h"

typedef enum {
  NONE,
  SWAPPING_START,
  TABBING_START,
  ZOOMING_START,
  BROWSING_START,
  SWAPPING_CONTINUE,
  TABBING_CONTINUE,
  ZOOMING_CONTINUE,
  BROWSING_CONTINUE
} swapper_state_t;

typedef struct {
    swapper_state_t state;
} swapper_t;

process_record_result_t process_swapper(uint16_t keycode, keyrecord_t *record);

#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "os_toggle.h"
#include "secret.h"

typedef struct {
    bool isLeading;
} leader_t;
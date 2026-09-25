#pragma once

#include "rafaelromao.h"

// Select home / word / line (ZMK src/features/select.dtsi). Repeating a
// selection within the adaptive window extends it.
bool process_select(uint16_t keycode, bool pressed);

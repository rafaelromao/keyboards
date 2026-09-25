#pragma once

#include "rafaelromao.h"

// Accented letters through the US-International dead keys (ZMK
// src/features/accents.dtsi), ç, "qu", "ão" and "ões". A pending one-shot
// shift (sticky shift, sentence case) or caps word shifts the letter only,
// never the dead key, which is what the ZMK _s and _c variants do.
bool process_accents(uint16_t keycode, bool pressed);

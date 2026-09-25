#pragma once

#include "rafaelromao.h"

// OS-dependent shortcuts (ZMK OS_MORPH in src/features/shortcuts.dtsi) and
// the OS mode itself: Linux (Omarchy) by default, macOS when detected over
// USB or forced from the toggles layer. The manual choice is a latch that a
// later detection (a replug, a KVM switch) does not undo.
bool shortcuts_is_mac(void);
bool process_shortcuts(uint16_t keycode, bool pressed);

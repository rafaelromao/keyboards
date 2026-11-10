#pragma once

#include "rafaelromao.h"
#include "definitions/process_record.h"

// Vim mode without the host sync (ZMK zmk/features/vim.dtsi minus the
// zmk-vim-mode listener): the NORMAL and CHANGE layers, and the mode the
// keyboard infers on its own from the keys it types. Entered with the
// top-row ring+middle+index chord or its MACROS-layer twin (both also tap
// Esc), left with the other MACROS-layer chord or cancel; num word keeps it.
// Neither is announced to the host: there is no sync to keep in step.
#define VIM_STICKY_TIMEOUT 20000

#ifdef RR_VIM_ENABLE
process_record_result_t process_vim(uint16_t keycode, keyrecord_t *record);
bool                    process_vim_kc(uint16_t keycode, bool pressed);
void                    vim_after_press(uint16_t keycode, keyrecord_t *record);
void                    vim_after_symbol(uint16_t keycode);
void                    vim_modtap_tap(uint8_t tap);
void                    vim_off(void);
void                    vim_housekeeping(void);
#else
static inline process_record_result_t process_vim(uint16_t keycode, keyrecord_t *record) {
    return PROCESS_RECORD_CONTINUE;
}
static inline void vim_after_press(uint16_t keycode, keyrecord_t *record) {}
static inline void vim_after_symbol(uint16_t keycode) {}
static inline void vim_modtap_tap(uint8_t tap) {}
static inline void vim_off(void) {}
static inline void vim_housekeeping(void) {}
// With vim off the vim keycodes are their plain keys.
bool process_vim_kc(uint16_t keycode, bool pressed);
#endif

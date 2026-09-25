#include "rafaelromao.h"
#include "definitions/process_record.h"
#include "features/taphold.h"
#include "features/thumbs.h"
#include "features/smart.h"
#include "features/adaptive.h"
#include "features/macros.h"
#include "features/accents.h"
#include "features/shortcuts.h"
#include "features/select_word.h"
#include "features/vim.h"

// The custom keycodes, whether pressed on a key, emitted by a combo or run
// from another feature through execute_keycode().
bool process_custom(uint16_t keycode, bool pressed) {
    return process_smart(keycode, pressed) || process_accents(keycode, pressed) || process_shortcuts(keycode, pressed) || process_macros(keycode, pressed) || process_select(keycode, pressed) || process_vim_kc(keycode, pressed);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    if (pressed) smart_before_press(keycode, record);

    process_record_result_t result = process_vim(keycode, record);
    if (result == PROCESS_RECORD_CONTINUE) result = process_taphold(keycode, record);
    if (result == PROCESS_RECORD_CONTINUE && keycode >= SAFE_RANGE) {
        process_custom(keycode, pressed);
        result = PROCESS_RECORD_RETURN_FALSE;
    }

    // Keys handled here never reach post_process_record_user.
    if (pressed && result == PROCESS_RECORD_RETURN_FALSE) {
        smart_after_press(keycode, record, true);
        vim_after_press(keycode, record);
    }
    return result != PROCESS_RECORD_RETURN_FALSE;
}

// Native keys: remember what was typed for the adaptive keys, and spend a
// pending one-shot the way ZMK's sticky keys are spent, on the press.
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return;
    uint16_t tap = keycode;
    if (IS_QK_MOD_TAP(keycode)) {
        if (!record->tap.count) return;
        tap = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_LAYER_TAP(keycode)) {
        if (!record->tap.count) return;
        tap = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }
    if (tap <= QK_MODS_MAX) adaptive_track(tap);
    smart_after_press(keycode, record, false);
    vim_after_press(keycode, record);
}

void housekeeping_task_user(void) {
    smart_housekeeping();
    vim_housekeeping();
}

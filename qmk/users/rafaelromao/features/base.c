#include "features/base.h"
#include "features/macros.h"
#include "features/shortcuts.h"

static uint8_t base_modtap_index(uint16_t keycode) {
    switch (keycode) {
        case BASE_HRM_N: return 0;
        case BASE_HRM_E: return 1;
        case BASE_HRM_F: return 2;
        case BASE_HRM_C: return 3;
        default: return UINT8_MAX;
    }
}

static uint8_t base_held_mods[4];

// These tagged BASE mod-taps need to choose their hold modifier from the
// detected OS. Their placeholder Right-Ctrl mods are never sent to the host.
process_record_result_t process_base_modtap(uint16_t keycode, keyrecord_t *record) {
    uint8_t index = base_modtap_index(keycode);
    if (index == UINT8_MAX) return PROCESS_RECORD_CONTINUE;

    if (record->tap.count) {
        if (record->event.pressed) execute_keycode(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
    } else if (record->event.pressed) {
        uint8_t mods = shortcuts_is_mac() ? MOD_BIT(KC_LGUI) : MOD_BIT(KC_LCTL);
        if (index >= 2) mods |= MOD_BIT(KC_LSFT);
        base_held_mods[index] = mods;
        register_mods(mods);
    } else {
        unregister_mods(base_held_mods[index]);
        base_held_mods[index] = 0;
    }
    return PROCESS_RECORD_RETURN_FALSE;
}

#include <assert.h>
#include <stdio.h>

#include "features/base.h"
#include "features/shortcuts.h"

static bool host_mac;
static uint8_t active_mods;
static uint16_t tapped_key;
static unsigned tap_count;

bool shortcuts_is_mac(void) {
    return host_mac;
}

void register_mods(uint8_t mods) {
    active_mods |= mods;
}

void unregister_mods(uint8_t mods) {
    active_mods &= (uint8_t)~mods;
}

void execute_keycode(uint16_t keycode) {
    tapped_key = keycode;
    ++tap_count;
}

static void test_hold(uint16_t keycode, uint8_t expected_mods, bool change_os_before_release) {
    bool initial_os = host_mac;
    keyrecord_t record = {.event.pressed = true, .tap.count = 0};
    assert(process_base_modtap(keycode, &record) == PROCESS_RECORD_RETURN_FALSE);
    assert(active_mods == expected_mods);

    if (change_os_before_release) host_mac = !initial_os;
    record.event.pressed = false;
    assert(process_base_modtap(keycode, &record) == PROCESS_RECORD_RETURN_FALSE);
    assert(active_mods == 0);
    host_mac = initial_os;
}

static void test_tap(uint16_t keycode, uint8_t expected_key) {
    keyrecord_t record = {.event.pressed = true, .tap.count = 1};
    unsigned previous_taps = tap_count;
    assert(process_base_modtap(keycode, &record) == PROCESS_RECORD_RETURN_FALSE);
    assert(tap_count == previous_taps + 1);
    assert(tapped_key == expected_key);
    assert(active_mods == 0);

    record.event.pressed = false;
    assert(process_base_modtap(keycode, &record) == PROCESS_RECORD_RETURN_FALSE);
    assert(tap_count == previous_taps + 1);
}

int main(void) {
    const uint8_t ctrl = MOD_BIT(KC_LCTL);
    const uint8_t command = MOD_BIT(KC_LGUI);
    const uint8_t shift = MOD_BIT(KC_LSFT);

    host_mac = false;
    test_hold(BASE_HRM_N, ctrl, true);
    test_hold(BASE_HRM_E, ctrl, false);
    test_hold(BASE_HRM_F, ctrl | shift, false);
    test_hold(BASE_HRM_C, ctrl | shift, false);

    host_mac = true;
    test_hold(BASE_HRM_N, command, false);
    test_hold(BASE_HRM_E, command, false);
    test_hold(BASE_HRM_F, command | shift, false);
    test_hold(BASE_HRM_C, command | shift, false);

    test_tap(BASE_HRM_N, KC_N);
    test_tap(BASE_HRM_E, KC_E);
    test_tap(BASE_HRM_F, KC_F);
    test_tap(BASE_HRM_C, KC_C);

    keyrecord_t record = {.event.pressed = true, .tap.count = 1};
    assert(process_base_modtap(KC_N, &record) == PROCESS_RECORD_CONTINUE);

    puts("PASS: BASE mod-taps emit the right taps and OS-specific held modifiers");
}

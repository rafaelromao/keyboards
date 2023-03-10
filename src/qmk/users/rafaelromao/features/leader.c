#include QMK_KEYBOARD_H

#include "leader.h"

leader_t leader = {.isLeading = false};

void leader_start_user() {
    leader.isLeading = true;
}

void leader_end_user() {
    leader.isLeading = false;
    process_leader_dictionary();
}

void process_leader_dictionary(void) {
    // Vim - Leader key + V + something

    // Vim - Select Whole Block
    if (leader_sequence_two_keys(KC_V, KC_B)) {
        tap_code(KC_V);
        tap_code(KC_A);
        tap_code16(KC_LCBR);
        register_mods(MOD_LSFT);
        tap_code(KC_V);
        unregister_mods(MOD_LSFT);
        tap_code(KC_DOWN);
    }

    // Process secret leader sequences
    process_leader_dictionary_secret();
}
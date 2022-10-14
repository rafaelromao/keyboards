#include QMK_KEYBOARD_H

#include "leader.h"

leader_t leader = {.isLeading = false};

LEADER_EXTERNS();

void process_leader_dictionary(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Vim - Leader key + V + something

        // Vim - Select Whole Block
        SEQ_TWO_KEYS(KC_V, KC_B) {
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
}

void leader_start(void) {
    leader.isLeading = true;
}

void leader_end(void) {
    leader.isLeading = false;
}
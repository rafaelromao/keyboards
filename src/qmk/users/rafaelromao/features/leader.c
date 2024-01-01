#include QMK_KEYBOARD_H

#include "leader.h"

leader_t leader = {.isLeading = false};

void process_leader_dictionary(void) {
    // Degree sign
    if (leader_sequence_two_keys(TD_DOT, KC_D)) {
        process_macros(MC_DEG, NULL);
        return;
    }
    // Section sign
    if (leader_sequence_two_keys(TD_DOT, KC_S)) {
        process_macros(MC_SEC, NULL);
        return;
    }
    // Male ordinal sign
    if (leader_sequence_two_keys(TD_DOT, KC_A)) {
        process_macros(MC_ORDA, NULL);
        return;
    }
    // Female ordinal sign
    if (leader_sequence_two_keys(TD_DOT, KC_O)) {
        process_macros(MC_ORDO, NULL);
        return;
    }
    // Cancel
    if (leader_sequence_one_key(KC_K)) {
        return;
    }

    // Process secret leader sequences
    process_leader_dictionary_secret();
}

void leader_start_user() {
    leader.isLeading = true;
}

void leader_end_user() {
    leader.isLeading = false;
    process_leader_dictionary();
}

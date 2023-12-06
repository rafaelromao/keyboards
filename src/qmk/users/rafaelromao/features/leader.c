#include QMK_KEYBOARD_H

#include "leader.h"

leader_t leader = {.isLeading = false};

void process_leader_dictionary(void) {
    bool isMacOS = is_macos();

    // Sample Leader Sequence

    // Euro sign
    if (leader_sequence_one_key(KC_E)) {
            if (isMacOS) {
                tap_code16(LSFT(RALT(KC_2)));
            } else {
                tap_code16(LCTL(LALT(KC_5)));
            }
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

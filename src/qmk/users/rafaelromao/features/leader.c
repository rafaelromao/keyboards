#include QMK_KEYBOARD_H

#include "leader.h"

leader_t leader = {.isLeading = false};

void process_leader_dictionary(void) {
    bool isMacOS = is_macos();

    // Sample Leader Sequence

    // Section Sign
    if (leader_sequence_one_key(KC_S)) {
        if (isMacOS) {
            SEND_STRING(SS_LALT(SS_TAP(X_6)));
        } else {
            SEND_STRING(SS_RALT(SS_LSFT(SS_TAP(X_S))));
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

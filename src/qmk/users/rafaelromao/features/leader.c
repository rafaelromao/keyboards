#include QMK_KEYBOARD_H

#include "leader.h"

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

        // Git - Leader key + G + something

        // Git - Add and Commit
        SEQ_TWO_KEYS(KC_G, KC_A) {
            SEND_STRING("git add . && git commit -m \"\"");
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
        }

        // Git - Commit
        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m \"\"");
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
        }

        // Git - New branch
        SEQ_TWO_KEYS(KC_G, KC_B) {
            SEND_STRING("git checkout -b ");
        }

        // Git - New branch
        SEQ_TWO_KEYS(KC_G, KC_O) {
            SEND_STRING("git checkout ");
        }

        // Git - Reset
        SEQ_TWO_KEYS(KC_G, KC_R) {
            SEND_STRING("git reset --hard HEAD~ 1");
        }

        // Git - Set-Upstream
        SEQ_TWO_KEYS(KC_G, KC_U) {
            SEND_STRING("git push --set-upstream origin $(git branch --show-current)");
        }

        // Process secret leader sequences
        process_leader_dictionary_secret();
    }
}

void leader_start(void) {
    leader_start_keymap();
}

void leader_end(void) {
    leader_end_keymap();
}

__attribute__ ((weak)) void leader_start_keymap(void) {}
__attribute__ ((weak)) void leader_end_keymap(void) {}

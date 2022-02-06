/* Copyright 2021 Rafael Romão @rafaelromao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "combos.h"

// Nav

const uint16_t PROGMEM l_nav_sel_combo[] = {KC_PGDN, KC_PGUP, COMBO_END};
const uint16_t PROGMEM l_mou_sel_combo[] = {KC_WH_D, KC_WH_U, COMBO_END};

// Lower

const uint16_t PROGMEM r_low_fun_combo[] = {RAI_BSP, KC_2, KC_3, COMBO_END};

// Qwerty

const uint16_t PROGMEM l_qwe_esc_combo[] = {LOW_SPC, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM l_qwe_sav_combo[] = {LOW_SPC, LSFTT_S, LCTLT_D, COMBO_END};
const uint16_t PROGMEM l_qwe_und_combo[] = {LOW_SPC, KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM r_qwe_tab_combo[] = {RAI_BSP, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM r_qwe_ent_combo[] = {RAI_BSP, RCTLT_K, RSFTT_L, COMBO_END};

const uint16_t PROGMEM l_qwe_sal_combo[] = {LOW_SPC, KCA_FUN, LSFTT_S, COMBO_END};
const uint16_t PROGMEM l_qwe_pas_combo[] = {LOW_SPC, LCTLT_D, LALTT_F, COMBO_END};
const uint16_t PROGMEM l_qwe_cop_combo[] = {LOW_SPC, KC_C, LGUIT_V, COMBO_END};

const uint16_t PROGMEM r_qwe_sal_combo[] = {RAI_BSP, RSFTT_L, UND_MED, COMBO_END};
const uint16_t PROGMEM r_qwe_pas_combo[] = {RAI_BSP, RALTT_J, RCTLT_K, COMBO_END};
const uint16_t PROGMEM r_qwe_cop_combo[] = {RAI_BSP, RGUIT_M, TD_COML, COMBO_END};
const uint16_t PROGMEM r_qwe_und_combo[] = {RAI_BSP, TD_DOTD, KC_UNDS, COMBO_END};

// Romak 1

const uint16_t PROGMEM l_ro1_cop_combo[] = {LOW_SPC, KC_Y, LGUIT_V, COMBO_END};
const uint16_t PROGMEM l_rom_rai_combo[] = {LOW_SPC, KC_X, KC_Y, COMBO_END};
const uint16_t PROGMEM r_ro1_sal_combo[] = {RAI_BSP, RSFTT_L, KCC_MED, COMBO_END};
const uint16_t PROGMEM r_ro1_pas_combo[] = {RAI_BSP, RALTT_N, RCTLT_K, COMBO_END};

// Romak 2

const uint16_t PROGMEM l_ro2_pas_combo[] = {LOW_SPC, LCTLT_D, LA_UNDS, COMBO_END};
const uint16_t PROGMEM l_rom_sal_combo[] = {LOW_SPC, KCF_FUN, LSFTT_S, COMBO_END};
const uint16_t PROGMEM r_ro2_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_L, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[] = {RAI_BSP, RALTT_N, RCTLT_A, COMBO_END};

// Romak 3

const uint16_t PROGMEM l_ro3_pas_combo[] = {LOW_SPC, LC_UNDS, LALTT_T, COMBO_END};
const uint16_t PROGMEM l_rom_cop_combo[] = {LOW_SPC, KC_Y, LGUIT_D, COMBO_END};

// Romak 4

const uint16_t PROGMEM l_ro4_esc_combo[] = {LOW_SPC, KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_S, LCTLT_E, COMBO_END};
const uint16_t PROGMEM l_rom_pas_combo[] = {LOW_SPC, LCTLT_E, LALTT_T, COMBO_END};
const uint16_t PROGMEM l_rom_und_combo[] = {LOW_SPC, KC_B, KC_X, COMBO_END};

// Romak 5

const uint16_t PROGMEM r_rom_tab_combo[] = {RAI_BSP, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_O, COMBO_END};
const uint16_t PROGMEM r_rom_sal_combo[] = {RAI_BSP, RSFTT_O, KCC_MED, COMBO_END};

// Romak 6

const uint16_t PROGMEM l_rom_esc_combo[] = {LOW_SPC, KC_R, KC_Q, COMBO_END};
const uint16_t PROGMEM r_rom_und_combo[] = {LOW_SPC, TD_DOTD, KC_W, COMBO_END};

// Layer toggle

const uint16_t PROGMEM l_qwe_rai_combo[] = {LOW_SPC, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM l_me1_tog_combo[] = {LOW_SPC, KC_Z, COMBO_END};
const uint16_t PROGMEM l_me2_tog_combo[] = {LOW_SPC, KC_B, COMBO_END};
const uint16_t PROGMEM l_rai_tog_combo[] = {RAI_BSP, KC_EQL, KC_EXLM, COMBO_END};
const uint16_t PROGMEM r_qwe_lo1_combo[] = {RAI_BSP, TD_COML, TD_DOTD, COMBO_END};
const uint16_t PROGMEM r_qwe_lo2_combo[] = {RAI_BSP, TD_SCLE, COMBO_END};
const uint16_t PROGMEM r_rom_low_combo[] = {RAI_BSP, KC_W, COMBO_END};
const uint16_t PROGMEM r_mou_nav_combo[] = {KC_HOME, KC_END, COMBO_END};
const uint16_t PROGMEM r_nav_tog_combo[] = {RAI_BSP, KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM r_mou_tog_combo[] = {RAI_BSP, KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM r_low_tog_combo[] = {RAI_BSP, KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM r_fun_tog_combo[] = {KC_SPC, KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM r_med_tog_combo[] = {KC_SPC, KC_VOLD, KC_VOLU, COMBO_END};

// Reset

const uint16_t PROGMEM qwe_reset_combo[] = {KC_Q, KC_P, KC_Z, TD_SCLE, COMBO_END};
const uint16_t PROGMEM rom_reset_combo[] = {TD_UNDS, KC_B, KC_W, TD_SCLE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(l_nav_sel_combo, SS_SELW),
  COMBO(l_mou_sel_combo, SS_SELW),

  COMBO(r_low_fun_combo, TG_FUN),

  COMBO(l_qwe_esc_combo, KC_ESC),
  COMBO(l_qwe_sav_combo, CB_SAVE),
  COMBO(l_qwe_und_combo, CB_UNDO),
  COMBO(r_qwe_tab_combo, KC_TAB),
  COMBO(r_qwe_ent_combo, KC_ENT),

  COMBO(l_qwe_sal_combo, CB_SELC),
  COMBO(l_qwe_pas_combo, CB_PAST),
  COMBO(l_qwe_cop_combo, CB_COPY),

  COMBO(r_qwe_sal_combo, CB_SELC),
  COMBO(r_qwe_pas_combo, CB_PAST),
  COMBO(r_qwe_cop_combo, CB_COPY),
  COMBO(r_qwe_und_combo, CB_UNDO),

  COMBO(l_ro1_cop_combo, CB_COPY),
  COMBO(l_rom_rai_combo, TT_RAI),
  COMBO(r_ro1_sal_combo, CB_SELC),
  COMBO(r_ro1_pas_combo, CB_PAST),

  COMBO(l_ro2_pas_combo, CB_PAST),
  COMBO(l_rom_sal_combo, CB_SELC),
  COMBO(r_ro2_ent_combo, KC_ENT),
  COMBO(r_rom_pas_combo, CB_PAST),

  COMBO(l_ro3_pas_combo, CB_PAST),
  COMBO(l_rom_cop_combo, CB_COPY),

  COMBO(l_ro4_esc_combo, KC_ESC),
  COMBO(l_rom_sav_combo, CB_SAVE),
  COMBO(l_rom_pas_combo, CB_PAST),
  COMBO(l_rom_und_combo, CB_UNDO),

  COMBO(r_rom_tab_combo, KC_TAB),
  COMBO(r_rom_ent_combo, KC_ENT),
  COMBO(r_rom_sal_combo, CB_SELC),

  COMBO(l_rom_esc_combo, KC_ESC),
  COMBO(r_rom_und_combo, CB_UNDO),

  COMBO(l_qwe_rai_combo, TT_RAI),
  COMBO(r_qwe_lo1_combo, TT_LOW),
  COMBO(r_qwe_lo2_combo, OS_LOW),
  COMBO(r_rom_low_combo, OS_LOW),
  COMBO(r_mou_nav_combo, TO_NAV),
  COMBO(l_rai_tog_combo, TG_RAI),
  COMBO(r_nav_tog_combo, TG_NAV),
  COMBO(r_mou_tog_combo, TG_MOU),
  COMBO(r_low_tog_combo, TG_LOW),
  COMBO(r_fun_tog_combo, TG_FUN),
  COMBO(r_med_tog_combo, TG_MED),
  COMBO(l_me1_tog_combo, OS_MED),
  COMBO(l_me2_tog_combo, OS_MED),

  COMBO(qwe_reset_combo, RESET),
  COMBO(rom_reset_combo, RESET),
};

extern os_t os;

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    uint16_t key;
    uint8_t idx = 0;
    bool combo_must_tap = false;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                combo_must_tap = true;
                break;
            default:
                combo_must_tap = false;
                break;
        }
        if (!combo_must_tap) {
            return false;
        }
        idx += 1;
    }
    return combo_must_tap;
}

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (keycode) {

        case CB_SELC:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("a"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_SAVE:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("s"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_UNDO:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("z"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_COPY:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("c"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_PAST:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("v"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

    }

    return PROCESS_RECORD_CONTINUE;
}

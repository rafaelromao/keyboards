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

const uint16_t PROGMEM l_low_esc_combo[] = {TD_PARB, KC_RPRN, COMBO_END};
const uint16_t PROGMEM l_low_sal_combo[] = {SS_BTIC, SS_DQUO, COMBO_END};
const uint16_t PROGMEM l_low_sav_combo[] = {SS_DQUO, SS_SQUO, COMBO_END};
const uint16_t PROGMEM l_low_pas_combo[] = {SS_SQUO, KC_AMPR, COMBO_END};
const uint16_t PROGMEM l_low_und_combo[] = {KC_AT, KC_LBRC, COMBO_END};
const uint16_t PROGMEM l_low_rai_combo[] = {TD_SQRB, KC_RBRC, COMBO_END};
const uint16_t PROGMEM l_low_cop_combo[] = {KC_RBRC, KC_QUES, COMBO_END};

const uint16_t PROGMEM l_rai_tab_combo[] = {TD_CURB, KC_RCBR, COMBO_END};
const uint16_t PROGMEM l_rai_sal_combo[] = {KC_EXLM, KC_PERC, COMBO_END};
const uint16_t PROGMEM l_rai_ent_combo[] = {KC_EQL, KC_EXLM, COMBO_END};
const uint16_t PROGMEM l_rai_pas_combo[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM l_rai_und_combo[] = {KC_GT, KC_COLN, COMBO_END};
const uint16_t PROGMEM l_rai_low_combo[] = {TD_ANGB, KC_GT, COMBO_END};
const uint16_t PROGMEM l_rai_cop_combo[] = {KC_SLSH, KC_LT, COMBO_END};

const uint16_t PROGMEM l_qwe_esc_combo[] = {LOW_SPC, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM l_qwe_sav_combo[] = {LOW_SPC, LSFTT_S, LCTLT_D, COMBO_END};
const uint16_t PROGMEM r_qwe_tab_combo[] = {RAI_BSP, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM r_qwe_ent_combo[] = {RAI_BSP, RCTLT_K, RSFTT_L, COMBO_END};

const uint16_t PROGMEM l_qwe_sal_combo[] = {LOW_SPC, KCA_FUN, LSFTT_S, COMBO_END};
const uint16_t PROGMEM l_qwe_pas_combo[] = {LOW_SPC, LCTLT_D, LALTT_F, COMBO_END};
const uint16_t PROGMEM l_qwe_cop_combo[] = {LOW_SPC, KC_C, LGUIT_V, COMBO_END};

const uint16_t PROGMEM r_qwe_sal_combo[] = {RAI_BSP, RSFTT_L, UND_MED, COMBO_END};
const uint16_t PROGMEM r_qwe_pas_combo[] = {RAI_BSP, RALTT_J, RCTLT_K, COMBO_END};
const uint16_t PROGMEM r_qwe_cop_combo[] = {RAI_BSP, RGUIT_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM l_bas_und_combo[] = {LOW_SPC, KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM r_bas_und_combo[] = {RAI_BSP, TD_DOTD, TD_SCLE, COMBO_END};

const uint16_t PROGMEM l_col_esc_combo[] = {LOW_SPC, KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM l_col_sav_combo[] = {LOW_SPC, LSFTT_R, LCTLT_S, COMBO_END};
const uint16_t PROGMEM r_col_tab_combo[] = {RAI_BSP, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM r_col_ent_combo[] = {RAI_BSP, RCTLT_E, RSFTT_I, COMBO_END};

const uint16_t PROGMEM l_col_sal_combo[] = {LOW_SPC, KCA_FUN, LSFTT_R, COMBO_END};
const uint16_t PROGMEM l_col_pas_combo[] = {LOW_SPC, LCTLT_S, LALTT_T, COMBO_END};
const uint16_t PROGMEM l_col_cop_combo[] = {LOW_SPC, KC_C, LGUIT_D, COMBO_END};

const uint16_t PROGMEM r_col_sal_combo[] = {RAI_BSP, RSFTT_I, KCO_MED, COMBO_END};
const uint16_t PROGMEM r_col_pas_combo[] = {RAI_BSP, RALTT_N, RCTLT_E, COMBO_END};
const uint16_t PROGMEM r_col_cop_combo[] = {RAI_BSP, RGUIT_H, KC_COMM, COMBO_END};

const uint16_t PROGMEM l_bas_rai_combo[] = {LOW_SPC, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM r_bas_lo1_combo[] = {RAI_BSP, KC_COMM, TD_DOTD, COMBO_END};
const uint16_t PROGMEM r_bas_lo2_combo[] = {RAI_BSP, TD_SCLE, COMBO_END};
const uint16_t PROGMEM r_low_fun_combo[] = {RAI_BSP, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM r_mou_nav_combo[] = {KC_HOME, KC_END, COMBO_END};

const uint16_t PROGMEM l_rai_tog_combo[] = {LOW_SPC, KC_CIRC, KC_TILD, COMBO_END};
const uint16_t PROGMEM l_med_tog_combo[] = {LOW_SPC, KC_Z, COMBO_END};
const uint16_t PROGMEM r_nav_tog_combo[] = {RAI_BSP, KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM r_mou_tog_combo[] = {RAI_BSP, KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM r_low_tog_combo[] = {RAI_BSP, KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM r_fun_tog_combo[] = {KC_SPC, KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM r_med_tog_combo[] = {KC_SPC, KC_VOLD, KC_VOLU, COMBO_END};

const uint16_t PROGMEM reset_combo[] = {KC_Q, KC_P, KC_Z, TD_SCLE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(l_low_esc_combo, KC_ESC),
  COMBO(l_low_sal_combo, CB_SELC),
  COMBO(l_low_sav_combo, CB_SAVE),
  COMBO(l_low_pas_combo, CB_PAST),
  COMBO(l_low_und_combo, CB_UNDO),
  COMBO(l_low_rai_combo, TT_RAI),
  COMBO(l_low_cop_combo, CB_COPY),

  COMBO(l_rai_tab_combo, KC_TAB),
  COMBO(l_rai_sal_combo, CB_SELC),
  COMBO(l_rai_ent_combo, KC_ENT),
  COMBO(l_rai_pas_combo, CB_PAST),
  COMBO(l_rai_und_combo, CB_UNDO),
  COMBO(l_rai_low_combo, TT_LOW),
  COMBO(l_rai_cop_combo, CB_COPY),

  COMBO(l_qwe_esc_combo, KC_ESC),
  COMBO(l_qwe_sav_combo, CB_SAVE),
  COMBO(r_qwe_tab_combo, KC_TAB),
  COMBO(r_qwe_ent_combo, KC_ENT),

  COMBO(l_qwe_sal_combo, CB_SELC),
  COMBO(l_qwe_pas_combo, CB_PAST),
  COMBO(l_qwe_cop_combo, CB_COPY),

  COMBO(r_qwe_sal_combo, CB_SELC),
  COMBO(r_qwe_pas_combo, CB_PAST),
  COMBO(r_qwe_cop_combo, CB_COPY),

  COMBO(l_bas_und_combo, CB_UNDO),
  COMBO(r_bas_und_combo, CB_UNDO),

  COMBO(l_col_esc_combo, KC_ESC),
  COMBO(l_col_sav_combo, CB_SAVE),
  COMBO(r_col_tab_combo, KC_TAB),
  COMBO(r_col_ent_combo, KC_ENT),

  COMBO(l_col_sal_combo, CB_SELC),
  COMBO(l_col_pas_combo, CB_PAST),
  COMBO(l_col_cop_combo, CB_COPY),

  COMBO(r_col_sal_combo, CB_SELC),
  COMBO(r_col_pas_combo, CB_PAST),
  COMBO(r_col_cop_combo, CB_COPY),

  COMBO(l_bas_rai_combo, TT_RAI),
  COMBO(r_bas_lo1_combo, TT_LOW),
  COMBO(r_bas_lo2_combo, OS_LOW),
  COMBO(r_low_fun_combo, TG_FUN),
  COMBO(r_mou_nav_combo, TO_NAV),

  COMBO(l_rai_tog_combo, TG_RAI),
  COMBO(r_nav_tog_combo, TG_NAV),
  COMBO(r_mou_tog_combo, TG_MOU),
  COMBO(r_low_tog_combo, TG_LOW),
  COMBO(r_fun_tog_combo, TG_FUN),
  COMBO(r_med_tog_combo, TG_MED),
  COMBO(l_med_tog_combo, OS_MED),

  COMBO(reset_combo, RESET),
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

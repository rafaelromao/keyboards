#include QMK_KEYBOARD_H

#include "combos.h"

// Numpad

const uint16_t PROGMEM l_num_esc_combo[] = {LOW_SPC, KC_F9, KC_F8, COMBO_END};
const uint16_t PROGMEM l_num_sav_combo[] = {LOW_SPC, SF_F6, CT_F5, COMBO_END};
const uint16_t PROGMEM r_num_ent_combo[] = {RAI_BSP, CT_5, SF_6, COMBO_END};

// Lower

const uint16_t PROGMEM l_low_par_combo[] = {TD_OPAR, TD_CPAR, COMBO_END};
const uint16_t PROGMEM l_low_hom_combo[] = {TD_SQRB, KC_RBRC, COMBO_END};
const uint16_t PROGMEM r_low_tab_combo[] = {RAI_BSP, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_low_ent_combo[] = {RAI_BSP, KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM r_low_end_combo[] = {KC_2, KC_3, COMBO_END};

// Raise

const uint16_t PROGMEM l_rai_hom_combo[] = {KC_F3, KC_F2, COMBO_END};
const uint16_t PROGMEM r_rai_end_combo[] = {TD_ANGB, KC_GT, COMBO_END};

// Media

const uint16_t PROGMEM r_med_pas_combo[] = {KC_MUTE, KC_VOLD, COMBO_END};
const uint16_t PROGMEM r_med_del_combo[] = {KC_VOLD, KC_VOLU, COMBO_END};
const uint16_t PROGMEM r_med_hom_combo[] = {KC_MPLY, KC_MPRV, COMBO_END};
const uint16_t PROGMEM r_med_end_combo[] = {KC_MPRV, KC_MNXT, COMBO_END};
const uint16_t PROGMEM r_med_ent_combo[] = {KC_ENT, KC_TAB, COMBO_END};

// N-Grams

const uint16_t PROGMEM l_ng_i_combo[]    = {MC_TH, MC_SQUO, COMBO_END};
const uint16_t PROGMEM l_ng_the_combo[]  = {MC_SQUO, MC_WH, COMBO_END};
const uint16_t PROGMEM l_ng_eu_combo[]   = {MC_CH, MC_NH, COMBO_END};
const uint16_t PROGMEM l_ng_nt_combo[]   = {MC_NH, MC_SH, COMBO_END};
const uint16_t PROGMEM r_ng_ao_combo[]   = {MC_SQ_A, MC_TL_A, COMBO_END};
const uint16_t PROGMEM r_ng_cao_combo[]  = {MC_CR_A, MC_SQ_A, MC_TL_A, COMBO_END};
const uint16_t PROGMEM r_ng_em_combo[]   = {MC_CR_E, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_ng_oes_combo[]  = {MC_SQ_E, MC_SQ_I, COMBO_END};
const uint16_t PROGMEM r_ng_coes_combo[] = {MC_CR_E, MC_SQ_E, MC_SQ_I, COMBO_END};

// Base

const uint16_t PROGMEM l_rom_esc_combo[] = {LOW_SPC, KC_Q, KC_U, COMBO_END};
const uint16_t PROGMEM l_rom_sal_combo[] = {LOW_SPC, KCP_MAC, LSFTT_S, COMBO_END};
const uint16_t PROGMEM l_rom_rai_combo[] = {LOW_SPC, LSFTT_S, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_S, LCTLT_E, COMBO_END};
const uint16_t PROGMEM l_rom_usc_combo[] = {KC_X, KC_Y, COMBO_END};
const uint16_t PROGMEM l_rom_pas_combo[] = {LOW_SPC, LCTLT_E, LALTT_D, COMBO_END};
const uint16_t PROGMEM l_rom_und_combo[] = {LOW_SPC, KC_B, KC_X, COMBO_END};
const uint16_t PROGMEM l_rom_cop_combo[] = {LOW_SPC, KC_U, LGUIT_T, COMBO_END};

const uint16_t PROGMEM r_rom_tab_combo[] = {RAI_BSP, KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[] = {RAI_BSP, RALTT_N, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_R, COMBO_END};
const uint16_t PROGMEM r_rom_low_combo[] = {RAI_BSP, RSFTT_R, COMBO_END};
const uint16_t PROGMEM r_rom_ful_combo[] = {RAI_BSP, RSFTT_R, KCC_MAC, COMBO_END};
const uint16_t PROGMEM r_rom_cop_combo[] = {RAI_BSP, RGUIT_M, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_sco_combo[] = {TD_COMM, TD_DOTD, COMBO_END};
const uint16_t PROGMEM r_rom_fin_combo[] = {RAI_BSP, TD_DOTD, KC_W, COMBO_END};

// Reset

const uint16_t PROGMEM rom_reset_combo[] = {KCP_MAC, KC_B, KCC_MAC, KC_W, COMBO_END};

// Secret

const uint16_t PROGMEM secret_1_combo[] = {SEC_1, SEC_2, SEC_3, SEC_4, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(l_num_esc_combo, KC_ESC),  COMBO(l_num_sav_combo, MC_SAVE), COMBO(r_num_ent_combo, KC_ENT),
    COMBO(l_low_par_combo, TD_PARN), COMBO(r_low_tab_combo, KC_TAB),  COMBO(r_low_ent_combo, KC_ENT),
    COMBO(l_ng_the_combo, MC_THE),   COMBO(l_ng_i_combo, MC_I),       COMBO(l_ng_nt_combo, MC_NT),
    COMBO(l_ng_eu_combo, MC_EU),     COMBO(r_ng_ao_combo, MC_AO),     COMBO(r_ng_cao_combo, MC_CAO),
    COMBO(r_ng_oes_combo, MC_OES),   COMBO(r_ng_coes_combo, MC_COES), COMBO(r_ng_em_combo, MC_EM),
    COMBO(r_rom_cop_combo, MC_COPY), COMBO(r_rom_sco_combo, TD_SCLE), COMBO(l_rom_usc_combo, KC_UNDS),
    COMBO(l_rom_sal_combo, MC_SELC), COMBO(r_rom_pas_combo, MC_PAST), COMBO(l_rom_rai_combo, MO_RAI),
    COMBO(l_rom_sav_combo, MC_SAVE), COMBO(l_rom_pas_combo, MC_PAST), COMBO(l_rom_esc_combo, KC_ESC),
    COMBO(r_rom_fin_combo, MC_FIND), COMBO(l_rom_und_combo, MC_UNDO), COMBO(l_rom_cop_combo, MC_COPY),
    COMBO(r_rom_tab_combo, KC_TAB),  COMBO(r_rom_low_combo, MO_LOW),  COMBO(r_rom_ent_combo, KC_ENT),
    COMBO(r_rom_ful_combo, MC_FULL), COMBO(l_low_hom_combo, KC_HOME), COMBO(r_low_end_combo, KC_END),
    COMBO(l_rai_hom_combo, KC_HOME), COMBO(r_med_hom_combo, KC_HOME), COMBO(r_med_end_combo, KC_END),
    COMBO(r_med_del_combo, KC_DEL),  COMBO(r_med_ent_combo, TD_EENT), COMBO(r_med_pas_combo, MC_PAST),
    COMBO(r_rai_end_combo, KC_END),  COMBO(rom_reset_combo, QK_BOOT), COMBO(secret_1_combo, MC_SECRET_1),
};
#include QMK_KEYBOARD_H

#include "combos.h"

// Numpad

const uint16_t PROGMEM l_num_esc_combo[] = {KC_F9, KC_F8, COMBO_END};
const uint16_t PROGMEM l_num_sav_combo[] = {KC_SPC, SF_F6, CT_F5, COMBO_END};
const uint16_t PROGMEM r_num_ent_combo[] = {RAI_SPC, CT_5, SF_6, COMBO_END};
const uint16_t PROGMEM r_num_bsp_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_num_tab_combo[] = {RAI_SPC, KC_8, KC_9, COMBO_END};

// Lower

const uint16_t PROGMEM l_low_par_combo[] = {TD_OPAR, TD_CPAR, COMBO_END};
const uint16_t PROGMEM r_low_ent_combo[] = {RAI_SPC, KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM r_low_sco_combo[] = {KC_2, KC_3, COMBO_END};

// Raise

const uint16_t PROGMEM r_rai_cur_combo[]  = {TD_COLN, TD_LCRB, TD_RCRB, COMBO_END};
const uint16_t PROGMEM r_rai_lt_combo[]   = {TD_SLSH, KC_ASTR, COMBO_END};
const uint16_t PROGMEM r_rai_gt_combo[]   = {KC_ASTR, TD_NOT, COMBO_END};
const uint16_t PROGMEM r_rai_ltgt_combo[] = {TD_SLSH, KC_ASTR, TD_NOT, COMBO_END};
const uint16_t PROGMEM r_rai_sar_combo[]  = {KC_MINS, TD_PLUS, COMBO_END};
const uint16_t PROGMEM r_rai_deq_combo[]  = {TD_PLUS, TD_EQL, COMBO_END};
const uint16_t PROGMEM r_rai_neq_combo[]  = {KC_MINS, TD_PLUS, TD_EQL, COMBO_END};
const uint16_t PROGMEM r_rai_bsp_combo[]  = {TD_LCRB, TD_RCRB, COMBO_END};

// Navigation

const uint16_t PROGMEM l_nav_esc_combo[] = {MC_ESC, MC_SAVE, COMBO_END};
const uint16_t PROGMEM r_nav_ent_combo[] = {KC_SPC, KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM r_nav_bsp_combo[] = {KC_PGDN, KC_PGUP, COMBO_END};

// Media

const uint16_t PROGMEM r_med_ent_combo[] = {KC_ENT, KC_TAB, COMBO_END};

// Accents

const uint16_t PROGMEM l_acc_esc_combo[]  = {KC_J, KC_V, COMBO_END};
const uint16_t PROGMEM r_acc_squo_combo[] = {MC_TL_A, MC_SQ_A, COMBO_END};
const uint16_t PROGMEM r_acc_ae_combo[]   = {MC_CR_A, MC_CR_O, COMBO_END};
const uint16_t PROGMEM r_acc_ao_combo[]   = {MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_acc_oe_combo[]   = {MC_CR_O, MC_CR_E, COMBO_END};
const uint16_t PROGMEM r_acc_cao_combo[]  = {MC_TL_A, MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_acc_coes_combo[] = {MC_CR_A, MC_CR_O, MC_CR_E, COMBO_END};
const uint16_t PROGMEM r_acc_bsp_combo[]  = {MC_SQ_O, MC_SQ_U, COMBO_END};

// Macros

const uint16_t PROGMEM r_mac_z0r_combo[] = {MC_MODM, SF_MODP, COMBO_END};
const uint16_t PROGMEM r_mac_clo_combo[] = {MC_SWLE, MC_SWRI, COMBO_END};

// Base

const uint16_t PROGMEM l_rom_k_combo[]   = {KC_C, LALTT_P, COMBO_END};
const uint16_t PROGMEM l_rom_q_combo[]   = {RALTT_F, KC_C, LALTT_P, COMBO_END};
const uint16_t PROGMEM l_rom_esc_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM l_rom_esv_combo[] = {LOW_SPC, KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM l_rom_und_combo[] = {LOW_SPC, RALTT_F, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_N, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_usc_combo[] = {RALTT_F, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_ful_combo[] = {LOW_SPC, LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_fin_combo[] = {LOW_SPC, KC_C, LALTT_P, COMBO_END};

const uint16_t PROGMEM r_rom_v_combo[]   = {KC_L, KC_O, COMBO_END};
const uint16_t PROGMEM r_rom_y_combo[]   = {RGUIT_R, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_p_combo[]   = {LALTT_H, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_x_combo[]   = {RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_d_combo[]   = {RGUIT_R, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_oes_combo[] = {RAI_ACT, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_soe_combo[] = {RAI_ACT, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_cop_combo[] = {RAI_ACT, RGUIT_R, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_scp_combo[] = {RAI_ACT, RGUIT_R, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[] = {RAI_ACT, LALTT_H, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_spa_combo[] = {RAI_ACT, LALTT_H, TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[] = {RAI_ACT, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_bsp_combo[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_tab_combo[] = {RAI_ACT, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_sal_combo[] = {RAI_ACT, TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_sco_combo[] = {TD_COMM, TD_DOT, COMBO_END};
#ifndef SAVE_MEMORY
const uint16_t PROGMEM r_rom_epa_combo[] = {LALTT_H, TD_COMM, TD_DOT, COMBO_END};
#endif

// Secret

const uint16_t PROGMEM secret_1_combo[] = {SEC_1, SEC_2, SEC_3, SEC_4, COMBO_END};

combo_t key_combos[] = {
    COMBO(l_rom_q_combo, KC_Q),       COMBO(r_rom_v_combo, KC_V),       COMBO(r_rom_y_combo, KC_Y),
    COMBO(l_rom_k_combo, KC_K),       COMBO(r_rom_d_combo, KC_D),       COMBO(r_rom_x_combo, KC_X),
    COMBO(r_rom_p_combo, KC_P),       COMBO(l_acc_esc_combo, MC_ESCC),  COMBO(l_nav_esc_combo, MC_ESCC),
    COMBO(l_num_esc_combo, MC_ESCC),  COMBO(r_nav_ent_combo, KC_ENT),   COMBO(l_rom_esv_combo, MC_ESAV),
    COMBO(l_num_sav_combo, MC_SAVE),  COMBO(r_nav_bsp_combo, KC_BSPC),  COMBO(r_rai_bsp_combo, KC_BSPC),
    COMBO(r_num_bsp_combo, KC_BSPC),  COMBO(r_num_tab_combo, KC_TAB),   COMBO(r_acc_bsp_combo, KC_BSPC),
    COMBO(r_num_ent_combo, KC_ENT),   COMBO(r_acc_squo_combo, MC_SQUO), COMBO(l_low_par_combo, TD_PARN),
    COMBO(r_low_ent_combo, KC_ENT),   COMBO(r_acc_ae_combo, MC_AE),     COMBO(r_acc_ao_combo, MC_AO),
    COMBO(r_acc_cao_combo, MC_CAO),   COMBO(r_acc_oe_combo, MC_OE),     COMBO(r_acc_coes_combo, MC_COES),
    COMBO(r_mac_z0r_combo, MC_Z0R),   COMBO(r_mac_clo_combo, MC_CLOS),  COMBO(r_rom_cop_combo, MC_COPY),
    COMBO(r_rom_scp_combo, MC_SCOP),  COMBO(r_rom_sco_combo, TD_SCLE),  COMBO(r_low_sco_combo, TD_SCLE),
    COMBO(l_rom_usc_combo, KC_UNDS),  COMBO(l_rom_ful_combo, MC_FULL),
#ifndef SAVE_MEMORY
    COMBO(r_rom_epa_combo, TD_EPA),
#endif
    COMBO(r_rom_pas_combo, MC_PAST),  COMBO(r_rom_spa_combo, MC_SPAS),  COMBO(l_rom_sav_combo, MC_SAVE),
    COMBO(l_rom_esc_combo, MC_ESCC),  COMBO(l_rom_und_combo, MC_UNDO),  COMBO(l_rom_fin_combo, MC_FIND),
    COMBO(r_rom_oes_combo, MC_OESC),  COMBO(r_rom_soe_combo, MC_SOES),  COMBO(r_rom_bsp_combo, KC_BSPC),
    COMBO(r_rom_tab_combo, KC_TAB),   COMBO(r_rom_ent_combo, KC_ENT),   COMBO(r_rom_sal_combo, MC_SELC),
    COMBO(r_rai_sar_combo, TD_SARR),  COMBO(r_rai_deq_combo, MC_DEQ),   COMBO(r_rai_neq_combo, MC_NEQ),
    COMBO(r_rai_ltgt_combo, MC_LTGT), COMBO(r_rai_lt_combo, TD_LT),     COMBO(r_rai_gt_combo, TD_GT),
    COMBO(r_rai_cur_combo, MC_CUR),   COMBO(r_med_ent_combo, TD_EENT),  COMBO(secret_1_combo, MC_SECRET_1)};
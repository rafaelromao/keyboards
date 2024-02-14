#include QMK_KEYBOARD_H

#include "combos.h"

// Alpha 1

const uint16_t PROGMEM l_rom_k_combo[]   = {KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM l_rom_w_combo[]   = {LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_v_combo[]   = {KC_C, LALTT_P, COMBO_END};
const uint16_t PROGMEM l_rom_q_combo[]   = {LSFTT_N, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_num_combo[] = {RALTT_F, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_esc_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM l_rom_esv_combo[] = {LOW_SPC, KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM l_rom_und_combo[] = {LOW_SPC, RALTT_F, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_N, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_ful_combo[] = {LOW_SPC, LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_fin_combo[] = {LOW_SPC, KC_C, LALTT_P, COMBO_END};
const uint16_t PROGMEM l_rom_ent_combo[] = {LSFTT_N, LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_tab_combo[] = {KC_B, KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM l_rom_del_combo[] = {RALTT_F, KC_C, LALTT_P, COMBO_END};

const uint16_t PROGMEM r_rom_x_combo[]    = {KC_L, KC_O, COMBO_END};
const uint16_t PROGMEM r_rom_z_combo[]    = {RGUIT_R, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_j_combo[]    = {RALTT_H, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_y_combo[]    = {RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_d_combo[]    = {KC_L, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_p_combo[]    = {RGUIT_R, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_cop_combo[]  = {RAI_A2, RGUIT_R, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[]  = {RAI_A2, RALTT_H, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_sal_combo[]  = {RAI_A2, TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_scp_combo[]  = {RAI_A2, RGUIT_R, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_spa_combo[]  = {RAI_A2, RALTT_H, TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[]  = {RAI_A2, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_bsp_combo[]  = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_tab_combo[]  = {RAI_A2, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_sco_combo[]  = {TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_sent_combo[] = {RALTT_H, TD_COMM, TD_DOT, COMBO_END};

// Alpha 2

const uint16_t PROGMEM l_acc_esc_combo[]  = {KC_Q, MC_QU, COMBO_END};
const uint16_t PROGMEM l_acc_und_combo[]  = {KC_J, MC_SQ_C, COMBO_END};
const uint16_t PROGMEM l_acc_dqo_combo[]  = {MC_QU, KC_K, COMBO_END};
const uint16_t PROGMEM l_acc_lpa_combo[]  = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM l_acc_sqo_combo[]  = {KC_X, KC_W, COMBO_END};
const uint16_t PROGMEM l_acc_ques_combo[] = {MC_SQ_C, KC_V, COMBO_END};
const uint16_t PROGMEM l_acc_ent_combo[]  = {KC_Z, KC_X, KC_W, COMBO_END};
const uint16_t PROGMEM l_acc_tab_combo[]  = {KC_Q, MC_QU, KC_K, COMBO_END};

const uint16_t PROGMEM r_acc_bsp_combo[]  = {MC_SQ_O, MC_SQ_U, COMBO_END};
const uint16_t PROGMEM r_acc_tab_combo[]  = {RAI_A2, MC_SQ_O, MC_SQ_U, COMBO_END};
const uint16_t PROGMEM r_acc_ent_combo[]  = {RAI_A2, MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_acc_col_combo[]  = {MC_CR_O, MC_SQ_O, COMBO_END};
const uint16_t PROGMEM r_acc_min_combo[]  = {MC_TL_A, MC_SQ_A, COMBO_END};
const uint16_t PROGMEM r_acc_excl_combo[] = {MC_TL_O, MC_CR_A, COMBO_END};
const uint16_t PROGMEM r_acc_rpa_combo[]  = {MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_acc_agr_combo[]  = {MC_CR_A, MC_CR_E, COMBO_END};

// Numpad

const uint16_t PROGMEM l_num_f10_combo[] = {KC_F2, AL_F1, COMBO_END};
const uint16_t PROGMEM l_num_f11_combo[] = {CT_F5, GU_F4, COMBO_END};
const uint16_t PROGMEM l_num_esc_combo[] = {KC_F9, KC_F8, COMBO_END};
const uint16_t PROGMEM l_num_sav_combo[] = {KC_SPC, SF_F6, CT_F5, COMBO_END};
const uint16_t PROGMEM l_num_tab_combo[] = {KC_F9, KC_F8, KC_F9, COMBO_END};
const uint16_t PROGMEM l_num_num_combo[] = {AL_F3, KC_F2, COMBO_END};
const uint16_t PROGMEM l_num_ent_combo[] = {SF_F6, CT_F5, GU_F4, COMBO_END};

const uint16_t PROGMEM r_num_ent_combo[]  = {RAI_SPC, CT_5, SF_6, COMBO_END};
const uint16_t PROGMEM r_num_bsp_combo[]  = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_num_tab_combo[]  = {RAI_SPC, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_num_npd_combo[]  = {RAI_SPC, MED_0, COMBO_END};
const uint16_t PROGMEM r_num_com_combo[]  = {RAI_SPC, INT_DOT, COMBO_END};
const uint16_t PROGMEM r_num_sent_combo[] = {AL_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM r_num_sfg_combo[]  = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM r_num_j_combo[]    = {GU_4, CT_5, COMBO_END};
const uint16_t PROGMEM r_num_k_combo[]    = {CT_5, SF_6, COMBO_END};
const uint16_t PROGMEM r_num_pip_combo[]  = {AL_1, KC_2, COMBO_END};
const uint16_t PROGMEM r_num_cop_combo[]  = {RAI_SPC, GU_4, CT_5, COMBO_END};
const uint16_t PROGMEM r_num_pas_combo[]  = {RAI_SPC, AL_1, KC_2, COMBO_END};
const uint16_t PROGMEM r_num_sal_combo[]  = {RAI_SPC, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM r_num_scp_combo[]  = {RAI_SPC, GU_4, CT_5, SF_6, COMBO_END};
const uint16_t PROGMEM r_num_spa_combo[]  = {RAI_SPC, AL_1, KC_2, KC_3, COMBO_END};

// Lower

const uint16_t PROGMEM l_low_cur_combo[] = {TD_LCBR, TD_RCBR, COMBO_END};
const uint16_t PROGMEM l_low_bsl_combo[] = {TD_RCBR, TD_DLR, COMBO_END};
const uint16_t PROGMEM l_low_par_combo[] = {TD_LPRN, TD_RPRN, COMBO_END};
const uint16_t PROGMEM l_low_bra_combo[] = {TD_LBRC, TD_RBRC, COMBO_END};
const uint16_t PROGMEM l_low_sqo_combo[] = {TD_RPRN, TD_DQUO, COMBO_END};
const uint16_t PROGMEM l_low_bti_combo[] = {TD_RBRC, TD_QUES, COMBO_END};

const uint16_t PROGMEM r_low_ent_combo[]  = {RAI_SPC, KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM r_low_sco_combo[]  = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM r_low_com_combo[]  = {RAI_SPC, KC_DOT, COMBO_END};
const uint16_t PROGMEM r_low_sent_combo[] = {KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM r_low_j_combo[]    = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM r_low_k_combo[]    = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM r_low_pip_combo[]  = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM r_low_cop_combo[]  = {RAI_SPC, KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM r_low_pas_combo[]  = {RAI_SPC, KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM r_low_sal_combo[]  = {RAI_SPC, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM r_low_scp_combo[]  = {RAI_SPC, KC_4, KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM r_low_spa_combo[]  = {RAI_SPC, KC_1, KC_2, KC_3, COMBO_END};

// Raise

const uint16_t PROGMEM l_rai_f10_combo[]  = {KC_F2, KC_F1, COMBO_END};
const uint16_t PROGMEM l_rai_f11_combo[]  = {KC_F4, KC_F5, COMBO_END};
const uint16_t PROGMEM l_rai_f12_combo[]  = {KC_F7, KC_F8, COMBO_END};
const uint16_t PROGMEM l_rai_f13_combo[]  = {KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM l_rai_f14_combo[]  = {KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM l_rai_f15_combo[]  = {KC_F8, KC_F9, COMBO_END};

const uint16_t PROGMEM r_rai_deq_combo[]  = {TD_COLN, TD_EQL, COMBO_END};
const uint16_t PROGMEM r_rai_neq_combo[]  = {TD_COLN, TD_EQL, TD_HASH, COMBO_END};
const uint16_t PROGMEM r_rai_cir_combo[]  = {TD_MINS, TD_PLUS, COMBO_END};
const uint16_t PROGMEM r_rai_dan_combo[]  = {TD_PLUS, TD_SLSH, COMBO_END};
const uint16_t PROGMEM r_rai_dds_combo[]  = {TD_MINS, TD_PLUS, TD_SLSH, COMBO_END};
const uint16_t PROGMEM r_rai_bsp_combo[]  = {TD_EQL, TD_HASH, COMBO_END};
const uint16_t PROGMEM r_rai_til_combo[]  = {TD_EXLM, TD_LT, COMBO_END};
const uint16_t PROGMEM r_rai_dor_combo[]  = {TD_LT, TD_GT, COMBO_END};
const uint16_t PROGMEM r_rai_tisl_combo[] = {TD_EXLM, TD_LT, TD_GT, COMBO_END};

// Navigation

const uint16_t PROGMEM l_nav_esc_combo[] = {MC_ESC, KC_PGUP, COMBO_END};
const uint16_t PROGMEM r_nav_ent_combo[] = {KC_SPC, KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM r_nav_cop_combo[] = {KC_SPC, KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM r_nav_pas_combo[] = {KC_SPC, KC_DEL, KC_HOME, COMBO_END};
const uint16_t PROGMEM r_nav_bsp_combo[] = {KC_ENT, MC_DELW, COMBO_END};

// Media

const uint16_t PROGMEM r_med_ent_combo[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM r_med_vis_combo[] = {KC_MPLY, KC_MPRV, COMBO_END};
const uint16_t PROGMEM r_med_svi_combo[] = {KC_MPRV, KC_MNXT, COMBO_END};
const uint16_t PROGMEM r_med_cvi_combo[] = {KC_MPLY, KC_MPRV, KC_MNXT, COMBO_END};
const uint16_t PROGMEM r_med_esp_combo[] = {MC_MIC, KC_VOLD, KC_VOLU, COMBO_END};
const uint16_t PROGMEM r_med_esc_combo[] = {MC_TAB, KC_ENT, COMBO_END};
const uint16_t PROGMEM r_med_oes_combo[] = {MC_MIC, KC_VOLD, COMBO_END};
const uint16_t PROGMEM r_med_soe_combo[] = {KC_VOLD, KC_VOLU, COMBO_END};

// Symbols

const uint16_t PROGMEM l_sym_eur_combo[]  = {KC_RCBR, KC_DLR, COMBO_END};
const uint16_t PROGMEM l_sym_cur_combo[]  = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM l_sym_par_combo[]  = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM l_sym_bra_combo[]  = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM l_sym_quo_combo[]  = {KC_RPRN, MC_DQUO, COMBO_END};
const uint16_t PROGMEM l_sym_grv_combo[]  = {KC_RBRC, KC_QUES, COMBO_END};

const uint16_t PROGMEM r_sym_perc_combo[] = {KC_COLN, KC_EQL, COMBO_END};
const uint16_t PROGMEM r_sym_cir_combo[]  = {KC_MINS, KC_PLUS, COMBO_END};
const uint16_t PROGMEM r_sym_til_combo[]  = {KC_EXLM, KC_LT, COMBO_END};
const uint16_t PROGMEM r_sym_bsp_combo[]  = {KC_EQL, KC_HASH, COMBO_END};
const uint16_t PROGMEM r_sym_amp_combo[]  = {KC_PLUS, KC_SLSH, COMBO_END};
const uint16_t PROGMEM r_sym_pip_combo[]  = {KC_LT, KC_GT, COMBO_END};

// Intellij and Shortcuts

const uint16_t PROGMEM r_sho_bsp_combo[] = {MC_ENT, KC_ESC, COMBO_END};

// Secret

const uint16_t PROGMEM secret_1_combo[] = {SEC_1, SEC_2, SEC_3, SEC_4, COMBO_END};

combo_t key_combos[] = {
    COMBO(r_num_sent_combo, MC_SENT),   COMBO(l_low_sqo_combo, MC_SQUO),   COMBO(l_low_bti_combo, MC_BTIC),
    COMBO(r_num_sfg_combo, LSFT(KC_L)), COMBO(r_num_j_combo, KC_A),        COMBO(r_num_k_combo, KC_E),
    COMBO(r_num_pip_combo, KC_PIPE),    COMBO(l_low_bsl_combo, KC_BSLS),   COMBO(r_low_sent_combo, MC_SENT),
    COMBO(r_low_j_combo, KC_A),         COMBO(r_low_k_combo, KC_E),        COMBO(r_low_pip_combo, KC_PIPE),
    COMBO(l_sym_cur_combo, MC_CURS),    COMBO(l_sym_par_combo, TD_PARN),   COMBO(l_sym_bra_combo, MC_BRAC),
    COMBO(l_sym_quo_combo, KC_QUOT),    COMBO(l_sym_grv_combo, KC_GRV),    COMBO(l_sym_eur_combo, MC_EUR),
    COMBO(r_sym_perc_combo, KC_PERC),   COMBO(r_sym_cir_combo, KC_CIRC),   COMBO(r_sym_amp_combo, KC_AMPR),
    COMBO(r_sym_pip_combo, KC_PIPE),    COMBO(r_sym_til_combo, KC_TILD),   COMBO(r_sym_bsp_combo, KC_BSPC),
    COMBO(r_low_com_combo, KC_COMM),    COMBO(r_num_com_combo, KC_COMM),   COMBO(l_acc_esc_combo, MC_ESCC),
    COMBO(l_acc_und_combo, KC_UNDS),    COMBO(l_acc_ques_combo, MC_QUES),  COMBO(l_acc_dqo_combo, MC_DQUO),
    COMBO(l_low_cur_combo, MC_CUR),     COMBO(l_low_bra_combo, MC_BRAC),   COMBO(l_low_par_combo, TD_PARN),
    COMBO(l_nav_esc_combo, MC_ESCC),    COMBO(l_num_esc_combo, MC_ESCC),   COMBO(l_num_f10_combo, KC_F10),
    COMBO(l_num_f11_combo, KC_F11),     COMBO(l_num_ent_combo, KC_ENT),    COMBO(l_num_num_combo, TO_A1),
    COMBO(l_num_sav_combo, MC_SAVE),    COMBO(l_rai_f10_combo, KC_F10),    COMBO(l_rai_f11_combo, KC_F11),
    COMBO(l_rai_f12_combo, KC_F12),     COMBO(l_rai_f13_combo, KC_F13),    COMBO(l_rai_f14_combo, KC_F14),
    COMBO(l_rai_f15_combo, KC_F15),     COMBO(l_rom_esc_combo, MC_ESCC),   COMBO(l_rom_esv_combo, MC_ESAV),
    COMBO(l_rom_fin_combo, MC_FIND),    COMBO(l_rom_ful_combo, MC_FULL),   COMBO(l_rom_del_combo, KC_DEL),
    COMBO(l_rom_q_combo, KC_Q),         COMBO(l_rom_k_combo, KC_K),        COMBO(l_rom_num_combo, TG_NUMC),
    COMBO(l_rom_sav_combo, MC_SAVE),    COMBO(l_rom_und_combo, MC_UNDO),   COMBO(l_rom_v_combo, HYP_KCV),
    COMBO(l_rom_w_combo, KC_W),         COMBO(l_acc_lpa_combo, KC_LPRN),   COMBO(l_acc_sqo_combo, MC_SQUO),
    COMBO(r_acc_rpa_combo, KC_RPRN),    COMBO(r_acc_bsp_combo, KC_BSPC),   COMBO(r_acc_col_combo, KC_COLN),
    COMBO(r_acc_excl_combo, MC_EXLM),   COMBO(r_acc_min_combo, KC_MINS),   COMBO(r_acc_agr_combo, MC_GV_A),
    COMBO(r_low_ent_combo, KC_ENT),     COMBO(r_low_sco_combo, TD_SCLE),   COMBO(r_med_ent_combo, TD_EENT),
    COMBO(r_med_vis_combo, KC_V),       COMBO(r_med_svi_combo, MC_SVI),    COMBO(r_med_esc_combo, MC_ESCC),
    COMBO(r_med_esp_combo, MC_0P),      COMBO(r_med_cvi_combo, MC_CVI),    COMBO(r_med_oes_combo, MC_OESC),
    COMBO(r_med_soe_combo, MC_SOES),    COMBO(r_nav_cop_combo, MC_COPY),   COMBO(r_nav_ent_combo, KC_ENT),
    COMBO(r_nav_pas_combo, MC_PAST),    COMBO(r_num_bsp_combo, KC_BSPC),   COMBO(r_num_ent_combo, KC_ENT),
    COMBO(r_nav_bsp_combo, KC_BSPC),    COMBO(r_num_npd_combo, TG_NUM),    COMBO(l_num_tab_combo, KC_TAB),
    COMBO(r_num_tab_combo, KC_TAB),     COMBO(r_rai_bsp_combo, KC_BSPC),   COMBO(r_rai_deq_combo, MC_DEQ),
    COMBO(r_rai_til_combo, TD_TIL),     COMBO(r_rai_dor_combo, TD_DOR),    COMBO(r_rai_tisl_combo, MC_TISL),
    COMBO(r_rai_dds_combo, MC_DDS),     COMBO(r_rai_neq_combo, MC_NEQ),    COMBO(r_rai_dan_combo, TD_DAND),
    COMBO(r_rai_cir_combo, TD_CIRC),    COMBO(r_rom_bsp_combo, KC_BSPC),   COMBO(r_rom_d_combo, KC_D),
    COMBO(r_rom_p_combo, KC_P),         COMBO(l_rom_ent_combo, KC_ENT),    COMBO(r_rom_ent_combo, KC_ENT),
    COMBO(r_rom_j_combo, HYP_KCJ),      COMBO(r_rom_cop_combo, MC_COPY),   COMBO(r_rom_pas_combo, MC_PAST),
    COMBO(r_rom_sal_combo, MC_SELC),    COMBO(r_rom_scp_combo, MC_SCOP),   COMBO(r_rom_spa_combo, MC_SPAS),
    COMBO(r_low_cop_combo, MC_COPY),    COMBO(r_low_pas_combo, MC_PAST),   COMBO(r_low_sal_combo, MC_SELC),
    COMBO(r_low_scp_combo, MC_SCOP),    COMBO(r_low_spa_combo, MC_SPAS),   COMBO(r_num_cop_combo, MC_COPY),
    COMBO(r_num_pas_combo, MC_PAST),    COMBO(r_num_sal_combo, MC_SELC),   COMBO(r_num_scp_combo, MC_SCOP),
    COMBO(r_num_spa_combo, MC_SPAS),    COMBO(r_rom_sco_combo, TD_SCLE),   COMBO(r_rom_sent_combo, MC_SENT),
    COMBO(l_rom_tab_combo, KC_TAB),     COMBO(r_rom_tab_combo, KC_TAB),    COMBO(l_acc_ent_combo, KC_ENT),
    COMBO(r_acc_ent_combo, KC_ENT),     COMBO(l_acc_tab_combo, KC_TAB),    COMBO(r_acc_tab_combo, KC_TAB),
    COMBO(r_rom_z_combo, KC_Z),         COMBO(r_rom_x_combo, KC_X),        COMBO(r_rom_y_combo, KC_Y),
    COMBO(r_sho_bsp_combo, KC_BSPC),    COMBO(secret_1_combo, MC_SECRET_1)};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo->keycode) {
        case KC_BSPC:
            if (layer_state_is(_MEDIA)) {
                return false;
            }
            break;
        case KC_F13:
        case KC_F14:
        case KC_F15:
            if (layer_state_is(_NUMPAD)) {
                return false;
            }
            break;
        case MC_DEQ:
        case TD_CIRC:
        case TD_DAND:
        case TD_TIL:
        case TD_DOR:
        case MC_NEQ:
        case MC_DDS:
        case MC_TISL:
            if (layer_state_is(_SYMBOLS)) {
                return false;
            }
            break;
    }
    return true;
}

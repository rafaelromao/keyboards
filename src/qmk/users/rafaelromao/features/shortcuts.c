#include "features/shortcuts.h"
#include "features/macros.h"
#include "features/adaptive.h"
#include "os_detection.h"

static bool os_mac;
static bool os_manual;

bool shortcuts_is_mac(void) {
    return os_mac;
}

bool process_detected_host_os_user(os_variant_t os) {
    if (!os_manual) os_mac = (os == OS_MACOS || os == OS_IOS);
    return true;
}

// {linux, mac}, in the order of the keycode enum from MC_OS_FIRST. KC_NO marks
// the entries built from two others in code below.
typedef struct {
    uint16_t linux;
    uint16_t mac;
} os_shortcut_t;

// clang-format off
static const os_shortcut_t os_shortcuts[] PROGMEM = {
    [MC_FULLSCR - MC_OS_FIRST]        = {G(KC_F),        C(G(KC_F))},
    [MC_FIND - MC_OS_FIRST]           = {C(KC_F),        G(KC_F)},
    [MC_SELALL - MC_OS_FIRST]         = {C(KC_A),        G(KC_A)},
    [MC_UNDO - MC_OS_FIRST]           = {C(KC_Z),        G(KC_Z)},
    [MC_COPY - MC_OS_FIRST]           = {G(KC_C),        G(KC_C)},
    [MC_SHIFT_COPY - MC_OS_FIRST]     = {S(C(KC_C)),      S(G(KC_C))},
    [MC_SELCOPY - MC_OS_FIRST]        = {KC_NO,           KC_NO},
    [MC_SHIFT_SELCOPY - MC_OS_FIRST]  = {KC_NO,           KC_NO},
    [MC_PASTE - MC_OS_FIRST]          = {G(KC_V),        G(KC_V)},
    [MC_SHIFT_PASTE - MC_OS_FIRST]    = {S(C(KC_V)),      S(G(KC_V))},
    [MC_SELPASTE - MC_OS_FIRST]       = {KC_NO,           KC_NO},
    [MC_SHIFT_SELPASTE - MC_OS_FIRST] = {KC_NO,           KC_NO},
    [MC_SAVE - MC_OS_FIRST]           = {C(KC_S),        G(KC_S)},
    [MC_COMMENT - MC_OS_FIRST]        = {C(KC_SLSH),     G(KC_SLSH)},
    [MC_LOCK - MC_OS_FIRST]           = {C(G(KC_L)),      C(G(KC_Q))},
    [MC_REFRESH - MC_OS_FIRST]        = {KC_F5,           G(KC_R)},
    [MC_CLOSE - MC_OS_FIRST]          = {C(KC_W),        G(KC_W)},
    [MC_REOPEN - MC_OS_FIRST]         = {S(C(KC_T)),      S(G(KC_T))},
    [MC_NEW - MC_OS_FIRST]            = {C(KC_T),        G(KC_T)},
    [MC_ZOOM_OUT - MC_OS_FIRST]       = {C(KC_MINS),     G(KC_MINS)},
    [MC_ZOOM_IN - MC_OS_FIRST]        = {C(KC_PLUS),     G(KC_PLUS)},
    [MC_RESET_ZOOM - MC_OS_FIRST]     = {C(KC_0),        G(KC_0)},
    [MC_LAUNCHER - MC_OS_FIRST]       = {G(KC_SPC),      A(KC_SPC)},
    [MC_TABS - MC_OS_FIRST]           = {S(C(KC_A)),      S(G(KC_A))},
    [MC_FILES - MC_OS_FIRST]          = {S(G(KC_F)),      LCA(KC_F)},
    [MC_SCREENSHOT - MC_OS_FIRST]     = {KC_PSCR,         LCA(KC_S)},
    [MC_EMOJI - MC_OS_FIRST]          = {C(G(KC_E)),      LCA(KC_J)},
    [MC_CALC - MC_OS_FIRST]           = {C(G(KC_Q)),      LCA(KC_C)},
    [MC_NOTES - MC_OS_FIRST]          = {S(G(KC_O)),      LCA(KC_O)},
    [MC_TERM - MC_OS_FIRST]           = {G(KC_ENT),      LCA(KC_T)},
    [MC_BROWSER - MC_OS_FIRST]        = {S(G(KC_B)),      LCA(KC_B)},
    [MC_EDITOR - MC_OS_FIRST]         = {S(G(KC_N)),      LCA(KC_N)},
    [MC_AI - MC_OS_FIRST]             = {C(G(KC_X)),      LCA(KC_I)},
    [MC_ACTIVITIES - MC_OS_FIRST]     = {C(G(KC_T)),      LCA(KC_A)},
    [MC_SYSTEM - MC_OS_FIRST]         = {A(G(KC_SPC)),    C(KC_SPC)},
    [MC_CONTAINERS - MC_OS_FIRST]     = {S(G(KC_D)),      LCA(KC_R)},
    [MC_PREV_WORD - MC_OS_FIRST]      = {C(KC_LEFT),     A(KC_LEFT)},
    [MC_NEXT_WORD - MC_OS_FIRST]      = {C(KC_RGHT),     A(KC_RGHT)},
    [MC_DEL_WORD - MC_OS_FIRST]       = {C(KC_DEL),      A(KC_DEL)},
    [MC_BSP_WORD - MC_OS_FIRST]       = {C(KC_BSPC),     A(KC_BSPC)},
};
// clang-format on

static uint16_t os_keycode(uint16_t keycode) {
    const os_shortcut_t *e = &os_shortcuts[keycode - MC_OS_FIRST];
    return os_mac ? pgm_read_word(&e->mac) : pgm_read_word(&e->linux);
}

static void tap_os(uint16_t keycode) {
    uint16_t kc = os_keycode(keycode);
    tap_code16(kc);
    adaptive_track(kc);
}

bool process_shortcuts(uint16_t keycode, bool pressed) {
    if (keycode >= MC_OS_FIRST && keycode <= MC_OS_LAST) {
        if (!pressed) return true;
        switch (keycode) {
            case MC_SELCOPY:
                tap_os(MC_SELALL);
                tap_os(MC_COPY);
                break;
            case MC_SHIFT_SELCOPY:
                tap_code16(S(os_keycode(MC_SELALL)));
                tap_os(MC_SHIFT_COPY);
                break;
            case MC_SELPASTE:
                tap_os(MC_SELALL);
                tap_os(MC_PASTE);
                break;
            case MC_SHIFT_SELPASTE:
                tap_code16(S(os_keycode(MC_SELALL)));
                tap_os(MC_SHIFT_PASTE);
                break;
            default:
                tap_os(keycode);
        }
        return true;
    }
    switch (keycode) {
        case MC_OS_MAC:
        case MC_OS_LINUX:
            if (pressed) {
                os_mac    = (keycode == MC_OS_MAC);
                os_manual = true;
            }
            return true;
        case MC_OS_NAME:
            if (pressed) seq_play(os_mac ? SEQ_MACOS : SEQ_OMARCHY);
            return true;
    }
    return false;
}

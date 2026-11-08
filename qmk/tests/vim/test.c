#include <assert.h>
#include <stdio.h>

#include "features/vim.h"
#include "features/macros.h"

static uint32_t layers;
static uint8_t mods;
static uint8_t oneshot_mods;
static uint16_t last_key;
static unsigned adaptive_clear_count;
static unsigned key_count;

void layer_on(uint8_t layer) { layers |= 1UL << layer; }
void layer_off(uint8_t layer) { layers &= ~(1UL << layer); }
uint8_t get_mods(void) { return mods; }
uint8_t get_oneshot_mods(void) { return oneshot_mods; }
uint16_t timer_read(void) { return 0; }
uint16_t timer_elapsed(uint16_t start) { return 0 - start; }
void tap_code(uint8_t keycode) { last_key = keycode; ++key_count; }
void execute_keycode(uint16_t keycode) { last_key = keycode; ++key_count; }
void adaptive_clear(void) { ++adaptive_clear_count; }

static bool normal_layer(void) { return layers & (1UL << _VIM_NORMAL); }

static void enter_visual(void) {
    mods = oneshot_mods = 0;
    vim_off();
    assert(process_vim_kc(VIM_ON, true));
    assert(process_vim_kc(VIM_V, true));
    assert(normal_layer());
}

// The callbacks run around native base keys and tapped mod-taps in the
// userspace record pipeline. QMK itself supplies their tap decisions.
static void base_ctrl_c(bool modtap, bool oneshot) {
    keyrecord_t record = {.event.pressed = true, .tap.count = 1};
    uint16_t keycode = modtap ? HRM_C : KC_C;
    mods = oneshot ? 0 : MOD_MASK_CTRL;
    oneshot_mods = oneshot ? MOD_MASK_CTRL : 0;
    assert(process_vim(keycode, &record) == PROCESS_RECORD_CONTINUE);
    vim_after_press(keycode, &record);
    mods = oneshot_mods = 0;
}

static void assert_i_enters_insert(void) {
    unsigned clears = adaptive_clear_count;
    unsigned keys = key_count;
    vim_modtap_tap(KC_I);
    assert(!normal_layer());
    assert(last_key == KC_I);
    assert(key_count == keys + 1);
    assert(adaptive_clear_count == clears + 1);
}

int main(void) {
    // Insert and change macros clear the antecedent without sending F23.
    const uint16_t commands[] = {VIM_O, VIM_A, VIM_I, VIM_CE, VIM_CI, VIM_CA};
    const uint16_t expected[] = {KC_O, KC_A, KC_I, KC_E, KC_I, KC_A};
    for (unsigned i = 0; i < sizeof(commands) / sizeof(commands[0]); ++i) {
        assert(process_vim_kc(VIM_ON, true));
        unsigned clears = adaptive_clear_count;
        unsigned keys = key_count;
        assert(process_vim_kc(commands[i], true));
        assert(!normal_layer());
        assert(last_key == expected[i]);
        assert(key_count == keys + 1);
        assert(adaptive_clear_count == clears + 1);
    }

    // Existing Ctrl+C behavior when a NORMAL mod-tap handles the tap.
    enter_visual();
    mods = MOD_MASK_CTRL;
    vim_modtap_tap(KC_C);
    mods = 0;
    assert_i_enters_insert();

    for (unsigned modtap = 0; modtap < 2; ++modtap) {
        for (unsigned oneshot = 0; oneshot < 2; ++oneshot) {
            enter_visual();
            vim_base_hold(true);
            assert(!normal_layer());
            base_ctrl_c(modtap, oneshot);
            assert(!normal_layer());  // Ctrl+C must not drop the base override.
            vim_base_hold(false);
            assert(normal_layer());
            assert_i_enters_insert();  // Stale VISUAL instead leaves NORMAL on.
        }
    }

    // Releasing one pinky must not cancel a second held pinky's override.
    enter_visual();
    vim_base_hold(true);
    vim_base_hold(true);
    base_ctrl_c(true, false);
    vim_base_hold(false);
    assert(!normal_layer());
    vim_base_hold(false);
    assert(normal_layer());
    assert_i_enters_insert();

    // Other mode transitions that want NORMAL also respect the held base.
    enter_visual();
    vim_base_hold(true);
    process_vim_kc(VIM_CTL_V, true);
    assert(!normal_layer());
    vim_base_hold(false);
    assert(normal_layer());
    vim_modtap_tap(KC_I);  // Still VISUAL: i is a text object, not insert.
    assert(normal_layer());
    assert(last_key == KC_I);

    // A hold release must not re-enable NORMAL after Vim has been disabled.
    vim_base_hold(true);
    vim_off();
    vim_base_hold(false);
    assert(!normal_layer());

    puts("PASS: insert/change clear the antecedent without markers; base Ctrl+C exits VISUAL and preserves held overrides");
}

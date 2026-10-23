/*
 * Copyright (c) 2026 Rafael Romão
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_sentence_case

#include <zephyr/device.h>
#include <drivers/behavior.h>
#include <zmk/behavior.h>
#include <zmk/event_manager.h>
#include <zmk/events/keycode_state_changed.h>
#include <zmk/hid.h>
#include <dt-bindings/zmk/keys.h>
#include <zmk-sentence-case.h>

struct sentence_case_config {
    uint32_t prior_idle_ms;
    uint32_t release_after_ms;
};

/* No modifier is held while armed: numbers, mod-morphs and dead keys must not
 * see a shift. Apply it to the next letter's event, just as an LS() binding
 * would, so adaptive/repeat keys also remember the capitalized character. */
static bool armed;
static int64_t expires_at;
static bool last_was_terminator;
static int64_t last_timestamp;

bool zmk_sentence_case_pending(int64_t timestamp) {
    if (armed && timestamp > expires_at) {
        armed = false;
    }
    return armed;
}

static int on_space_pressed(struct zmk_behavior_binding *binding,
                            struct zmk_behavior_binding_event event) {
    const struct device *dev = zmk_behavior_get_binding(binding->behavior_dev);
    const struct sentence_case_config *config = dev->config;
    bool trigger = last_was_terminator && event.timestamp >= last_timestamp &&
                   event.timestamp - last_timestamp <= config->prior_idle_ms;

    /* Deliver space first: it consumes an earlier one-shot and becomes the
     * previous character. Arm on press, not release, to support rolled typing. */
    int err = raise_zmk_keycode_state_changed_from_encoded(SPACE, true, event.timestamp);
    armed = trigger;
    expires_at = event.timestamp + config->release_after_ms;
    return err < 0 ? err : ZMK_BEHAVIOR_OPAQUE;
}

static int on_space_released(struct zmk_behavior_binding *binding,
                             struct zmk_behavior_binding_event event) {
    return raise_zmk_keycode_state_changed_from_encoded(SPACE, false, event.timestamp);
}

static const struct behavior_driver_api sentence_case_api = {
    .binding_pressed = on_space_pressed,
    .binding_released = on_space_released,
};

static int sentence_case_listener(const zmk_event_t *eh) {
    struct zmk_keycode_state_changed *ev = as_zmk_keycode_state_changed(eh);
    if (!ev || !ev->state) {
        return ZMK_EV_EVENT_BUBBLE;
    }

    if (zmk_sentence_case_pending(ev->timestamp)) {
        armed = false;
        if (ev->usage_page == HID_USAGE_KEY && ev->keycode >= ZMK_HID_USAGE_ID(A) &&
            ev->keycode <= ZMK_HID_USAGE_ID(Z)) {
            ev->implicit_modifiers |= MOD_LSFT;
        }
    }

    /* Match the adaptive key's strict modifier semantics, including held mods.
     * Shift+dot is '>', Ctrl+dot is a shortcut, and neither starts a sentence. */
    uint8_t mods = ev->implicit_modifiers | zmk_hid_get_explicit_mods();
    last_was_terminator =
        ev->usage_page == HID_USAGE_KEY &&
        ((ev->keycode == ZMK_HID_USAGE_ID(DOT) && mods == 0) ||
         ((ev->keycode == ZMK_HID_USAGE_ID(QMARK) || ev->keycode == ZMK_HID_USAGE_ID(EXCL)) &&
          mods == MOD_LSFT));
    last_timestamp = ev->timestamp;
    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(sentence_case, sentence_case_listener);
ZMK_SUBSCRIPTION(sentence_case, zmk_keycode_state_changed);

#define SENTENCE_CASE_INST(n)                                                                      \
    static const struct sentence_case_config sentence_case_config_##n = {                          \
        .prior_idle_ms = DT_INST_PROP(n, prior_idle_ms),                                           \
        .release_after_ms = DT_INST_PROP(n, release_after_ms),                                     \
    };                                                                                             \
    BEHAVIOR_DT_INST_DEFINE(n, NULL, NULL, NULL, &sentence_case_config_##n, POST_KERNEL,           \
                            CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &sentence_case_api);

DT_INST_FOREACH_STATUS_OKAY(SENTENCE_CASE_INST)

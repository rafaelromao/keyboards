/*
 * Copyright (c) 2026 Rafael Romão
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_sentence_morph

#include <errno.h>
#include <zephyr/device.h>
#include <drivers/behavior.h>
#include <zmk/behavior.h>
#include <zmk/keymap.h>
#include <zmk-sentence-case.h>

struct sentence_morph_config {
    struct zmk_behavior_binding bindings[2];
};

struct active_morph {
    struct zmk_behavior_binding pressed;
    uint32_t position;
#if IS_ENABLED(CONFIG_ZMK_SPLIT)
    uint8_t source;
#endif
    bool active;
};

struct sentence_morph_data {
    struct active_morph positions[CONFIG_ZMK_BEHAVIOR_SENTENCE_MORPH_MAX_HELD];
};

static struct active_morph *find_morph(struct sentence_morph_data *data,
                                       struct zmk_behavior_binding_event event) {
    for (int i = 0; i < ARRAY_SIZE(data->positions); i++) {
        struct active_morph *active = &data->positions[i];
        if (!active->active || active->position != event.position) {
            continue;
        }
#if IS_ENABLED(CONFIG_ZMK_SPLIT)
        if (active->source != event.source) {
            continue;
        }
#endif
        return active;
    }
    return NULL;
}

static int on_morph_pressed(struct zmk_behavior_binding *binding,
                            struct zmk_behavior_binding_event event) {
    const struct device *dev = zmk_behavior_get_binding(binding->behavior_dev);
    const struct sentence_morph_config *config = dev->config;
    struct sentence_morph_data *data = dev->data;
    if (find_morph(data, event)) {
        return -EBUSY;
    }
    for (int i = 0; i < ARRAY_SIZE(data->positions); i++) {
        struct active_morph *active = &data->positions[i];
        if (active->active) {
            continue;
        }
        active->pressed = config->bindings[zmk_sentence_case_pending(event.timestamp)];
        active->position = event.position;
#if IS_ENABLED(CONFIG_ZMK_SPLIT)
        active->source = event.source;
#endif
        active->active = true;
        int err = zmk_behavior_invoke_binding(&active->pressed, event, true);
        if (err < 0) {
            active->active = false;
        }
        return err;
    }
    return -ENOMEM;
}

static int on_morph_released(struct zmk_behavior_binding *binding,
                             struct zmk_behavior_binding_event event) {
    const struct device *dev = zmk_behavior_get_binding(binding->behavior_dev);
    struct sentence_morph_data *data = dev->data;
    struct active_morph *active = find_morph(data, event);
    if (!active) {
        return ZMK_BEHAVIOR_OPAQUE;
    }
    struct zmk_behavior_binding pressed = active->pressed;
    active->active = false;
    return zmk_behavior_invoke_binding(&pressed, event, false);
}

static const struct behavior_driver_api sentence_morph_api = {
    .binding_pressed = on_morph_pressed,
    .binding_released = on_morph_released,
};

#define SENTENCE_MORPH_INST(n)                                                                     \
    BUILD_ASSERT(DT_INST_PROP_LEN(n, bindings) == 2, "sentence-morph requires two bindings");      \
    static const struct sentence_morph_config sentence_morph_config_##n = {                        \
        .bindings = {ZMK_KEYMAP_EXTRACT_BINDING(0, DT_DRV_INST(n)),                                \
                     ZMK_KEYMAP_EXTRACT_BINDING(1, DT_DRV_INST(n))},                               \
    };                                                                                             \
    static struct sentence_morph_data sentence_morph_data_##n;                                     \
    BEHAVIOR_DT_INST_DEFINE(n, NULL, NULL, &sentence_morph_data_##n, &sentence_morph_config_##n,   \
                            POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,                      \
                            &sentence_morph_api);

DT_INST_FOREACH_STATUS_OKAY(SENTENCE_MORPH_INST)

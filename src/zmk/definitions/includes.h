#pragma once

#define MACOS

#include <dt-bindings/zmk/hid_usage.h>
#include <dt-bindings/zmk/hid_usage_pages.h>
#include <dt-bindings/zmk/modifiers.h>
#include <dt-bindings/zmk/mouse.h>

#include "templates.dtsi"
#include "keycodes.h"
#include "config.dtsi"

#include "../features/mouse.dtsi"

#include "../features/accents.dtsi"
#include "../features/shortcuts.dtsi"
#include "../features/select.dtsi"

#ifdef MACOS
#include "../features/macos/accents.dtsi"
#include "../features/macos/shortcuts.dtsi"
#include "../features/macos/select.dtsi"
#endif
#ifdef LINUX
#include "../features/linux/accents.dtsi"
#include "../features/linux/shortcuts.dtsi"
#include "../features/linux/select.dtsi"
#endif

#include "../features/smart.dtsi"
#include "../features/magic.dtsi"
#include "../features/symbols.dtsi"

#include "../features/combos.dtsi"
#include "../features/leader.dtsi"

#if __has_include("../secret.dtsi")
#include "../secret.dtsi"
#endif

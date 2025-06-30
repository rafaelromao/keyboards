#include <dt-bindings/zmk/hid_usage.h>
#include <dt-bindings/zmk/hid_usage_pages.h>
#include <dt-bindings/zmk/modifiers.h>
#include <dt-bindings/zmk/mouse.h>

#include "helpers.h"
#include "config.dtsi"

#if __has_include("flags.h")
#include "flags.h"
#endif

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

#include "../features/sentence.dtsi"
#include "../features/smart.dtsi"
#include "../features/adaptive.dtsi"
#include "../features/symbols.dtsi"

#include "../features/combos.dtsi"
#include "../features/leader.dtsi"

#if __has_include("../secret.dtsi")
#include "../secret.dtsi"
#endif

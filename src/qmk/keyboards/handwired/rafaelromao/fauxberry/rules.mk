SRC += features/leader.c
SRC += features/sentence_case.c
SRC += features/dynamic_macro.c
SRC += features/swapper.c

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
WS2812_DRIVER = vendor
ENCODER_MAP_ENABLE = yes
MOUSEKEY_ENABLE = yes
OLED_DRIVER = SSD1306
DYNAMIC_MACRO_ENABLE = yes
LEADER_ENABLE = yes
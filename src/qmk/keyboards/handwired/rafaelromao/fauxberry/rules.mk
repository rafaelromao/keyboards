SRC += features/dynamic_macro.c
SRC += features/getreuer/orbital_mouse.c
SRC += features/leader.c

LEADER_ENABLE = yes
MOUSE_ENABLE = yes
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
WS2812_DRIVER = vendor
ENCODER_MAP_ENABLE = yes
OLED_DRIVER = ssd1306
DYNAMIC_MACRO_ENABLE = yes
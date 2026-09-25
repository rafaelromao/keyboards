SRC += rafaelromao.c
SRC += features/taphold.c
SRC += features/thumbs.c
SRC += features/smart.c
SRC += features/adaptive.c
SRC += features/macros.c
SRC += features/accents.c
SRC += features/shortcuts.c
SRC += features/select_word.c
SRC += features/vim.c
INTROSPECTION_KEYMAP_C = features/combos.c

LTO_ENABLE = yes

EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
OS_DETECTION_ENABLE = yes

# Not needed by this layout, and every one of them costs flash on the
# ATmega32U4 boards this userspace is built for.
NKRO_ENABLE = no
BOOTMAGIC_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
AUDIO_ENABLE = no
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
KEY_LOCK_ENABLE = no
SWAP_HANDS_ENABLE = no
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
DYNAMIC_MACRO_ENABLE = no
REPEAT_KEY_ENABLE = no
UNICODE_ENABLE = no

# rafaelromao's QMK userspace

The QMK implementation of [my keymap](https://github.com/rafaelromao/keyboards), for the boards that cannot run ZMK. It is a port of the ZMK keymap in `zmk/definitions` and `zmk/features`, position for position, and it is built as a QMK External Userspace (see `qmk/qmk.json`, `scripts/b.sh` and `scripts/qmk-build.sh`).

- `definitions/layers.h`: the layers, in the ZMK order.
- `definitions/keycodes.h`: the custom keycodes and the aliases used by the keymap.
- `definitions/keymap_blocks.h`: the 36-position keymap, one block per row and hand.
- `definitions/positions.h`: the 36 positions as ALPHA1 keycodes, for the combos.
- `features/taphold.c`: the tap/hold symbol keys and the per-key tap-hold settings.
- `features/thumbs.c`: the smart thumb keys.
- `features/smart.c`: caps word, caps line, num word, one-shot layers, sentence case, cancel.
- `features/adaptive.c`: the adaptive keys (alternate repeat, magic keys).
- `features/combos.c`: the combos, with the layers each one is allowed on.
- `features/shortcuts.c`: the OS-dependent shortcuts and the OS mode.
- `features/macros.c`: key sequences, digits, text macros.
- `features/accents.c`: accented letters, ç, qu, ão, ões.
- `features/select_word.c`: select word / line / home.
- `features/vim.c`: vim mode without the host sync.

`config.h` has the three optional parts (MEHS, vim, MACROS) as defines, in the order they would be dropped if a board ran out of flash.

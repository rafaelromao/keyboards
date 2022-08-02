# rafaelromao's keyboard layout

## Layout Overview
- This is a 32 keys split layout, 3x5+2 keys on each side, minus the two top row pinky keys.
- This layout works well with the OS configured for US International keyboards.
- It was designed mostly for coding and typing in Portuguese and English.
- It reduces the usage of pinkies and considers the right hand as the dominant hand.
- The base layer is [Romak](romak.md), a new keyboard layout, inspired by [Colemak](https://colemak.org) and [BEAKL](https://ieants.cc/beakl).

## Smart Thumb Keys
- The Smart Thumb keys in this layout change behavior according to the context (active layer and active modifiers).
- The four thumb keys control layer transitions, when held (navigation, lower, raise and media).
- The two outer thumb keys act as activation for oneshot layer or modifiers, when tapped.
- The two inner thumb keys act as space and backspace, when tapped (inverted in the [Macros](macros.md#macros) layer).
- Holding both outer thumb keys will activate the maintenance layer.
- Source code: [custom_oneshot.c](../src/qmk/users/rafaelromao/features/custom_oneshot.c)

## Base Layer Combos
- Combos are available in the base and [Numpad](symbols.md#numpad-layer) layers to send ENTER, ESC, TAB and common shortcuts like copy, paste, save, select all and undo.
- Most combos include the home thumb key, the one in the same side, to avoid misfires.
- One-shot shift can be used to invert the [Default Modifier](modifiers.md#default-mod-and-alt-thumb-keys) used in the combos.
- If shift, or any other modifier, is held, it will be included in the combo. So hold Shift and tap the Undo combo will send Redo instead.
- Source code: [combos.c](../src/qmk/users/rafaelromao/features/combos.c)

## Base Layer Macros
- Some macros are available directly from the base layer.
- Source code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

### Double Comma for Leader Key
- The Leader Key can be accessed double tapping the comma key. This allow really fast access to leader sequences.

### Pontuation Hold
- Holding a pontuation key (dot, comma or semicollon) will add it to the end of the current line.

### Secrets
- Secret combos and leader sequencies can be included in the files [secret.h](https://gist.github.com/rafaelromao/29b444b8b0bdec5402067beb35c2bcda) and [secret.c](https://gist.github.com/rafaelromao/76be290d7d58176699b8e20859c15618). These files are not part of the repo, for obvious reasons, so these two gists are provided as templates.

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[N-Grams and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)

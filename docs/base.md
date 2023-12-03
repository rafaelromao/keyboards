# rafaelromao's keyboard layout

## Layout Overview
- This is split keyboard layout that goes from 24 to 34 keys, from the formats 1333+2 to 3x5+2. Most of the time I use boards in the 23332+2 format, like the Rommana and Hummingbird, but with the 1333+2 keymap.
- This layout works well with the OS configured for US International keyboards.
- It was designed mostly for coding and typing in Portuguese and English.
- It reduces the usage of pinkies and indexes and considers the right hand as dominant.
- The alpha layout is [Romak](romak.md), a new keyboard layout, inspired by [Colemak](https://colemak.org) and [BEAKL](https://ieants.cc/beakl).

### Primary Alpha Layer
- The Alpha1 layer is the base layer, which contains the most common alphas of Portuguese and English, plus comma and period. It is extended by the Alpha2 layer.

### Secondary Alpha Layer
- The Alpha2 layer has common Portuguese accented letters, readily available with a single tap on the left outer thumb key (OS Accents), making them as easy to type as shifted letters, which are available with a single tap on the right outer thumb key (OS Shift).
- This layer also gives access to q, y, z and x, that are not available in the base layer, for the 28 keys variant, as well as an standalone apostrophe character.
- There are dedicated accent keys for à á ã â é ê õ ó ô ú í and ç, which is all that is needed for Portuguese.
- Source code:
  - [QMK] [accents.c](../src/qmk/users/rafaelromao/features/accents.c)
  - [ZMK] [accents.dtsi](https://github.com/rafaelromao/keyboards/blob/main/src/zmk/config/rafaelromao/features/accents.dtsi) 

## Smart Thumb Keys
- The Smart Thumb keys in this layout change behavior according to the context (active layer and active modifiers).
- The four thumb keys control layer transitions, when held (Navigation, Lower, Raise and Media).
- Holding both outer thumb keys will activate the [System](../system.md) layer, while holding both inner thumb keys activates the [Symbols](../symbols.md) layer.
- Source code: [custom_oneshot.c](../src/qmk/users/rafaelromao/features/custom_oneshot.c)

## Repeat Key
- The outer left thumb key, when tapped, repeats the last key or shortcut. This is usefull to avoid tapping the same key twice 5 words like 'tapped'.
- Holding this key in the base will activate the [Navigation](../navigation.md) layer, but holding it in the [Raise](../symbols.md) layer will keeps repeating the last key or shortcut.

## Base Layer Combos
- Combos are available in the base and [Numpad](symbols.md#numpad-layer) layers to send ENTER, ESC, TAB and common shortcuts like copy, paste, save, select all and undo.
- Most combos include the home thumb key, the one in the same side, to avoid misfires.
- One-shot shift can be used to invert the modifier (Ctrl vs Cmd) used in the combos.
- If shift, or any other modifier, is held, it will be included in the combo. So hold Shift and tap the Undo combo will send Redo instead.
- There are also combos for z and x, that are not available through dedicated keys in the base layer.
- Source code: [combos.c](../src/qmk/users/rafaelromao/features/combos.c)

### Leader Key
- The Leader Key can be accessed double tapping the comma key. This allow really fast access to leader sequences.

### Pontuation Hold
- Holding a pontuation key (dot, comma or semicollon) will add it to the end of the current line.

### Sentence Case
- Tapping Space after `.`, `?` or `!` will trigger ONESHOT SHIFT when the next key is pressed, so that it gets capitalized. Repeat key can be used to cancel this behavior, and it will also expire after one second if no other key is pressed.

### Secrets
- Secret combos and leader sequencies can be included in the files [secret.h](https://gist.github.com/rafaelromao/29b444b8b0bdec5402067beb35c2bcda) and [secret.c](https://gist.github.com/rafaelromao/76be290d7d58176699b8e20859c15618). These files are not part of the repo, for obvious reasons, so these two gists are provided as templates.

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[Shortcuts and Macros](shortcuts.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[System](system.md)

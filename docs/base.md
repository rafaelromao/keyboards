# rafaelromao's keyboard layout

## Layout Overview
- This is split keyboard layout that goes from 24 to 34 keys, from the formats 1333+2 to 3x5+2. Most of the time I use boards in the 23332+2 format, like the Rommana and Hummingbird, but with the 1333+2 keymap.
- This layout works well with the OS configured for US International keyboards.
- It was designed mostly for coding and typing in Portuguese and English.
- It reduces the usage of pinkies and indexes and considers the right hand as dominant.
- The alpha layout is [Romak](https://github.com/rafaelromao/romak), a new keyboard layout, with all vowels on the right hand.

### Primary Alpha Layer
- The Alpha1 layer is the base layer, which contains the most common alphas of Portuguese and English, plus comma and period. It is extended by the Alpha2 layer.

### Secondary Alpha Layer
- The Alpha2 layer has common Portuguese accented letters, readily available with a single tap on the right inner thumb key (OS Accents), making them as easy to type as shifted letters, which are available with a single tap on the right outer thumb key (OS Shift).
- There are dedicated accent keys for à á â é ê ó ô ú í and ç, as well as a dead key for ~, which is all that is needed for Portuguese.
- This layer also gives access to comma, dot and replicated versions of q, y, w, v, z and j, that are not available in the base layer, for the 24 keys variant, as well as an standalone apostrophe character in the thumb.
- This two alpha layers approach is based on [Ben Vallack's keymap](https://youtu.be/5RN_4PQ0j1A?si=f9OkOvNdL3jE4seR).
- Source code:
  - [QMK] [accents.c](../src/qmk/users/rafaelromao/features/accents.c)
  - [ZMK] [accents.dtsi](https://github.com/rafaelromao/keyboards/blob/main/src/zmk/config/rafaelromao/features/accents.dtsi) 

## Smart Thumb Keys
- The Smart Thumb keys in this layout change behavior according to the context (active layer, active modifiers and more).
- The four thumb keys control layer transitions, when held (Navigation, Lower, Raise and Media).
- Source code: [custom_oneshot.c](../src/qmk/users/rafaelromao/features/custom_oneshot.c)

### Smart Shift / Repeat Key
- The outer left thumb key, when tapped in the middle of a word, repeats the last key. This is usefull to avoid tapping the same key twice in words like 'tapped'.
- When tapped in the beginning of a word, it acts as One Shot Shift.
- Holding this key in the base layer will activate the [Navigation](../navigation.md) layer.
- Tapping or holding this key in the [Raise](../symbols.md) layer acts as a normal Repeat Key, which can be used to spam or to repeat shortcuts. 
- This feature was inspired by bmijanovich's [Dynamic Repeat Key](https://github.com/bmijanovich/zmk-config?tab=readme-ov-file#dynamic-repeat-key).

### Smart Shift / Magic Key
- The outer right thumb key, when tapped in the middle of a word, selects the output according to the context. See more about that [here](https://github.com/rafaelromao/romak/tree/main?tab=readme-ov-file#magic-romak).
- When tapped in the beginning of a word, it also acts as One Shot Shift.
- Holding this key in the base layer will activate the [Media](../navigation.md) layer.

## Base Layer Combos
- Combos are available in the base and [Numpad](symbols.md#numpad-layer) layers to send ENTER, ESC, TAB and common shortcuts like copy, paste, save, select all and undo.
- Most combos include the home thumb key, the one in the same side.
- If shift or any other modifier is held, it will be included in the combo. So hold Shift and tap the Undo combo will send Redo instead.
- Source code: [combos.c](../src/qmk/users/rafaelromao/features/combos.c)

## Base Layer Macros
- Some macros are available in the base layers and are triggered according to some specific behaviors, like explained below:

### Leader Key
- The Leader Key can be triggered holding the comma key. This allow easy access to leader sequences.

### Pontuation Hold
- Holding a pontuation key (dot, comma or semicollon) will add it to the end of the current line.

### Sentence Case
- Tapping Space after `.`, `?` or `!` will trigger ONESHOT SHIFT when the next key is pressed, so that it gets capitalized. Repeat key can be used to cancel this behavior, and it will also expire after one second if no other key is pressed.
- The implementation was based on [Pascal's](https://github.com/getreuer/qmk-keymap) implementation, but it does not work the same way.

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

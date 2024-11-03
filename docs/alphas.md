# rafaelromao's keyboard layout

## Two Alpha Layers
- This is a split keyboard layout with 24  keys, in the formats 1333+2.
- This layout works well with the OS configured for US International keyboards.
- It was designed mostly for coding and typing in Portuguese and English.
- It reduces the usage of pinkies and indexes and considers the right hand as dominant.
- The alpha layout is [Romak](https://github.com/rafaelromao/romak), a new keyboard layout, with all vowels on the right hand.

### Primary Alpha Layer
- The Alpha1 layer is the base layer, which contains the most common alphas of Portuguese and English, plus comma and period. It is extended by the Alpha2 layer.

### Secondary Alpha Layer
- The Alpha2 layer has common Portuguese accentuated letters, readily available with a single tap on the right inner thumb key, along with the alphas that are missing in the base layer.
- There are dedicated keys for `à` `á` `â` `é` `ê` `ó` `ô` `ú` `í` and `ç`, as well, which is all that is needed for Portuguese.
- This two alpha layers approach is based on [Ben Vallack's keymap](https://youtu.be/5RN_4PQ0j1A?si=f9OkOvNdL3jE4seR).

#### Ç Extension
- There is an extension to the Secondary Alpha Layer, which I call *Ç Extension*. It activates an one-shot layer just after `ç` is typed, to allow easy access to `ã`, `õ` and macros for `ão` and `ões`.

### Magic Key
- The Bottom Row Index Key, in the right hand, is programmed to act as a Magic Key. It will behave like `H` after consonants and like `V` after vowels. To see more about that, check the [Magic Romak](https://github.com/rafaelromao/romak/tree/main?tab=readme-ov-file#magic-romak) page.

#### Reversed Magic Key
- The Reversed Magic Key replaces the `V` in the secondary alpha layer and will type `V` by default but `H` after vowels, producing the reversed result of the Magic Key.

### Repeat Key
- The outer left thumb key repeats the last key by default, but outputs an alternate result for keys that do not worth repeating.
- Holding this key in the base layer will activate the [Navigation](../navigation.md) layer.
- Tapping or holding this key in the [Raise](../symbols.md) layer acts as a normal Repeat Key, which can be used to spam or to repeat shortcuts. 

### Thumb Shift
- The one-shot Shift key is available in the right outer thumb key and will toggle the Shift modifier in one-shot mode when single tapped.

### Caps Word / Caps Line
- Caps Word will captalize a single word and return to normal mode after a word break.
- Caps Line will be similar to Caps Word, but will not break after a word, but only after a line break.
- Caps Line and Caps Word are available in the base layer outer thumb keys when the one-shot shift is activated.

## Home Block Mods

[Home Block Mods](https://precondition.github.io/home-row-mods#alternative-home-row-mods-layout) are an alternative to [Home Row Mods](https://precondition.github.io/home-row-mods), but with the pinky key replaced by the index column key in the bottom row.

- Home block modifiers are available on both sides of the [Base](base.md) and [Numpad](symbols.md#numpad-layer) layers.
- Home block modifiers are not available on Lower and Raise layers, since they delay the symbol activation and are not that much useful anyway.

## Shortcut Combos
- Combos are available in the base layer to send ENTER, ESC, TAB and common shortcuts like copy, paste, save, select all and undo.
- Most combos include the home thumb key, the one in the same side.
- If shift or any other modifier is held, it will be included in the combo. So hold Shift and tap the Undo combo will send Redo instead.

### Sentence Case
- Tapping Space after `.`, `?` or `!` will trigger ONESHOT SHIFT when the next key is pressed, so that it gets capitalized. Repeat key can be used to cancel this behavior, and it will also expire after one second if no other key is pressed.
- The implementation was based on [Pascal's](https://github.com/getreuer/qmk-keymap) implementation, but it does not work the same way.

### Panic Mode Combo
- All fixable layers have a Panic Mode combo that returns the keyboard to the base layer. This combo is formed by the top three keys in the left side of the keyboard.

### Secrets
- Secret combos and leader sequencies can be included in the files [secret.h](https://gist.github.com/rafaelromao/29b444b8b0bdec5402067beb35c2bcda) and [secret.c](https://gist.github.com/rafaelromao/76be290d7d58176699b8e20859c15618). These files are not part of the repo, for obvious reasons, so these two gists are provided as templates.

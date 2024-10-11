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
- The Alpha2 layer has common Portuguese accentuated letters, readily available with a single tap on the right inner thumb key, along with the alphas that are missing in the base layer.
- There are dedicated keys for `à` `á` `â` `é` `ê` `ó` `ô` `ú` `í` and `ç`, as well, which is all that is needed for Portuguese.
- This two alpha layers approach is based on [Ben Vallack's keymap](https://youtu.be/5RN_4PQ0j1A?si=f9OkOvNdL3jE4seR).

#### Ç Extension
- There is an extension to the Secondary Alpha Layer, which I call *Ç Extension*. It activates an one-shot layer just after `ç` is typed, to allow easy access to the vowels and accentuated vowels that are commonly seen after `ç`, in Portuguese, so that typing common bigrams like `çã` and `çõ` will not require two consecutive activations of the Secondary Alpha Layer. The characters `a`, `ã`, `â`, `o`, `ô`, `õ`, `u` and `ú` are available in this layer, while `e`, `é`, `ê` and `í` are not, since they will never appear after `ç`. The position of these characters in the secondary alpha layer is also thought to support this.

### Magic Key
- The Bottom Row Index Key, in the right hand, is programmed to act as a Magic Key. It will behave like `H` after consonants and like `V` after vowels. To see more about that, check the [Magic Romak](https://github.com/rafaelromao/romak/tree/main?tab=readme-ov-file#magic-romak) page.

#### Reversed Magic Key
- The Reversed Magic Key replaces the `V` in the secondary alpha layer and will type `V` by default but `H` after vowels, producing the reversed result of the Magic Key.

## Smart Thumb Keys
- The Smart Thumb keys in this layout change behavior according to the context (active layer, active modifiers and more).
- The four thumb keys control layer transitions, when held (Navigation, Lower, Raise and Media).

### Repeat Key
- The outer left thumb key repeats the last key by default, but outputs an alternate result for keys that do not worth repeating. For `Ç`, the repeat key reactivates the Secondary Alpha Layer, which makes it easier to type `çã` and `çõ`.
- Holding this key in the base layer will activate the [Navigation](../navigation.md) layer.
- Tapping or holding this key in the [Raise](../symbols.md) layer acts as a normal Repeat Key, which can be used to spam or to repeat shortcuts. 

### Caps Word / Caps Line
- Caps Word will captalize a single word and return to normal mode after a word break.
- Caps Line will be similar to Caps Word, but will not break after a word, but only after a line break.

### Smart Shift / Caps Word
- The OS Shift key is available in the right outer thumb key and will toggle the Shift modifier in one-shot mode when single tapped.
- When double tapped, this key will activate Caps Word.

## Base Layer Combos
- Combos are available in the base and [Numpad](symbols.md#numpad-layer) layers to send ENTER, ESC, TAB and common shortcuts like copy, paste, save, select all and undo.
- Most combos include the home thumb key, the one in the same side.
- If shift or any other modifier is held, it will be included in the combo. So hold Shift and tap the Undo combo will send Redo instead.

## Base Layer Macros
- Some macros are available in the base layers and are triggered according to some specific behaviors, like explained below:

### Leader Key
- The Leader Key is available in the Base layer, holding and releasing comma for 175 milisseconds. It gives easy access to some useful macros, like typing an internet domain or recurring terminal commands.

### Pontuation Hold
- Holding a pontuation key (dot, comma or semicolon) will add it to the end of the current line.

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

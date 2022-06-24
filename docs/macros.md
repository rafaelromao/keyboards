# rafaelromao's keyboard layout

## N-Grams and Macros
- The N-Grams and Macros layers complement the base layer and are easy to access.

### N-Grams and Accents
- The N-Grams and Accents layer has common English and Portuguese n-grams and accentuated letters, readily available on a single tap of the left outer thumb key, making them as easy to type as a shifted key (which is available on a single tap of the right outer thumb key).

#### N-Grams
- N-grams that involve h, like th, ch, wh, are available in this layer.
- The inspiration for this layer came from [this post](https://www.reddit.com/r/KeyboardLayouts/comments/t3i523/ri%C3%BEinquing_h_digra%CF%86s/).
- Source code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

#### Accentuation
- There are dedicated accentuation keys for à á ã â é ê õ ó ô ú í and ç, which is all that is needed for Portuguese. These keys are positioned below or close to their corresponding vowels, making them easy to assimilate.
- It is also possible to accentuate using dead keys, like usually done with the US International layout. To get a dead version of ' " ^ ~ or ` to accentuate a letter, just press shift before the keys that output these symbols, then type the letter you want to accentuate. I.e.: Shift " u produces ü. 
- Source code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

### Macros
- A Macros layer can be activated holding any of the home row pinky keys.
- The Macros layer not only gives access to some common programming macros but also some complex ones, like Select Word, Window Swapper and the ability to record and play Dynamic Macros, as well as the inverted space and backspace keys and the IDE Dancing feature.

#### Zoom Controls
- In the right side of the Macros layer, there are keys to control Zoom, which can be either Cmd+ and Cmd- or Ctrl+ and Ctrl-, according to the operating system that is selected.

#### Leader Key
- Although not available in the Macros layer, the Leader Key is an important tool to play macros.
- The Leader Key is available through a double tap in the comma.
- The Leader Key is used to give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../src/qmk/users/rafaelromao/features/leader.c)

#### Window Swapper
- Window Swapper is a macro that performs Alt-Tab on Windows/Linux and Cmd+Tab on MacOS, holding the modifier between keypresses. 
- There are dedicated keys to swap windows back and forth.
- Source Code: [window_swapper.c](../src/qmk/users/rafaelromao/features/window_swapper.c)

#### Select Word
- Select Word is a macro that selects the current word in the first press and extend the selection to the next word in consecutive presses.
- If shift is held (or in one-shot mode), this macro will select the line instead, and extend the seletion to the next line in consecutive presses.
- This macro is also OS aware and works the same way on Windows, Linux and MacOS.
- There are dedicated keys for this macro, in the Macros layer.
- Source Code: [select_word.c](../src/qmk/users/rafaelromao/features/select_word.c)

#### Comment Lines
- This macro comments/uncomments the current line or selected block.
- Source Code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

#### Join Lines
- This macro joins the current line with the line bellow it.
- Source Code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

#### Dynamic Macros
- There is a independent dynamic macro recording key in the Macros layer.
- Double tapping them will start or stop recording a dynamic macro.
- Tapping them will play the dynamic macro.
- If shift is active, it will consider the macro slot 2, otherwise it will consider the macro slot 1.
- If there is a macro being recorded, using the [Default Mod Key](modifiers.md#default-mod-and-alt-thumb-keys) to deactivate one-shot modifiers (tapping it twice) will stop recording and clear the current macro.
- Source Code: [dynamic_macro.c](../src/qmk/users/rafaelromao/features/dynamic_macro.c)

#### IDE Macros
- In the left side os the Macros layers, there are macros for the most common IDE shortcuts:
    - Build (Cmd+F9/Ctrl+F9)
    - Run Everything (Ctrl+Ctrl)
    - Go To Project Window (Cmd+1/Ctrl+1)
    - Complete Statement (Shift+Cmd+Enter/Shift+Ctrl+Enter)
    - Quick Actions (Alt+Enter)
    - Search Everywhere (Shift+Shift)
    - Find Usages (Alt+F7)
    - Refactor This (Shift+Cmd+Alt+T/Shift+Ctrl+Alt+T)
    - Show Autocomplete Options (Ctrl+Space)
    - Go To Next Error (F2)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
N-Grams and Macros |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)

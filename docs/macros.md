# rafaelromao's keyboard layout

## N-Grams and Macros
- The N-Grams and Macros layers complement the base layer and are easy to access.

### N-Grams and Accents
- The N-Grams and Accents layer has common English and Portuguese n-grams and accentuated letters readly available on a single tap of the left outer thumb key, making them as easy to type as a shifted alpha (which is available on a single tap of the right outer thumb key).

## Macros
- A Macros layer can be activated holding any of the home row pinky keys.
- The Macros layer not only gives access to some common programming macros but also a Leader key, a Select Word macro, Zoom controls and the ability to record and play Dynamic Macros, as well as the inverted space and backspace keys and the IDE Dancing feature.

### Leader Key
- The Leader Key is available in the left side of the Macros layer, but a double tap in the comma will also activate it.
- The Leader Key is used to give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../src/qmk/users/rafaelromao/features/leader.c)

### Select Word
- Select Word is a macro that selects the current word in the first press and extend the selection to the next word in consecutive presses.
- If shift is held (or in one-shot mode), this macro will select the line instead, and extend the seletion to the next line in consecutive presses.
- This macro is also OS aware and works the same way on Windows, Linux and MacOS.
- There is a dedicated key for this macro, in the left side of the Macros layer, but a combo with the middle and ring fingers in the top row on the right side of the Navigation and Media layers will also trigger it.
- Source Code: [select_word.c](../src/qmk/users/rafaelromao/features/select_word.c)

### Dynamic Macros
- There are two independent macro recording keys in the home row index key of the Macros layer.
- Double tapping them will start or stop recording a dynamic macro.
- Tapping them will play the dynamic macro.
- If there is a macro being recorded, using the [Default Mod Key](modifiers.md#default-mod-and-alt-thumb-keys) to deactivate one-shot modifiers (tapping it twice) will stop recording and clear the current macro.
- Source Code: [dynamic_macro.c](../src/qmk/users/rafaelromao/features/dynamic_macro.c)

### Zoom Controls
- In the right side of the Macros layer, there are keys to control Zoom, which can be either Cmd+ and Cmd- or Ctrl+ and Ctrl-, according to the operating system that is selected.

### IDE Dancing
- Also in the Macros layers, which means, when holding any of the home row pinky keys, the outer thumb keys can be used to tap dance through some of the most common IDE shortcuts, using keybindings from IntelliJ IDEA.
- Left Side:
    - Tap = Build (Cmd+F9/Ctrl+F9)
    - Double Tap = Run Everything (Ctrl+Ctrl)
    - Triple Tap = Find Usages (Alt+F7)
    - Hold = Complete Statement (Shift+Cmd+Enter/Shift+Ctrl+Enter)
- Right Side:
    - Tap = Quick Actions (Alt+Enter)
    - Double Tap = Search Everywhere (Shift+Shift)
    - Triple Tap = Go To Project Window (Cmd+1/Ctrl+1)
    - Hold = Refactor This (Shift+Cmd+Alt+T/Shift+Ctrl+Alt+T)
- Two other extremely helpful shortcuts are Ctrl+Space (Show Autocomplete Options) and F2 (Go To Next Error), but they are easy to type and don't need to be included in the dancing.
- Source code: [tapdance.c](../src/qmk/users/rafaelromao/features/tapdance.c)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
N-Grams and Macros |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)

# rafaelromao's keyboard layout

## Accents and Macros

### Accents
- The Accents layer has common Portuguese accented letters, readily available on a single tap of the left outer thumb key, making them as easy to type as a shifted key (which is available on a single tap of the right outer thumb key).
- These layer also gives access to z and x, that are not available in the base layer, as well as an standalone apostrophe character.
- There are dedicated accent keys for à á ã â é ê õ ó ô ú í and ç, which is all that is needed for Portuguese.
- It is also possible to accent using dead keys, like usually done with the US International layout. To get a dead version of ' " ^ ~ or ` to accent a letter, just press shift before the keys that output these symbols, then type the letter you want to accent. I.e.: Shift " u produces ü. 
- Source code: [accents.c](../src/qmk/users/rafaelromao/features/accents.c)

### Macros
- A Macros layer can be activated holding any of the home row pinky keys.
- The Macros layer not only gives access to some common programming macros and shortcuts but also some complex features, like Select Word, Window Swapper and the ability to record and play Dynamic Macros, as well as the inverted space and backspace keys.

#### Leader Key
- Although not available in the Macros layer, the Leader Key is an important tool to play macros.
- The Leader Key is available through a double tap in the comma.
- The Leader Key is used to give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../src/qmk/users/rafaelromao/features/leader.c)

#### Swapper
- Swapper is a set of macros that allows easy navigation between applications, tabs, navigation history and zoom.
- These macros will work according to the OS selected in the Maintenance layer.
- There are two pairs of dedicated keys.
- Source Code: [swapper.c](../src/qmk/users/rafaelromao/features/swapper.c)
##### Applications and Tabs
- The first pair swaps back and forth on applications.
- If shift is active in the first tap, they navigate between the current application tabs instead.
##### History and Zoom
- The second pair will navigate in the browser history.
- If shift is active in the first tap, they will decrease or increase zoom.
- Tapping both keys will refresh the current browser tab.
- If shift is active when tapping both keys, they will clear cache and refresh the current browser tab.

#### Select Word and Select Lines
- These two macros selects the current word or line in the first press and extend the selection to the next ones in consecutive presses.
- This macro is also OS aware and works the same way on Windows, Linux and MacOS.
- Source Code: [select_word.c](../src/qmk/users/rafaelromao/features/select_word.c)

#### Comment Lines
- This macro comments/uncomments the current line or selected text block.
- Source Code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

#### Join Lines
- This macro joins the current line with the line bellow it.
- Source Code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

#### Dynamic Macros
- There is an independent dynamic macro recording key in the Macros layer.
- Double tapping it will start or stop recording a dynamic macro.
- Tapping it will play the dynamic macro.
- If shift is active, it will consider the macro slot 2, otherwise it will consider the macro slot 1.
- If there is a macro being recorded, use the thumb modifier keys to stop recording and clear the current macro.
- Source Code: [dynamic_macro.c](../src/qmk/users/rafaelromao/features/dynamic_macro.c)

#### IDE Macros
- In the left side os the Macros layers, there are macros for the most common IDE shortcuts:
    - Complete Statement (Shift+Cmd+Enter / Shift+Ctrl+Enter) - If shifted, it will show the Generate menu
    - Type-matching Auto Complete (Ctrl+Shift+Space) - If shifted, it will show Basic Auto Complete Options (Ctrl+Space)
    - Next Error (Shift+F2) - If shifted, it will go to Next Warning (F2)
    - Search Everywhere (Shift+Shift) - Hold will act as Shift
    - Run Everything (Ctrl+Ctrl)
    - Quick Actions (Alt+Enter)
    - Build (Cmd+F9 / Ctrl+F9)
    - Project Files (Cmd+1 / Ctrl+1)
    - Recent Files (Cmd+E / Ctrl+E)
    - Find Usages (Alt+F7) - If shifted, it will go to Type Definition (Shift+Cmd+B / Shift+Ctrl+B)
    - Rename (Alt+F6) - If shifted, it will show other Refactor options (Ctrl+T / Shift+Ctrl+Alt+T)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
Accents and Macros |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)

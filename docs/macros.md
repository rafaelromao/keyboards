# rafaelromao's keyboard layout

## Accents and Macros

### Accents
- The Accents layer has common Portuguese accented letters, readily available on a single tap of the left outer thumb key, making them as easy to type as a shifted key (which is available on a single tap of the right outer thumb key).
- These layer also gives access to z and x, that are not available in the base layer, as well as an standalone apostrophe character.

#### Accents
- There are dedicated accent keys for à á ã â é ê õ ó ô ú í and ç, which is all that is needed for Portuguese.
- It is also possible to accent using dead keys, like usually done with the US International layout. To get a dead version of ' " ^ ~ or ` to accent a letter, just press shift before the keys that output these symbols, then type the letter you want to accent. I.e.: Shift " u produces ü. 
- Source code: [accents.c](../src/qmk/users/rafaelromao/features/accents.c)

### Macros
- A Macros layer can be activated holding any of the home row pinky keys.
- The Macros layer not only gives access to some common programming macros and shortcuts but also some complex features, like Select Word, Window Swapper and the ability to record and play Dynamic Macros, as well as the inverted space and backspace keys.

#### Zoom Controls
- In the right side of the Macros layer, there are keys to control Zoom, which can be either Cmd+ and Cmd- or Ctrl+ and Ctrl-, according to the operating system that is selected.

#### Leader Key
- Although not available in the Macros layer, the Leader Key is an important tool to play macros.
- The Leader Key is available through a double tap in the comma.
- The Leader Key is used to give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../src/qmk/users/rafaelromao/features/leader.c)

#### Window Swapper
- Window Swapper is a macro that allows easy navigation between applications, tabs and navigation history.
- There are dedicated keys to swap back and forth.
- On tap, these two keys navigate back and forth between application windows.
  - If shift is active in the first tap, they navigate between the current application tabs instead.
  - Tapping both keys will refresh the current browser tab.
- A long press will navigate in the browser history.
  - Holding both keys will clear cache and refresh the current browser tab.
  - These actions are executed when the key is released.
- These macros will work according to the OS selected in the Maintenance layer.
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
- There is an independent dynamic macro recording key in the Macros layer.
- Double tapping it will start or stop recording a dynamic macro.
- Tapping it will play the dynamic macro.
- If shift is active, it will consider the macro slot 2, otherwise it will consider the macro slot 1.
- If there is a macro being recorded, use the Default Mod key to stop recording and clear the current macro.
- Source Code: [dynamic_macro.c](../src/qmk/users/rafaelromao/features/dynamic_macro.c)

#### IDE Macros
- In the left side os the Macros layers, there are macros for the most common IDE shortcuts:
    - Complete Statement (Shift+Cmd+Enter / Shift+Ctrl+Enter) - A long press will show the Generate menu
    - Type-matching Auto Complete (Ctrl+Shift+Space) - A long press will show Basic Auto Complete Options (Ctrl+Space)
    - Next Error (Shift+F2) - A long press will go to Next Warning (F2)
    - Search Everywhere (Shift+Shift) - Hold will act as Shift
    - Run Everything (Ctrl+Ctrl)
    - Quick Actions (Alt+Enter)
    - Build (Cmd+F9 / Ctrl+F9)
    - Project Files (Cmd+1 / Ctrl+1)
    - Recent Files (Cmd+E / Ctrl+E)
    - Find Usages (Alt+F7) - A long press will go to Type Definition (Shift+Cmd+B / Shift+Ctrl+B)
    - Refactor (Alt+F6) - A long press will show the Refactor options (Ctrl+T / Shift+Ctrl+Alt+T)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
Accents and Macros |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)

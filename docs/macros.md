# rafaelromao's keyboard layout

## Accents and Macros

### Accents
- The Accents layer has common Portuguese accented letters, readily available with a single tap on the left outer thumb key (OS Accents), making them as easy to type as shifted letters, which are available with a single tap on the right outer thumb key (OS Shift).
- This layer also gives access to q, y, z and x, that are not available in the base layer, for the 28 keys variant, as well as an standalone apostrophe character.
- There are dedicated accent keys for à á ã â é ê õ ó ô ú í and ç, which is all that is needed for Portuguese.
- It is also possible to accent using dead keys, like usually done with the US International layout.
- Source code:
  - [QMK] [accents.c](../src/qmk/users/rafaelromao/features/accents.c)
  - [ZMK] [accents.dtsi](https://github.com/rafaelromao/keyboards/blob/main/src/zmk/config/rafaelromao/features/accents.dtsi) 

### Macros
- A Macros layer can be activated holding any of the home row pinky keys.
- The Macros layer not only gives access to some common programming macros and shortcuts but also some complex features, like Select Word, Window Swapper and the ability to record and play Dynamic Macros, as well as the inverted space and backspace keys.

#### Leader Key
- The Leader Key is available in the Macros layer and can give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../src/qmk/users/rafaelromao/features/leader.c)

#### Swapper
- Swapper is a set of macros that allows easy swap between applications, tabs, navigation history and zoom levels.
- These macros will work according to the OS selected in the Maintenance layer.
- There are two pairs of dedicated keys.
- Source Code: [swapper.c](../src/qmk/users/rafaelromao/features/swapper.c)
##### Applications and Tabs
- The first pair swaps back and forth between applications.
- If shift is active in the first tap, they navigate between the current application tabs instead.
    - And tapping both keys will close the current browser tab.
##### History and Zoom
- The second pair will decrease or increase zoom.
- If shift is active in the first tap, they will navigate in the browser history instead.
- Tapping both keys will refresh the current browser tab.
- If shift is active when tapping both keys, they will clear cache and refresh the current browser tab.

#### Select Word and Select Line
- These two macros selects the current word or line in the first press and extend the selection to the next ones in consecutive presses.
- These macros are also OS aware and works the same way on Windows, Linux and MacOS.
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

#### Coding Shortcuts
- In the left side os the Macros layers, there are shortcuts for the most common actions in IntelliJ.
    - Quick Actions (Alt+Enter) - If shifted, toggle a breakpoint in the current line (Cmd+F8 / Ctrl+F8).
    - Type-matching Auto Complete (Ctrl+Shift+Space) - If shifted, show Basic Auto Complete Options (Ctrl+Space)
    - Show Quick Docs (F1 / Ctrl+Q) - If shifted, show Parameters Info (Cmd+P / Ctrl+P)
    - Find Symbol (Cmd+Option+O / Ctrl+Alt+Shift+N) - If shifted, Find Action (Cmd+Shift+A / Ctrl+Shift+A) - Hold will act as Shift
    - Run (Ctrl+R / Shift+F10) - If shifted, Stop (Cmd+F2 / Ctrl+F2)
    - Debug (Ctrl+D / Shift+F9) - If shifted, Resume (Cmd+Option+R / F9)
    - Build (Cmd+F9 / Ctrl+F9) - If shifted, Rebuild (Cmd+Shift+F9 / Ctrl+Shift+F9)
    - Project Files (Cmd+1 / Alt+1) - If shifted, Select In (Option+F1 / Alt+F1)
    - Recent Files (Cmd+E / Ctrl+E) - If shifted, show Previous Error (Shift+F2)
    - Complete Statement (Cmd+Shift+Enter / Ctrl+Shift+Enter) - If shifted, show Next Error (F2)
    - Show Usages (Cmd+Option+F7 / Ctrl+Alt+F7) - If shifted, show Quick Definition (Option+Space / Ctrl+Shift+I)
    - Refactor (Ctrl+T / Ctrl+Shift+Alt+T) - If shifted, Reformat Code (Cmd+Option+L / Ctrl+Alt+L)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
Accents and Macros |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)

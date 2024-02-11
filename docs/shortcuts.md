# rafaelromao's keyboard layout

## Shortcuts

- A Shortcuts layer can be activated holding any of the home row pinky keys.
- This layer gives access to some complex features, like Select Word, Window Swapper and the ability to record and play Dynamic Macros.
- Up and Down arrows, Enter and Esc are also available in the right side of this layer to make it easier to navigate in context menus.
- There are also home row shift in the both sides to allow access to different actions when shift is active.

### Swapper
- Swapper is a set of macros that allows easy swap between applications, tabs, navigation history and zoom levels.
- These macros will work according to the OS selected in the System layer.
- The implementation was based on [Callums's](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum) implementation, but extended to support additional features.
- Source Code: [swapper.c](../src/qmk/users/rafaelromao/features/swapper.c)
#### Applications and Tabs
- The first pair swaps back and forth between applications.
- If shift is active in the first tap, they navigate between the current application tabs instead.

#### History and Zoom
- The second pair will decrease or increase zoom.
- If shift is active in the first tap, they will navigate in the browser history instead.
- If shift is active when tapping both keys, they will clear cache and refresh the current browser tab.

### Select Word and Select Line
- These two macros selects the current word or line in the first press and extend the selection to the next ones in consecutive presses.
- These macros are also OS aware and works the same way on Windows, Linux and MacOS.
- The implementation was based on [Pascal's](https://github.com/getreuer/qmk-keymap) implementation, but it does not work the same way.
- Source Code: [select_word.c](../src/qmk/users/rafaelromao/features/select_word.c)

### Dynamic Macros
- There is a dynamic macro recording key in the Shortcuts layer.
- Double tapping it will start or stop recording a dynamic macro.
- Tapping it will play the dynamic macro.
- If shift is active, it will use the macro slot 2, otherwise it will use the macro slot 1.
- If there is a macro being recorded, you can use the thumb one-shot shift key to stop recording and clear the dynamic macro.
- Source Code: [dynamic_macro.c](../src/qmk/users/rafaelromao/features/dynamic_macro.c)

## IntelliJ

- An IntelliJ layer can be activated holding the right pinky key from the Raise or Numpad layers, used to access function keys, which are common during debugging sessions.
- This layer can also be activated holding the home thumb in the right side of the shortcuts layer, which makes it possible to hold the thumb and pinky keys together in any order to activate the IntelliJ layer.
- This layer gives access to some common programming shortcuts and also some macros.
- Up and Down arrows, Enter and Esc are also available in the right side of this layer to make it easier to navigate in context menus.
- There is also a home row shift in the right side to allow access to different actions when shift is active.

### Comment Lines

- This macro comments/uncomments the current line or selected text block.
- Source Code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

### Coding Shortcuts

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
Shortcuts and Macros |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[System](system.md)

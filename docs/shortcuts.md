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

## Coding

- An Coding layer can be activated holding the right pinky key from the Raise or Numpad layers.
- This layer can also be activated holding the home thumb in the right side of the shortcuts layer, which makes it possible to hold the thumb and pinky keys together in any order to activate the Coding layer.
- This layer gives access to some common programming shortcuts and also some macros.
- Arrows, Enter and Esc are also available in the right side of this layer to make it easier to navigate in context menus.
- There is also a home row shift in the right side to allow access to different actions when shift is active.

### Coding Shortcuts

The list bellow contains my most used Coding shortcuts. The IntelliJ keymap for MacOS is used and must be configured in the desired IDE.

| Default Action | Shifted Action | Default Shortcut | Shifted Shortcut
|---|---|---|---|
| Type-matching      | Auto Complete      | Ctrl + Shift + Space | Ctrl + Space
| Quick Actions      | Generate           | Alt + Enter          | Gui + N
| Quick Docs         | Parameters Info    | F1                   | Gui + P
| Arrow Down         | Complete Statement | Down                 | Gui + Shift + Enter
| Refactor           | Reformat Code      | Ctrl + T             | Gui + Alt + L
| Comment Lines      |                    | Gui + /              |
| Project Files      | Select In          | Gui + 1              | Alt + F1
| Step Over          | Evaluate           | F8                   | Alt + F8
| Step Into          | Step Out           | F7                   | Shift + F8
| Toggle Breakpoint  | View Breakpoints   | Gui + F8             | Gui + Shift + F8
| Find Symbol        | Find Action        | Gui + Alt + O        | Gui + Shift + A
| Run                | Stop               | Ctrl + R             | Ctrl + F2
| Debug              | Resume             | Ctrl + D             | Gui + Alt + R
| Build              | Rebuild            | Gui + F9             | Gui + Shift + F9
| Recent Files       | Previous Error     | Gui + E              | Shift + F2
| Swapper            | Next Error         | Ctrl + Tab           | F2
| Show Usages        | Quick Definition   | Gui + Alt + F7       | Alt + Space

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
Shortcuts and Macros |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[System](system.md)

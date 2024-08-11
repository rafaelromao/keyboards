# rafaelromao's keyboard layout

## Shortcuts

- A Shortcuts layer can be activated holding any of the home row pinky keys.
- This layer gives access to some complex features, like Select Word, Window Swapper and the ability to record and play Dynamic Macros.
- Up and Down arrows, Enter and Esc are also available in the right side of this layer to make it easier to navigate in context menus.
- There are also home row shift in the both sides to allow access to different actions when shift is active.

### Swapper
- Swapper is a smart sub layer that makes it easier to navigate between the list of open applications.  
- Tapping the Swapper key will swap to the most recent app. Holding it will display the list of apps and the up and down arrow keys can be used to navigate.
- The idea was based on [Callums's](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum) swapper feature.

### Select Word and Select Line
- These two macros selects the current word or line in the first press and extend the selection to the next ones in consecutive presses.
- These macros are also OS aware and works the same way on Windows, Linux and MacOS.
- The implementation was based on [Pascal's](https://github.com/getreuer/qmk-keymap) implementation, but it does not work the same way.

### Dynamic Macros
- There is a dynamic macro recording key in the Shortcuts layer.
- Double tapping it will start or stop recording a dynamic macro.
- Tapping it will play the dynamic macro.
- If shift is active, it will use the macro slot 2, otherwise it will use the macro slot 1.
- If there is a macro being recorded, you can use the thumb one-shot shift key to stop recording and clear the dynamic macro.

## Coding

- A Coding layer can be activated holding the right pinky key from the Raise layers.
- This layer can also be activated tapping or holding the home thumb in the right side of the shortcuts layer, which makes it possible to hold the thumb and pinky keys together in any order to activate the Coding layer.
- This layer gives access to some common programming shortcuts and also some macros.
- Up and Down arrows, Enter and Esc are also available in the right side of this layer to make it easier to navigate in context menus.
- There are also home row shift in the both sides to allow access to different actions when shift is active.

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

## Fusion 360

A Fusion 360 layer can be activated tapping or holding the outer thumb key in the left side of the Shortcuts layer. This layer has bindings for the most common shortcuts in the right side of the board, and it is designed that way so that the left hand can be kept in a trackball all the time.

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
Shortcuts and Macros |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[System](system.md)

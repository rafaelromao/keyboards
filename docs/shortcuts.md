# rafaelromao's keyboard layout

## Shortcuts

### Shortcut Combos
Combos are available in the base and Numpad layers to send ENTER, ESC, BACKSPACE and common shortcuts like copy, paste, save, select all and undo.
- Most combos include the home thumb key, the one in the same side, to avoid misfires.
- One-shot shift can be used to invert the modifier (Ctrl vs Cmd) used in the combos.
- If shift, or any other modifier, is held, it will be included in the combo. So hold Shift and tap the Undo combo will send Redo instead.

### Select Word and Select Line
- These two macros selects the current word or line in the first press and extend the selection to the next ones in consecutive presses.
- These macros are also OS aware and works the same way on Windows, Linux and MacOS.

### Swappers
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

### Leader Key
- Although not available in the Macros layer, the Leader Key is an important tool to play macros.
- The Leader Key is available through a double tap in the comma.
- The Leader Key is used to give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../src/qmk/users/rafaelromao/features/leader.c)
### Dynamic Macros
- There is an independent dynamic macro recording key in the Macros layer.
- Double tapping it will start or stop recording a dynamic macro.
- Tapping it will play the dynamic macro.
- If shift is active, it will consider the macro slot 2, otherwise it will consider the macro slot 1.
- If there is a macro being recorded, use the thumb modifier keys to stop recording and clear the current macro.
- Source Code: [dynamic_macro.c](../src/qmk/users/rafaelromao/features/dynamic_macro.c)

### Hypers and Mehs
Hyper and Meh are two special modifiers composed by the combination of existing modifiers, Hyper = Ctrl + Alt + Shift + Cmd/Win, while Meh = Ctrl + Alt + Shift.
This combinations are usually not used by the Operation Systems or applications, so they are great for custom shortcuts.
In this keymap there is no dedicated key for these modifiers, but there are bindings for the combinations of them with some keys, available in the Navigation and Media layers. 

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

### IntelliJ Shortcuts
In the left side os the Macros layers, there are shortcuts for the most common actions in IntelliJ.
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

### Hypers and Mehs
Hyper and Meh are two special modifiers composed by the combination of existing modifiers, Hyper = Ctrl + Alt + Shift + Cmd/Win, while Meh = Ctrl + Alt + Shift.
This combinations are usually not used by the Operation Systems or applications, so they are great for custom shortcuts.
In this keymap there is no dedicated key for these modifiers, but there are bindings for the combinations of them with some keys, available in the Navigation and Media layers. 

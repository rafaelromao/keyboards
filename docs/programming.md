# rafaelromao's keyboard layout

## Programming

### Coding Dancing
- Coding Dancing is a set of macros available through tap dances (Double Tap and Triple Tap) in the Lower and Raise layers.
- It allows fast typing for some of the most frequent Java keywords and code blocks.

#### Comment Lines
- This macro comments/uncomments the current line or selected text block.
- Source Code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

#### Join Lines
- This macro joins the current line with the line bellow it.
- Source Code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

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

### VIM
- In VIM, navigation with `hjkl` should be remapped to `raei`, to use the fingers in the home position. Some other bindings should be remapped as well:

```vim
noremap A J
noremap E K
noremap I L
noremap L E
noremap K Z
noremap J A
noremap Z I
noremap R H
noremap H R

noremap a j
noremap e k
noremap i l
noremap l e
noremap k z
noremap j a
noremap z i
noremap r h
noremap h r
```
# rafaelromao's keyboard layout

## Navigation and Mouse
The Navigation and Mouse layer can be activated holding the outer left and right thumb keys, respectively.

## Navigation
- The Navigation layer gives access to [one-shot mods](modifiers.md), along with tab and esc, in the left side and VIM style navigation, along with page navigation, insert, delete, home, end and enter, in the right side.
- In VIM, navigation with hjkl should be ignored in favor of the navigation with the fingers in the home position, using the navigation layer.
    - For that to work better, hjkl should be disabled in normal and visual modes:
        ```vim
        nnoremap h <nop>
        nnoremap j <nop>
        nnoremap k <nop>
        nnoremap l <nop>
        vnoremap h <nop>
        vnoremap j <nop>
        vnoremap k <nop>
        vnoremap l <nop>
        ```
    - This trade-off turns the navigation easier and ubiquitous and makes even more sense when using other layout than qwerty.

## Mouse
- The Mouse layer is similar to the navigation layer, but replaces the arrows and page navigation by mouse and wheel navigation.

### Mouse Buttons
- The first and second mouse buttons are mirrored in both sides of the mouse layer, in the inner columns.

### Mouse Layer Toggle
- The mouse layer can be disabled, using the [Maintenance](maintenance.md) layer or a combo with the keys Home and End.
In this case, the navigation layer will be activated in its place.
Repeating the same combo toggle the mouse layer back on.
- Source code: [mouselayer_toggle.c](../src/qmk/users/rafaelromao/features/mouselayer_toggle.c)

## Leader Key
- The Leader Key is available in the left side of the Functions layer, but a double tap in the comma will also activate it.
- The Leader Key is used to give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../src/qmk/users/rafaelromao/features/leader.c)

## Select Word
- Select Word is a macro that selects the current word in the first press and extend the selection to the next word in consecutive presses.
- If shift is held (or in one-shot mode), this macro will select the line instead, and extend the seletion to the next line in consecutive presses.
- This macro is also OS aware and works the same way on Windows, Linux and MacOS.
- There is a dedicated key for this macro, in the left side of the Navigation and Mouse layers, but a combo with the middle and ring fingers in the top row on the right side will also trigger this macro.
- Source Code: [select_word.c](../src/qmk/users/rafaelromao/features/select_word.c)

## Window Swapper
- Window Swapper is a macro that performs Alt-Tab on Windows/Linux and Cmd+Tab on MacOS, holding the modifier between keypresses.
- Source Code: [window_swapper.c](../src/qmk/users/rafaelromao/features/window_swapper.c)

## Dynamic Macros
- Double or triple tapping will start or stop recording the dynamic macro 1 or 2, respectively.
- Tapping or holding will play the dynamic macro 1 or 2, respectively.
- If there is a macro being recorded, using the [Default Mod Key](modifiers.md#default-mod-key) to deactivate one-shot modifiers (tapping it twice) will stop recording and clear the current macro.
- Source Code: [dynamic_macro.c](../src/qmk/users/rafaelromao/features/dynamic_macro.c)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
Navigation and Mouse |
[Maintenance](maintenance.md) |

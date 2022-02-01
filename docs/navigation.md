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
- Once in the Navigation layer, it is still possible to toggle the layer on, using a combo. It is possible using a clone of the original Navigation layer.
- Another combo can be used to toggle the Navigation layer off.

## Mouse
- The Mouse layer is similar to the navigation layer, but replaces the arrows and page navigation by mouse and wheel navigation.
- From the Mouse layer, it is also possible to toggle the Navigation layer on with a combo, which allows single hand access to it.

### Mouse Buttons
- The first and second mouse buttons are mirrored in both sides of the mouse layer, in the inner columns.

### Mouse Layer Toggle
- The mouse layer can be disabled, using the [Maintenance](maintenance.md) layer. In this case, the navigation layer will be activated in its place.
- Source code: [mouselayer_toggle.c](../qmk/users/rafaelromao/features/mouselayer_toggle.c)

## Macros

### Select Word
- Select Word is a macro that selects the current word in the first press and extend the selection to the next word in consecutive presses.
- If shift is held, this macro will select the line instead, and extend the seletion to the next line in consecutive presses.
- This macro is also OS aware and works the same way on Windows, Linux and MacOS.
- There is a dedicated key for this macro, in the right side of the Navigation and Mouse layers, but a combo with the middle and ring fingers in the top row on the right side will trigger this macro.
- Source Code: [select_word.c](../qmk/users/rafaelromao/features/select_word.c)

### Window Swapper
- Window Swapper is a macro that performs Alt-Tab on Windows/Linux and Cmd+Tab on MacOS, holding the modifier between keypresses.
- Source Code: [window_swapper.c](../qmk/users/rafaelromao/features/window_swapper.c)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
Navigation and Mouse |
[Maintenance](maintenance.md) |

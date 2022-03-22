# rafaelromao's keyboard layout

## Navigation and Media
The Navigation and Media layer can be activated holding the outer left and right thumb keys, respectively.

## Navigation
- The Navigation layer gives access to [One-Shot Modifiers](modifiers.md#one-shot-modifiers), Enter, Tab and Esc, Insert, Delete, Home, End, Page Up, Page Down and VIM style navigation.
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

### Media
- The left side of the Media layer equals the left side of the Navigation layer and enter can also be found in the same position.
- The right side of this layer gives access to media keys, a Menu key, and a shortcut to toggle the Navigation layer on.

## Window Swapper
- Window Swapper is a macro that performs Alt-Tab on Windows/Linux and Cmd+Tab on MacOS, holding the modifier between keypresses. It is available in both Navigation and Media layer.
- Source Code: [window_swapper.c](../src/qmk/users/rafaelromao/features/window_swapper.c)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
Navigation and Media |
[Functions and Maintenance](functions.md)

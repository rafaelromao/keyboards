# rafaelromao's keyboard layout

## Navigation and Media
The Navigation and Media layer can be activated holding the outer left and right thumb keys, respectively.

### Navigation
- The Navigation layer gives access to [Standard Modifiers](modifiers.md#standard-modifiers), Enter, Tab, Insert, Delete, Home, End, Page Up, Page Down and VIM style navigation.
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
- The Media layer gives access to [One-Shot Modifiers](modifiers.md#one-shot-modifiers), Media controls, Esc and a Save shortcut.
- The right side of this layer gives access to media keys and shortcuts to toggle the Navigation or Numpad layers on or off.

### Navigation Layer Toggle
- A clone of the Navigation layer can be toggled on permanently using the Media layer.
- This clone works the same way as the original Navigation layer, but the outer right thumb key will activate the Media layer instead of the Maintenance layer.

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[N-Grams and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
Navigation and Media |
[Maintenance](maintenance.md)

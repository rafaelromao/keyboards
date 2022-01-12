# rafaelromao's keyboard layout

## Navigation and Mouse
The Navigation and Mouse layer can be activated holding the outer left and right thumb keys, respectively.
![img](https://i.imgur.com/5ZvA74r.png)

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
    - This trade-off turns the navigation easier and ubiquitous and makes even more sense when using Colemak.
- Once in the Navigation layer, it is still possible to toggle the layer on, using a combo. It is possible using a clone of the original Navigation layer.
- Another combo can be used to toggle the Navigation layer off.

## Mouse
- The Mouse layer is similar to the navigation layer, but replaces the arrows and page navigation by mouse and wheel navigation.
- From the Mouse layer, it is also possible to toggle the Navigation layer on with a combo, which allows single hand access to it.

### Mouse Buttons
- The third and fourth mouse buttons can be triggered double tapping the first and second button keys, on the right side of the mouse layer.
- The first and second buttons are mirrored in the left side of the mouse layer, but without this tap dancing, since it prevents drag and drop from working as expected.

### Mouse Layer Toggle
- The mouse layer can be disabled, using the [Maintenance](maintenance.md) layer. In this case, the navigation layer will be activated in its place.
- Source code: [mouselayer_toggle.c](../features/mouselayer_toggle.c)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
Navigation and Mouse |
[Maintenance](maintenance.md) |

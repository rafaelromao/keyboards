# rafaelromao's keyboard layout

## Navigation and Media
The Navigation and Media layer can be activated holding the outer left and right thumb keys, respectively.

### Navigation
- The Navigation layer gives access to [One-Shot Modifiers](modifiers.md#one-shot-modifiers), Enter, Tab, Insert, Delete, Home, End, Page Up, Page Down and VIM style navigation, as well as Esc and a Save shortcut.
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
        
### Media
- The Media layer gives access to [Standard Modifiers](modifiers.md#standard-modifiers), Media controls, Esc and a Save shortcut.
- The right side of this layer gives access to media keys and shortcuts to toggle the Navigation or Numpad layers on or off.

### Navigation Layer Toggle
- A clone of the Navigation layer can be toggled on permanently using the Media layer.
- This clone works the same way as the original Navigation layer, but the outer right thumb key will activate the Media layer instead of the System layer.

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Accents and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
Navigation and Media |
[System](system.md)

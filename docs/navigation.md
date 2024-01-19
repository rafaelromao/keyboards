# rafaelromao's keyboard layout

## Navigation and Media
The Navigation and Media layer can be activated holding the outer left and right thumb keys, respectively.

### Navigation
- The Navigation layer gives access to [Standard Modifiers](modifiers.md), Enter, Tab, Insert, Delete, Home, End, Page Up, Page Down and VIM style navigation, as well as Esc and a Save shortcut.
- There are also shortcuts to some common actions in this layer, like searching browser tabs, opening files explorer, calculator or a terminal. This is implemented using Meh keys and software mapping.
- In VIM, navigation with `hjkl` should be remapped to `raei`, to use the fingers in the home position. Some other bindings should be remapped as well:

```vim
noremap A J
noremap E K
noremap I L
noremap L G
noremap G E
noremap M W
noremap W M
noremap K Z
noremap J A
noremap Z I
noremap R H
noremap H R

noremap a j
noremap e k
noremap i l
noremap l g
noremap g e
noremap m w
noremap w m
noremap k z
noremap j a
noremap z i
noremap r h
noremap h r

noremap kk zz
noremap ll gg
```
        
#### Navigation Layer Toggle
- A clone of the Navigation layer can be toggled on permanently using the Shortcuts layer.
- This clone works the same way as the original Navigation layer, but the outer right thumb key will activate the Media layer instead of the System layer.

### Media
- The Media layer gives access to [Standard Modifiers](modifiers.md#standard-modifiers), Media controls, Esc and a Save shortcut.

#### Orbital Mouse
- In the left side of the Media layer, there are keys to control the mouse using the Orbital Mouse implementation by [Pascal Getreuer](https://github.com/getreuer/qmk-keymap).

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Accents and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
Navigation and Media |
[System](system.md)

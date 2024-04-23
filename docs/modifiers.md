# rafaelromao's keyboard layout

## Home Block Mods

[Home Block Mods](https://precondition.github.io/home-row-mods#alternative-home-row-mods-layout) are an alternative to [Home Row Mods](https://precondition.github.io/home-row-mods), but with the pinky key replaced by the index column key in the bottom row.

- Home block modifiers are available on both sides of the [Base](base.md) and [Numpad](symbols.md#numpad-layer) layers.
- Home block modifiers are not available on Lower and Raise layers, since they delay the symbol activation and are not that much useful anyway.

## Standard Mods

- Standard modifiers are available in [Navigation](navigation.md) the layer.
- These modifiers do not have one-shot or mod-tap behaviors, so they can be used in situations which a tap or multi tap in a modifier key is required.

## One-shot Shift Key
- The OS Shift key is available in the right outer thumb key and will toggle the Shift modifier in one-shot mode when single tapped.

## Smart Cases

Smart Cases are custom case modes activated via thumb modifiers.
- If any modifier is active or locked in one-shot mode, all these modifiers will be deactivated.
- If any Smart Case is active, and the thumb key is the right side one, it deactivates the Smart Case.
- If Shift is in one-shot mode, and no modifier is held, it activates Caps Word.
- If Shift is not in one-shot mode, and no modifier is held, it activates Shift for one-shot.
- If modifiers are held, it behaves as follows:
    - If Left Shift is held, it activates **camelCase**: Space is replaced by OSM(Shift), excluding first char.
    - If Left Control is held, it activates **CAPSWORD**: Caps Lock remains active until space or any word breaking symbol is typed.
    - If Left Shift + Left Control are held, it activates **PascalCase**: Space is replaced by OSM(Shift), including first char.
    - If Left Gui is held, it activates **snake_case**: Space is replaced by _.
    - If Left Gui + Left Control are held, it activates **STRONG_SNAKE_CASE** a.k.a **CONSTANT_CASE**.
    - If Right Gui is held, it activates **kebab-case**: Space is replaced by -.
    - If Right Control is held, it activates **CAPS LOCK**.
    - If Right Control + Right Gui are held, it activates **STRONG-KEBAB-CASE**.
    - If Right Shift is held, it activates **slash/case**.
    - If Right Control + Right Shift are held, it activates **STRONG/SLASH/CASE**.
- Any Smart Case option, including Caps Lock, will be automatically deactivated after 10 seconds of inactivity or typing space twice.
- The implementation was based on [Pascal's CapsWord](https://github.com/getreuer/qmk-keymap) and [Andrew's X-Case](https://github.com/andrewjrae/kyria-keymap), but it does not work the same way. There are no customization functions and Caps Lock is used instead of shift.

##
[Home](../readme.md) | 
[Base](base.md) |
Modifiers |
[Shortcuts and Macros](shortcuts.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[System](system.md)

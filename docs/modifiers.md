# rafaelromao's keyboard layout

## Home Block Modifiers

[Home Block Modifiers](https://precondition.github.io/home-row-mods#alternative-home-row-mods-layout) are an alternative to [Home Row Modifiers](https://precondition.github.io/home-row-mods), but with the pinky key replaced by the index colunm key in the bottom row.

- Home block modifiers are available on both sides of the [Base](base.md) and [Numpad](symbols.md#numpad-layer) layers.
- Home block modifiers are not available on lower and raise layers, since they delay the symbol activation and are not that much useful anyway.

## One-Shot Modifiers

One-Shot Modifiers are modifier keys that, when tapped, remain active until the next key is pressed or a timeout expires. 
- They are available in the [Media](navigation.md#media) layer and act as standard modifers when held.
- These modifiers will be automatically deactivated after 2 seconds. 
- They can also be activated in sticky mode, with a double tap, and remain active until manually deactivated by tapping the Default Mod or Smart Case thumb keys.

## Standard Modifiers

- Standard modifiers are available in the [Navigation](navigation.md#navigation) layer.
- These modifiers do not have one-shot behavior, so they can be used in situations which a tap or multi tap in a modifier key is required.

## Smart Case Key 

The Smart Case key is a custom key that works as Shift, Caps Word and other Smart Case modes, according to the modifier that is held when it is pressed.
- It is placed in the right outer thumb key and behaves as follows, when tapped:
    - If any modifier is active or locked in one-shot mode, all these modifiers will be deactivated.
    - If any Smart Case is active, it deactivates the Smart Case.
    - If Shift is in one-shot mode, and no modifier is held, it activates Caps Word.
    - If Shift is not in one-shot mode, and no modifier is held, it activates Shift for one-shot.
    - If modifiers are held, it behaves as follows:
        - If Shift is held, it activates **camelCase**: Space is replaced by OSM(Shift), excluding first char.
        - If Control is held, it activates **CAPSWORD**: Caps Lock remains active until space or any word breaking symbol is typed.
        - If Shift + Control are held, it activates **PascalCase**: Space is replaced by OSM(Shift), including first char.
        - If Alt is held, it activates **snake_case**: Space is replaced by _.
        - If Alt + Control are held, it activates **CONSTANT_CASE**.
        - If Gui is held, it activates **kebab-case**: Space is replaced by -.
        - If Ctrl + Gui are held, it activates **SCREAM-KEBAB-CASE**.
        - If Shift + Gui are held, it activates **slash/case**.
        - If Shift + Control + Alt are held, it activates Caps Lock.
- Any Smart Case option, including Caps Lock, will be automatically deactivated after 10 seconds of inactivity or typing space twice.
- Source code: [smart_case.c](../src/qmk/users/rafaelromao/features/smart_case.c)

## Accents Key
- The Accents key is available in the left outer thumb key and will toggle the Accents layer in one-shot mode, acting like a special shift key.
- Source code: [custom_oneshot.c](../src/qmk/users/rafaelromao/features/custom_oneshot.c)

##
[Home](../readme.md) | 
[Base](base.md) |
Modifiers |
[Accents and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)

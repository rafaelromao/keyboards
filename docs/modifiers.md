# rafaelromao's keyboard layout

## Home Block Modifiers

[Home Block Modifiers](https://precondition.github.io/home-row-mods#alternative-home-row-mods-layout) are an alternative to [Home Row Modifiers](https://precondition.github.io/home-row-mods), but with the pinky key replaced by the index colunm key in the bottom row.

- Home block modifiers are available on both sides of the [Base](base.md) and [Numpad](symbols.md#numpad-layer) layers.
- Home block modifiers are not available on lower and raise layers, since they delay the symbol activation and are not that much useful anyway.

## One-Shot Modifiers

One-Shot Modifiers are modifier keys that, when tapped, remain active until the next key is pressed or a timeout expires. 
- They are available in the [Media](navigation.md#media) layer and act as standard modifers when held.
- These modifiers will be automatically deactivated after 2 seconds. 
- They can also be activated in sticky mode, with a double tap, and remain active until manually deactivated by tapping the Default Mod thumb key.
- Source code: [custom_oneshot_mods.c](../src/qmk/users/rafaelromao/features/custom_oneshot_mods.c)

## Standard Modifiers

- Stantard modifiers are available in the [Navigation](navigation.md#navigation) layer.
- These modifiers do not have one-shot behavior, so they can be used in situations which a tap or multi tap in a modifier key is required.

## Smart Case Key 

The Smart Case key is a custom key that works as Shift, Caps Word and other Smart Case modes, according to the modifier that is held when it is pressed.
- It is placed in the right outer thumb key and behaves as follows, when tapped:
    - If any modifier is active or locked in one-shot mode, all these modifiers will be deactivated.
    - If any Smart Case is active, it deactivates the Smart Case.
    - If Shift is active or locked in one-shot mode, and no modifier is held, it activates Caps Word.
    - If Shift is not active in one-shot mode, and no modifier is held, it activates Shift for one-shot.
        - If Shift is held, it activates **camelCase**: Space is replaced by OSM(Shift), excluding first char.
        - If Control is held, it activates **CAPSWORD**: Caps Lock remains active until space or any word breaking symbol is typed.
        - If Shift + Control is held, it activates **PascalCase**: Space is replaced by OSM(Shift), including first char.
        - If Alt is held, it activates **snake_case**: Space is replaced by _.
        - If Alt + Control is held, it activates **STRONG_SNAKE_CASE**.
        - If Gui is held, it activates **kebab-case**: Space is replaced by -.
        - If Gui + Control is held, it activates **STRONG-KEBAB-CASE**.
        - If Shift + Control + Alt is held, it activates Caps Lock.
- Any Smart Case option, including Caps Lock, will be automatically deactivated after 10 seconds of inactivity.
- The Smart Case key is implemented using a custom keycode and a layer-tap.
    - The hold behavior is kept as is, but the tap behavior is intercepted and customized.
- Source code: [smart_case.c](../src/qmk/users/rafaelromao/features/smart_case.c)

## N-Grams Key
- The N-Grams key is available in the left outer thumb key and will toggle the N-Grams layer in one-shot mode, acting like a special shift key.
- Source code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

## Default Mod and Alt Thumb Keys

The Default Mod (Cmd or Ctrl) and Alt thumb keys are placed in the outer left and right thumb keys respectively, in the Media and Navigation layers, and will give access to one-shot versions of the Cmd/Ctrl or Alt keys.
- They behaves as follows, when tapped:
    - If any modifier is active or locked in one-shot mode, all these modifiers will be deactivated.
    - If no modifier is active or locked in one-shot mode, it activates the modifier in one-shot mode.
- They are implemented using a custom keycode and a layer-tap.
    - The hold behavior is kept as is, but the tap behavior is intercepted and customized.
- For the right side, this key will always activate Alt, when tapped.
- For the left side,
    - This key allows using the same key combinations for shortcuts like Cmd/Ctrl+S, Cmd/Ctrl+C and Cmd/Ctrl+V.
    - This key will activate the modifier for the current operating system, which can be selected in the maintenace layer.
        - If Mac OS is selected, the default modifier will be Cmd, otherwise it will be Ctrl.
        - If one-shot Shift is active, the default modifier will be inverted (Cmd vs Ctrl).
- Source code: [smart_thumb_keys.c](../src/qmk/users/rafaelromao/features/smart_thumb_keys.c)

##
[Home](../readme.md) | 
[Base](base.md) |
Modifiers |
[N-Grams and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)

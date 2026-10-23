# ZMK Sentence Case

A standalone Zephyr/ZMK module providing `&sentence_space`, a replacement for
`&kp SPACE`. It has no dependency on this repository's keymap, layers, adaptive
keys, or auto-layer module. It is kept here as source rather than a remote
submodule so fresh builds do not depend on an unpublished repository.

## Usage

Add this directory to `ZMK_EXTRA_MODULES`, **before adaptive-key and other
keycode observers**, then include:

```dts
#include <behaviors.dtsi>
#include <behaviors/sentence_case.dtsi>
```

Use `&sentence_space` wherever sentence-aware space is wanted, including in
macros or the tap binding of a hold-tap. Other `&kp SPACE` bindings remain plain
spaces. For example:

```dts
bindings = <&kp A &sentence_space &kp B>;

&sentence_space {
    prior-idle-ms = <2000>;
    release-after-ms = <1000>;
};
```

Space presses and releases behave like `&kp SPACE`. If the latest key press was
`.`, `!`, or `?` within `prior-idle-ms`, the space press arms a lazy, one-shot
Left Shift. The next keycode press consumes it; only keyboard letters A–Z get
shifted. Numbers, symbols, navigation, cancel, consumer keys, and modifiers
consume it without an added shift. Releases and layer-only behaviors do not
consume it. Another space consumes it without rearming. It expires after
`release-after-ms`; there is no held modifier to release on timeout.

Punctuation matching uses the previous behavior's strict modifier semantics:
plain dot or Left-Shift question/exclamation, without extra modifiers. Shift+dot
(`>`) and shortcuts are not sentence terminators. The shift is attached to the
letter's keycode event, so adaptive keys and repeat remember `LS(A)`, not `A`.
Only the first character of a macro is affected.

### Sticky shift and accents

`zmk,behavior-sentence-morph` chooses its first binding normally and its second
while capitalization is pending. It remembers the chosen binding through
release, even if that press consumes the one-shot. Both child bindings include
their own parameters; the morph itself takes none.

For example, ignore a redundant sticky-shift tap without losing a Media hold:

```dts
shift_guard: shift_guard {
    compatible = "zmk,behavior-sentence-morph";
    #binding-cells = <0>;
    bindings = <&sk LSHFT>, <&none>;
};
```

Use `&shift_guard` as the tap behavior of the normal shift/Media hold-tap.
For dead-key accent macros, select the existing shifted-accent binding with
another sentence morph. That binding must leave the dead key unshifted and
shift the vowel; a stock lazy sticky shift would otherwise modify the dead key.
The keymap's integration is in `zmk/features/sentence.dtsi`.

## Tests

The tests compile the real C behaviors into native ZMK and check its HID events;
they do not mock or reimplement the state machine. In a configured ZMK west
workspace:

```sh
python3 /path/to/zmk-sentence-case/tests/run.py \
  --zmk-app /path/to/zmk/app \
  --build-dir /path/to/sentence-tests
```

Optional `--adaptive-module /path/to/zmk-adaptive-key` and
`--auto-layer-module /path/to/zmk-auto-layer` enable integration scenarios.
Build and event logs are saved under the build directory. Repository-level
keymap wiring tests run with `python3 -m unittest discover -s zmk/tests`.

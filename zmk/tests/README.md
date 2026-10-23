# Keymap regression tests

## Fast checks (no firmware toolchain)

```sh
python3 -m unittest discover -s zmk/tests -v
```

These validate every layer's 36 positions, layer numbering, combo key positions
and layer references, sentence-case wiring, snapshot coverage, inert bindings,
and the expected HID letter/case for every direct letter binding.

Initialize the public sentence-case module before running tests on a fresh clone:
`git submodule update --init -- modules/rafaelromao/zmk-sentence-case`.

## Native ZMK integration

Inside the existing `init.sh` toolchain container, after its module cache has
been initialized by a firmware build:

```sh
scripts/test-zmk.sh
```

The test runner builds and executes the **production keymap**, with all its
external modules. It taps every binding on every layer and also holds every
directly bound hold-tap, after satisfying its prior-idle requirement. The only
excluded positions are the two bootloader bindings. Test-only controls select
layers and delimit scenarios without emitting marker keycodes. Private
`secret.dtsi` is never copied into the fixture.

`keymap.snapshot.jsonl` records HID presses/releases, effective modifier updates,
layer transitions (including locks), and mouse button/movement/scroll output.
Focused scenarios independently assert sentence starts, redundant sticky shift,
numbers/Num Word, accented capitals, adaptive/repeat, caps word and Media/Nav
holds. The standalone sentence module additionally runs 54 edge-case scenarios,
including shared-behavior concurrency, release ordering and capacity overflow.
Native time runs uncoupled from wall time, so long timeouts remain fast.

For an intentional keymap change, regenerate snapshots with the same command
used in `scripts/test-zmk.sh` for `native_keymap.py`, adding `--update`. Inspect
the snapshot diff; do not accept it just to silence a regression. The normal
test command never updates expected output. Logs and actual output are saved
under `build/zmk-tests` (override with `ZMK_TEST_BUILD_DIR`).

These are firmware simulation tests, not host-application, USB/BLE transport,
physical matrix, or real hardware tests. They cover individual taps/holds and
the named interaction scenarios, not every possible simultaneous key sequence.

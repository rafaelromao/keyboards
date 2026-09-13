# Editor keymaps for the MEHS layer

The **MEHS layer** (layer 12) emits Meh and Hyper chords, each with a
documented editor meaning. This directory is where those meanings become real
keymaps, so the layer actually does something once the firmware is flashed.

```
Meh   = Ctrl + Alt + Shift
Hyper = Meh + Gui          (Cmd on macOS, Super on Linux)
```

The intent map is `../docs/img/diagrams/keymap-drawer/keymap-drawer.yaml`
(`coding-meh:` / `coding-hyper:`, rendered to
`../docs/img/diagrams/coding-mehs.png`). The vocabulary is IntelliJ's, so
**IntelliJ is the reference** and VSCode gets the nearest equivalent.

## Installing

One script per editor, each self-contained and idempotent:

```sh
./vscode/install.sh
./intellij/install.sh
./nvim/install.sh
```

They symlink out of this directory rather than copying, so editing a keymap
here takes effect without reinstalling. Anything real already sitting at the
target is moved to `~/.keyboards-backup/<timestamp>/` first.

| Editor | Installed to |
|---|---|
| VS Code | `Code`, `Code - OSS` and `VSCodium` profiles, whichever exist |
| IntelliJ | every `IntelliJIdea*/keymaps/` config directory found |
| Neovim | a lazy.nvim spec at `~/.config/nvim/lua/plugins/coding-mehs.lua` |

IntelliJ needs one manual step the script cannot do: **Settings → Keymap →
*Mehs*.** It only reads `keymaps/` at startup, so restart the IDE if it is not
listed.

## Meh — `Ctrl+Alt+Shift`
| Chord | Action | IntelliJ | VSCode | Neovim |
|---|---|---|---|---|
| Meh+B | project tool window | `ActivateProjectToolWindow` | `workbench.view.explorer` | snacks explorer |
| Meh+M | build | `CompileDirty` | `workbench.action.tasks.build` | `:make` |
| Meh+G | format code | `ReformatCode` | `editor.action.formatDocument` | `vim.lsp.buf.format` |
| Meh+L | step out | `StepOut` | `workbench.action.debug.stepOut` | dap step_out |
| Meh+O | step over | `StepOver` | `workbench.action.debug.stepOver` | dap step_over |
| Meh+U | step into | `StepInto` | `workbench.action.debug.stepInto` | dap step_into |
| Meh+N | type match | `SmartTypeCompletion` | `editor.action.triggerSuggest` | omni-complete (insert mode) |
| Meh+S | complete statement | `EditorCompleteStatement` | `editor.action.insertLineAfter` | — |
| Meh+T | recent files | `RecentFiles` | `workbench.action.showAllEditorsByMostRecentlyUsed` | snacks recent |
| Meh+R | run | `Run` | `workbench.action.debug.run` | dap continue |
| Meh+A | debug | `Debug` | `workbench.action.debug.start` | dap continue |
| Meh+E | toggle breakpoint | `ToggleLineBreakpoint` | `editor.debug.action.toggleBreakpoint` | dap toggle_breakpoint |
| Meh+F | evaluate expression | `EvaluateExpression` | `editor.debug.action.selectionToRepl` | dap widgets.hover |
| Meh+C | comment line | `CommentByLineComment` | `editor.action.commentLine` | `gcc` |
| Meh+P | quick def | `QuickImplementations` | `editor.action.peekDefinition` | `vim.lsp.buf.definition` |
| Meh+H | quick docs | `QuickJavaDoc` | `editor.action.showHover` | `vim.lsp.buf.hover` |
| Meh+Y | go to implementation | `GotoImplementation` | `editor.action.goToImplementation` | `vim.lsp.buf.implementation` |
| Meh+Space | ai chat | `ActivateAIAssistantToolWindow` | `workbench.action.chat.open` | — |
| Meh+Enter | context actions | `ShowIntentionActions` | `editor.action.quickFix` | `vim.lsp.buf.code_action` |
| Meh+`'` / `,` | previous error | `GotoPreviousError` | `editor.action.marker.prev` | `vim.diagnostic.jump` |
| Meh+`\` / `.` | next error | `GotoNextError` | `editor.action.marker.next` | `vim.diagnostic.jump` |

## Hyper — `Ctrl+Alt+Shift+Gui`
| Chord | Action | IntelliJ | VSCode | Neovim |
|---|---|---|---|---|
| Hyper+B | select in | `SelectIn` | `workbench.files.action.showActiveFileInExplorer` | — |
| Hyper+M | rebuild | `CompileProject` | — | — |
| Hyper+G | analyze code | `InspectCode` | — | — |
| Hyper+L | search everywhere | `SearchEverywhere` | `workbench.action.quickOpen` | — |
| Hyper+O | go to symbol | `GotoSymbol` | `workbench.action.showAllSymbols` | — |
| Hyper+U | find action | `GotoAction` | `workbench.action.showCommands` | — |
| Hyper+N | code complete | `CodeCompletion` | `editor.action.triggerSuggest` | — |
| Hyper+S | refactor this | `Refactorings.QuickListPopupAction` | `editor.action.refactor` | — |
| Hyper+T | switch scheme | `QuickChangeScheme` | — | — |
| Hyper+R | stop | `Stop` | `workbench.action.debug.stop` | — |
| Hyper+A | resume | `Resume` | `workbench.action.debug.continue` | — |
| Hyper+E | view breakpoints | `ViewBreakpoints` | `workbench.debug.action.focusBreakpointsView` | — |
| Hyper+F | generate code | `Generate` | — | — |
| Hyper+C | comment block | `CommentByBlockComment` | `editor.action.blockComment` | — |
| Hyper+P | find usages | `FindUsages` | `references-view.findReferences` | — |
| Hyper+H | toggle bookmark | `ToggleBookmark` | — | — |
| Hyper+Y | go to declaration | `GotoDeclaration` | `editor.action.revealDefinition` | — |
| Hyper+`'` / `,` | previous bookmark | `GotoPreviousBookmark` | — | — |
| Hyper+`\` / `.` | next bookmark | `GotoNextBookmark` | — | — |

Meh+D, Meh+I and the K/W/V/X/Z/J/Q combos are emitted by the keyboard but have
no recorded editor intent, so nothing binds them.

## The two chords that differ per OS

Every Meh chord is identical on macOS and Linux except `,` and `.`, which the
firmware OS-morphs because macOS cannot take `Ctrl+Alt+Shift+comma`
(`src/features/shortcuts.dtsi:190-191`):

| | macOS | Linux |
|---|---|---|
| previous error / bookmark | `Ctrl+Alt+Shift+'` | `Ctrl+Alt+Shift+,` |
| next error / bookmark | `Ctrl+Alt+Shift+\` | `Ctrl+Alt+Shift+.` |

`keybindings.json` binds **both** variants, so one file serves both platforms;
the unreachable variant is simply never pressed. The IntelliJ files are split
per OS anyway, for the reason below.

## Why IntelliJ needs two files

A child keymap **replaces** the parent's shortcut list for any action it names —
it does not merge. So every action here repeats its inherited shortcuts
alongside the new chord; without that, binding Meh+G to *Reformat Code* would
silently delete `⌥⌘L`.

That makes the parent keymap load-bearing, and IntelliJ hides Mac keymaps on
Linux and vice versa (`DefaultKeymap.isBundledKeymapHidden`), so a single file
cannot name a per-OS parent:

- `Mehs-macos.xml` → `parent="Mac OS X 10.5+"`
- `Mehs-linux.xml` → `parent="$default"`

One more wrinkle: IntelliJ rewrites Ctrl→Cmd on shortcuts a Mac keymap inherits
from `$default`, but only for keymaps *named* `Mac OS X*`. Ours is named `Mehs`,
so the macOS file has that conversion pre-applied to the 20 actions that have no
explicit Mac entry. The rule reproduces all ten known macOS defaults exactly
(⌘E, ⌘/, ⌥⌘L, ⇧⌘A, ⌥⌘B, ⌘F8, ⌘F9, ⇧⌘⏎, ⌘F2, ⇧⌘F8).

**IntelliJ rewrites these files.** The install script links rather than copies,
so when you touch the keymap in Settings the IDE saves straight back through
the symlink into this directory. It normalises as it goes — keystrokes
lowercase, `disable-mnemonics` dropped, tags reordered — and XML comments do
not survive. That is why the explanations live in this README instead. A
rewritten file is still correct; check it with a `git diff` if you want to see
what the IDE changed.

### Default shortcuts these keymaps take away

The chords were not free. Each of these lost the one shortcut that collided;
their other shortcuts are untouched.

| Chord | Was | Where |
|---|---|---|
| `Ctrl+Alt+Shift+C` | Copy Reference | Linux |
| `Ctrl+Alt+Shift+S` | Project Structure | Linux |
| `Ctrl+Alt+Shift+L` | Reformat File dialog | Linux |
| `Ctrl+Alt+Shift+E` | Text Search | Linux |
| `Ctrl+Alt+Shift+B` | Previous Word With Selection | macOS |
| `Ctrl+Alt+Shift+F` | Next Word With Selection | macOS |
| `Ctrl+Alt+Shift+T` | Refactor This | both — moved to Hyper+S |
| `Ctrl+Alt+Shift+N` | Go To Symbol | both — moved to Hyper+O |

Eight plugin-declared shortcuts are cleared too, listed at the bottom of each
XML: four Database console/view actions, two Kotlin refactorings, and the two
console commit actions on `Ctrl+Alt+Shift+Enter`.

In VSCode no removals are needed — a user keybinding always beats a default.

## Where VSCode falls short

Bound to the nearest native command, no extensions:

| Action | Substitute |
|---|---|
| type match | `editor.action.triggerSuggest` (VSCode has no smart-type completion) |
| complete statement | `editor.action.insertLineAfter` |

Left unbound, because nothing native comes close:

- **rebuild** — `workbench.action.tasks.rebuild` looks real but is commented out in VSCode's source and fails silently
- **analyze code**, **switch scheme**, **generate code**
- **toggle / previous / next bookmark** — needs `alefragnani.Bookmarks`
  (`bookmarks.toggle`, `bookmarks.jumpToPrevious`, `bookmarks.jumpToNext`)

`go to declaration` maps to `editor.action.revealDefinition` rather than
`revealDeclaration`: IntelliJ's `GotoDeclaration` (⌘B) is functionally VSCode's
Go to Definition, and many language servers do not implement declaration.

## Neovim

Only the **Meh** layer is bound. `Ctrl+Alt+Shift+<letter>` cannot be expressed
in legacy terminal encoding at all — it needs the [Kitty keyboard
protocol](https://sw.kovidgoyal.net/kitty/keyboard-protocol/) (CSI-u), which
encodes the modifier as a bitmask+1 field: Ctrl+Alt+Shift+b is `CSI 98;8u`.

So the terminal has to speak it — Ghostty, Kitty and WezTerm all do — and
tmux has to pass it through. tmux 3.4+ needs these, which belong in your own
`tmux.conf`, not here:

```tmux
set -s extended-keys always
set -s extended-keys-format csi-u
set -as terminal-features 'xterm*:extkeys'
```

Note `xterm*`, not `xterm-kitty`: Ghostty sets `TERM=xterm-ghostty`, so the
narrower match never fires. These are server options, hence `-s` / `-as`.

Mappings are written `<C-M-S-x>`; Neovim canonicalises that to `<M-C-S-X>`, so
`:verbose map` will not echo back what you typed. The debug half is dormant
until nvim-dap exists — add `lazyvim.plugins.extras.dap.core` to `lazyvim.json`
to wake it.

Inside vscode-neovim, VS Code owns these chords through its own
`keybindings.json`. The generated spec omits `vscode = true`, so LazyVim skips
the plugin there, and the module guards on `vim.g.vscode` as well.

### Hyper is deliberately not bound in Neovim

It cannot work through tmux. tmux 3.5a defines `KEYC_META`, `KEYC_CTRL` and
`KEYC_SHIFT` and no `KEYC_SUPER`; `input-keys.c` caps the emitted modifier at
`8`, so the Super bit (16) is dropped. Ctrl+Alt+Shift sits exactly at tmux's
ceiling and Hyper is one bit past it. Still true on master.

Outside tmux it would work — Neovim reads `<D-…>` from a kitty-protocol terminal
(`:help map-super-keys`) and Ghostty sends it — but Ghostty already binds
`super+control+shift+alt+arrow_*` itself, and Hyprland grabs Super first on
Linux. If you ever want it, bind Ghostty to emit an explicit `csi:` sequence
that tmux can carry, rather than relying on native Super.

To check what actually arrives, run `sed -n l` in the terminal and press the
chord: a CSI-u sequence means it got through, a bare letter means it did not.

## Regenerating

The keymaps were generated from one table so the editors cannot drift. If you
change a binding, change it in `../docs/img/diagrams/keymap-drawer/keymap-drawer.yaml`
first — that file is the source of intent, and `scripts/draw.sh` builds the
diagram from it.

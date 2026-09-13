#!/usr/bin/env bash
# Install the MEHS coding keybindings into VS Code.
#
#   keyboards/editors/vscode/install.sh
#
# Idempotent. One file serves macOS and Linux: the only chords that differ are
# the , and . keys, which the firmware OS-morphs, and both variants are bound.
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
. "$HERE/../common.sh"

root="$(config_root)"
info "VS Code keybindings"

found=0
for flavour in "Code" "Code - OSS" "VSCodium"; do
  dir="$root/$flavour/User"
  [ -d "$dir" ] || continue
  link "$HERE/keybindings.json" "$dir/keybindings.json"
  found=1
done

if [ "$found" -eq 0 ]; then
  warn "no VS Code profile found under $root; launch it once, then re-run."
  exit 0
fi

echo "  Reload the window (Developer: Reload Window) to pick them up."

#!/usr/bin/env bash
# Install the MEHS coding keymap into IntelliJ IDEA.
#
#   keyboards/editors/intellij/install.sh
#
# Idempotent. Two files, because a child keymap names a parent and IntelliJ
# hides Mac keymaps on Linux and vice versa; the right one is linked as
# Mehs.xml, matching the `name` attribute inside it.
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
. "$HERE/../common.sh"

case "$(uname -s)" in
  Darwin) src="$HERE/Mehs-macos.xml" ;;
  Linux)  src="$HERE/Mehs-linux.xml" ;;
  *) echo "unsupported platform: $(uname -s)" >&2; exit 1 ;;
esac

root="$(config_root)/JetBrains"
info "IntelliJ IDEA keymap"

found=0
for cfg in "$root"/IntelliJIdea*/; do
  [ -d "$cfg" ] || continue
  link "$src" "${cfg}keymaps/Mehs.xml"
  found=1
done

if [ "$found" -eq 0 ]; then
  warn "no IntelliJ config directory under $root; launch the IDE once, then re-run."
  exit 0
fi

echo "  Now pick it: Settings > Keymap > Mehs."
echo "  IntelliJ only reads keymaps/ at startup, so restart the IDE if it is not listed."

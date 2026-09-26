# shellcheck shell=bash
# Shared helpers for the editor install scripts. Sourced, never run directly.

info() { printf '\033[1;34m==>\033[0m %s\n' "$1"; }
warn() { printf '\033[1;33mwarning:\033[0m %s\n' "$1" >&2; }

# Symlink $1 to $2, moving anything real that is already there out of the way.
# Symlinks are deliberate: editing the keymap in this repo takes effect without
# reinstalling, which is the whole point of keeping them next to the keymap.
link() {
  local src="$1" dst="$2"
  [ -e "$src" ] || { warn "missing $src"; return 1; }
  mkdir -p "$(dirname "$dst")"
  if [ -e "$dst" ] && [ ! -L "$dst" ]; then
    # One directory per destination: with the timestamp alone, Code's and
    # VSCodium's keybindings.json landed on the same name and the second
    # backup silently replaced the first.
    local rel backup
    rel="${dst#$HOME/}"
    backup="$HOME/.keyboards-backup/$(date +%Y%m%d-%H%M%S)/$(dirname "$rel" | tr '/ ' '--')"
    mkdir -p "$backup"
    mv "$dst" "$backup/"
    warn "moved the existing $(basename "$dst") to $backup/"
  fi
  ln -sfn "$src" "$dst"
  echo "  linked ~/${dst#$HOME/}"
}

# Where this OS keeps per-user application config.
config_root() {
  case "$(uname -s)" in
    Darwin) printf '%s/Library/Application Support' "$HOME" ;;
    Linux)  printf '%s' "${XDG_CONFIG_HOME:-$HOME/.config}" ;;
    *) echo "unsupported platform: $(uname -s)" >&2; return 1 ;;
  esac
}

#!/usr/bin/env bash

# Instructions:
#
# First, install the dependencies:
# - socat
# Enable the systemd service:
# - systemctl --user enable ~/.config/hypr/zmk-vim-mode-watcher.service
# Register and start the service in hyprland.conf
# - exec-once = systemctl --user enable ~/.config/hypr/zmk-vim-mode-watcher.service
# - exec-once = systemctl --user start zmk-vim-mode-watcher.service
# Restart the computer

# Path to the vim mode script (same directory as this script)
ZMK_VIM_SCRIPT="$(dirname "$(realpath "$0")")/zmk-vim-mode.sh"

# Log file
LOG_FILE="/tmp/zmk-vim-mode-watcher.log"

# Apps that should enable vim mode (class)
VIM_CLASSES="code-oss,Code,obsidian,org.omarchy.nvim"

# Title prefixes that indicate we are in NeoVim (inside terminal)
NVIM_TITLES="nvim,neovim,Nvim,Neovim,git rebase -i"

# Current vim mode state (global)
VIM_MODE_ENABLED=false

# Logging function
log() {
  echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*" >> "$LOG_FILE"
}

is_vim_class() {
  local class="$1"
  [[ ",$VIM_CLASSES," == *",$class,"* ]]
}

# Check if title contains any nvim keyword
is_nvim_title() {
  local title="$1"
  IFS=',' read -ra prefixes <<< "$NVIM_TITLES"
  for prefix in "${prefixes[@]}"; do
    # Check if title contains the prefix (case-insensitive would be: shopt -s nocasematch)
    if [[ "$title" == *"$prefix"* ]]; then
      return 0
    fi
  done
  return 1
}

# Enable/disable vim mode via external script
set_vim_mode() {
  local enabled="$1"
  if [[ "$enabled" == "$VIM_MODE_ENABLED" ]]; then
    return
  fi
  if [[ "$enabled" == true ]]; then
    log "Enabling vim mode"
    "$ZMK_VIM_SCRIPT" true 2>&1 | tee -a "$LOG_FILE"
    VIM_MODE_ENABLED=true
  else
    log "Disabling vim mode"
    "$ZMK_VIM_SCRIPT" false 2>&1 | tee -a "$LOG_FILE"
    VIM_MODE_ENABLED=false
  fi
  notify-send \
    --hint=string:x-dunst-stack-tag:volume \
    --hint=string:synchronous:volume \
    -i dialog-information -t 1000 \
    "Vim Mode" \
    $([ "$enabled" = true ] && echo "ON" || echo "OFF")
}

# Handle one event from the socket2
handle_event() {
  local line="$1"
  log "Received event: $line"
  
  case "$line" in
    activewindow\>\>*)
      # Format: activewindow>>CLASS,TITLE
      local data="${line#activewindow>>}"
      local class="${data%%,*}"
      local title="${data#*,}"
      
      log "Active window: class='$class' title='$title'"
      
      if is_vim_class "$class" || is_nvim_title "$title"; then
        set_vim_mode true
      else
        set_vim_mode false
      fi
      ;;
    *)
      # Other events (optional: log if desired)
      ;;
  esac
}

# Main execution
log "=== Script started with args: $* ==="
log "ZMK_VIM_SCRIPT: $ZMK_VIM_SCRIPT"
log "XDG_RUNTIME_DIR: $XDG_RUNTIME_DIR"
log "HYPRLAND_INSTANCE_SIGNATURE: $HYPRLAND_INSTANCE_SIGNATURE"

# Check if running as daemon
if [[ "$1" == "--daemon" ]]; then
  # Daemon: connect to socket and listen for events
  log "Daemon mode activated"
  
  # Ensure Hyprland environment variables are set
  if [[ -z "$XDG_RUNTIME_DIR" || -z "$HYPRLAND_INSTANCE_SIGNATURE" ]]; then
    log "ERROR: XDG_RUNTIME_DIR or HYPRLAND_INSTANCE_SIGNATURE not set"
    exit 1
  fi
  
  socket="$XDG_RUNTIME_DIR/hypr/$HYPRLAND_INSTANCE_SIGNATURE/.socket2.sock"
  
  if [[ ! -S "$socket" ]]; then
    log "ERROR: socket not found at $socket"
    exit 1
  fi
  
  log "Successfully connected to socket: $socket"
  log "Listening for events..."
  
  socat -U - UNIX-CONNECT:"$socket" | while read -r line; do
    handle_event "$line"
  done
  
  log "Socket connection closed"
else
  # Interactive mode: run once to test
  log "Test mode: showing active window"
  
  active=$(hyprctl activewindow -j 2>/dev/null)
  
  if [[ -n "$active" ]]; then
    class=$(echo "$active" | jq -r '.class // empty')
    title=$(echo "$active" | jq -r '.title // empty')
    
    log "Active window (test): class='$class' title='$title'"
    
    if is_vim_class "$class" || is_nvim_title "$title"; then
      set_vim_mode true
    else
      set_vim_mode false
    fi
  else
    log "ERROR: Could not get active window (test)"
  fi
fi

log "=== Script ended ==="

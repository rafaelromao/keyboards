-- Vim Mode configuration
vimModeEnabled = false
currentApp = nil
appWatcher = nil
terminalFilter = nil

-- Function to set Vim mode using hs.execute as requested
local function setVimMode(enabled)
  if enabled == vimModeEnabled then return end
  vimModeEnabled = enabled

  local value = enabled and "true" or "false"
  -- Using hs.execute with the second parameter 'true' to ensure it's handled by a shell
  hs.execute("~/.hammerspoon/zmk-vim-mode.sh " .. value, true)

  hs.alert(enabled and "Vim Mode ON" or "Vim Mode OFF")
end

-- Core logic to check if current window should trigger Vim mode
local function checkVimState()
  local win = hs.window.focusedWindow()
  if not win then return end

  local appName = win:application():name()
  local winTitle = win:title() or ""

  -- 1. Check for specific GUI apps
  if appName == "Code" or appName == "Obsidian" then
    setVimMode(true)
    return
  end

  -- 2. Check for Neovim inside Ghostty
  if appName == "Ghostty" then
    if winTitle:match("nvim") then
      setVimMode(true)
    else
      setVimMode(false)
    end
    return
  end

  -- 3. Default state for other apps
  setVimMode(false)
end

-- WATCHER 1: Detects when you switch between different apps
appWatcher = hs.application.watcher.new(function(appName, event, app)
  if event == hs.application.watcher.activated then
    checkVimState()
  end
end)
appWatcher:start()

-- WATCHER 2: Detects changes inside Ghostty (entering/leaving nvim)
-- This ensures the script reacts when you type 'nvim' or 'exit'
terminalFilter = hs.window.filter.new("Ghostty")

-- Update when the window title changes (e.g. nvim starts)
terminalFilter:subscribe(hs.window.filter.windowTitleChanged, function()
  checkVimState()
end)

-- Update when focusing different windows/tabs within Ghostty
terminalFilter:subscribe(hs.window.filter.windowFocused, function()
  checkVimState()
end)


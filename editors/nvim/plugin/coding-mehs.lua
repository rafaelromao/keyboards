-- Coding shortcuts for the MEHS layer of rafaelromao/keyboards.
--
--   Meh = Ctrl+Alt+Shift, written <C-M-S-x> (Neovim canonicalises it to <M-C-S-X>)
--
-- Only the Meh layer is bound here. Hyper adds Cmd/Super, which Ghostty on
-- macOS and Hyprland on Linux may swallow before the terminal sees it; see
-- editors/README.md for how to probe that before extending this.
--
-- REQUIREMENTS: these chords are inexpressible in legacy terminal encoding.
-- They need the Kitty keyboard protocol (CSI-u), which means Ghostty (or any
-- kitty-protocol terminal) and, inside tmux, `extended-keys always`.

-- Inside vscode-neovim, VSCode owns these chords via editors/vscode/keybindings.json.
if vim.g.vscode then
  return
end

local map = function(lhs, rhs, desc)
  vim.keymap.set("n", "<C-M-S-" .. lhs .. ">", rhs, { desc = "meh: " .. desc, silent = true })
end

-- The keyboard OS-morphs , and . because macOS cannot take Ctrl+Alt+Shift+comma.
local is_mac = vim.fn.has("macunix") == 1
local PREV, NEXT = is_mac and "'" or ",", is_mac and "\\" or "."

-- ---------------------------------------------------------------------------
-- Always available
-- ---------------------------------------------------------------------------

map("g", vim.lsp.buf.format, "format code")
map("h", vim.lsp.buf.hover, "quick docs")
map("p", vim.lsp.buf.definition, "quick def")
map("y", vim.lsp.buf.implementation, "go to implementation")
map("CR", vim.lsp.buf.code_action, "context actions")
-- gcc is itself a mapping, not a command, so this one has to be recursive.
vim.keymap.set("n", "<C-M-S-c>", "gcc", { desc = "meh: comment line", silent = true, remap = true })

map(PREV, function() vim.diagnostic.jump({ count = -1, float = true }) end, "previous error")
map(NEXT, function() vim.diagnostic.jump({ count = 1, float = true }) end, "next error")

map("m", "<Cmd>make<CR>", "build")

map("b", function()
  local ok, snacks = pcall(require, "snacks")
  if ok and snacks.explorer then
    snacks.explorer()
  elseif pcall(vim.cmd, "Neotree toggle") then
    return
  else
    vim.cmd("Explore")
  end
end, "project")

map("t", function()
  local ok, snacks = pcall(require, "snacks")
  if ok and snacks.picker then
    snacks.picker.recent()
  else
    vim.cmd("browse oldfiles")
  end
end, "recent files")

-- 'type match' is IntelliJ's smart-type completion; the nearest thing Neovim
-- has is omni-completion, which only makes sense in insert mode.
vim.keymap.set("i", "<C-M-S-n>", "<C-x><C-o>", { desc = "meh: type match", silent = true })

-- ---------------------------------------------------------------------------
-- Debugging - dormant until nvim-dap is installed
--
-- LazyVim ships it as an extra that is NOT enabled here; add
-- "lazyvim.plugins.extras.dap.core" to lazyvim.json to wake these up.
-- ---------------------------------------------------------------------------

local function dap_map(lhs, fn, desc)
  map(lhs, function()
    local ok, dap = pcall(require, "dap")
    if not ok then
      vim.notify("nvim-dap is not installed (enable lazyvim.plugins.extras.dap.core)", vim.log.levels.WARN)
      return
    end
    fn(dap)
  end, desc)
end

dap_map("l", function(dap) dap.step_out() end, "step out")
dap_map("o", function(dap) dap.step_over() end, "step over")
dap_map("u", function(dap) dap.step_into() end, "step into")
dap_map("r", function(dap) dap.continue() end, "run")
dap_map("a", function(dap) dap.continue() end, "debug")
dap_map("e", function(dap) dap.toggle_breakpoint() end, "toggle breakpoint")
dap_map("f", function()
  local ok, widgets = pcall(require, "dap.ui.widgets")
  if ok then widgets.hover() end
end, "evaluate expression")

-- ---------------------------------------------------------------------------
-- Deliberately unbound: no sensible Neovim equivalent
--
--   Meh+S      complete statement
--   Meh+Space  ai chat
-- ---------------------------------------------------------------------------

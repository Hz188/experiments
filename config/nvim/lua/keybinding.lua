-- keybinding.lua

vim.g.mapleader = " "
vim.g.maplocalleader = " "
local opt = { noremap = true, silent = true }

-- visual模式下缩进代码
vim.keymap.set("v", "<", "<gv", opt)
vim.keymap.set("v", ">", ">gv", opt)

-- 配置 Neovim 快速按 'jk' 退出 Insert 模式
vim.keymap.set("i", "jk", "<ESC>", opt)

-- insert 模式下 行首行尾跳转
vim.keymap.set("i", "<C-h>", "<ESC>I", opt)
vim.keymap.set("i", "<C-l>", "<ESC>A", opt)

vim.api.nvim_set_keymap("n", "<F2>", ":NvimTreeToggle<CR>", {noremap = true, silent = true})


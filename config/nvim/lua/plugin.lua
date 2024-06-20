-- lazy.nvim
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable", -- latest stable release
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

require("lazy").setup({
    { "catppuccin/nvim", name = "catppuccin", priority = 1000 },
    { "nvim-tree/nvim-web-devicons" },
	{ "kyazdani42/nvim-tree.lua", event = "VimEnter" },
	{ "akinsho/bufferline.nvim", dependencies = { "moll/vim-bbye" } },
	{ "nvim-lualine/lualine.nvim" },
	{ "arkav/lualine-lsp-progress" },
}
)

vim.cmd.colorscheme("catppuccin")

"Basics
	set number
	set mouse=a
	set numberwidth=1
	set clipboard=unnamed
	syntax enable
	set showcmd
	set ruler
	set cursorline
	set encoding=utf-8
	set showmatch
	set relativenumber
	set laststatus=2
	set visualbell

	" Plug
	call plug#begin('~/.vim/plugged')

	Plug 'joshdick/onedark.vim'
 	Plug 'itchyny/lightline.vim'
	Plug 'jiangmiao/auto-pairs'
	Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
	Plug 'junegunn/fzf.vim'
	Plug 'easymotion/vim-easymotion'
	Plug 'scrooloose/nerdtree'
	Plug 'christoomey/vim-tmux-navigator'
	Plug 'tpope/vim-commentary'

	call plug#end()
	
	"Themes
	set t_Co=256
	let NERDTreeQuitOnOpen=1
	let g:onedark_hide_endofbuffer=1
	let g:onedark_contrast_dark="hard"
	let	g:onedark_termcolor=256
	let	g:onedark_terminal_italics=0

	colorscheme onedark
	if (empty($TMUX))
  		if (has("nvim"))
    		let $NVIM_TUI_ENABLE_TRUE_COLOR=1
  		endif
  		if (has("termguicolors"))
    		set termguicolors
  		endif
	endif


	"ligthline
	let g:lightline = {
 	\ 'colorscheme': 'onedark',
  	\ }

 	"Mapeo  
	let mapleader=" "

	nmap <Leader>s <Plug>(easymotion-s2)
	nmap <Leader>nt :NERDTreeFind<CR>

	" Termdebug
	packadd termdebug
	let g:termdebug_popup = 0
	let g:termdebug_wide = 163

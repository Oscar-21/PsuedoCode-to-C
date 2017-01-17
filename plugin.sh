

I had a real difficulty installing vim plugins on mac. 
I know for a plugin to be installed it has to be seen by runtimepath. 
According to vim docs, this is

Macintosh: "$VIM:vimfiles,
$VIMRUNTIME,
$VIM:vimfiles:after"
 First off, what does $VIM:vimfiles mean?? 
 It is certainly not $VIM/vimfiles, as (~/.vim/vimfiles) 
 does not work. So my options are

   1) put my plugin in /usr/share/vim/vim73 (my $VIMRUNTIME, which i know to be BAD)
   2) find a way to make vim look at my home directory when including plugins. I have putting my plugin in:
   ~/.vim/plugin.vim
   ~/.vim/vimfiles/plugin.vim
   ~/.vim/plugin/plugin.vim
   All to no avail. Can somebody help me out here? Thanks!



  ##### ANSWER #####


  You dont need to do anything for Vim to find your plugins and
  settings. Except actually putting them in the right place.
  On UNIX derivatives, 
  $VIM 
  refers to the directory where Vims support files were installed. 
  On Mac OS X, a UNIX derivative, 
  Vims default location is 

  /usr/bin

  and its support files are installed in 
  
  /usr/share. 
  
  Dont put your 
  
  plugins/colorschemes/scripts 
  
  in $/usr/share/vim/vim73. 
  
  Only default files should be there as they 
  will likely be changed the next time you or Apple 
  updates your install.

  On Mac OS X (or any UNIX derivative) you must put your 
  plugins/colorschemes/scripts 
  in a

  ~/.vim directory

  and your custom settings in a 

  ~/.vimrc file.

  None of these are there by default: youll have to create 
  them yourself as well as any needed sub-directories. Some 
  plugins consist of only one file, 
  
  pluginname.vim 
  
  that you should put in 
  
  ~/.vim/plugin as in:

  ~/.vim/plugin/pluginname.vim

  If the plugin and your version of Vim are compatible it should work. 
  Check the plugins page if it needs some activation command or setting. 
  Youll need to relaunch Vim anyway. Many plugins, though, are composed 
  of many files in many directories like autoload, after, doc Youll have 
  to put the files in their corresponding directories under your ~/.vim, 
  creating them as needed. Taking CtrlP as an example:

  ~/.vim/autoload/ctrlp/<many files>
  ~/.vim/autoload/ctrlp/ctrlp.vim
  ~/.vim/doc/ctrlp.txt
  ~/.vim/plugin/ctrlp.vim

  Once you are OK with the basics of plugin management in Vim you should try 
  Pathogen or Vundle or some other slution.


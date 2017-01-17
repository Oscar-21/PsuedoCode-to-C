 install details
 Copy the zip archive cvim.zip to $HOME/.vim/ (Linux/Unix) or $HOME/vimfiles 
 (on the Windows platforms) and run 
 unzip cvim.zip 
 If you have already an older version of this plug-in and you have modified the 
 template files you may want to save your templates first or copy the files from 
 the archive by hand. See also the file README.md within the zip file. 

 To enable the tools for cmake or doxygen, add these lines to ~/.vimrc : 

 letg:C_UseTool_cmake= 'yes' 
 letg:C_UseTool_doxygen = 'yes' 

 For how to enable the Doxygen templates, see Chapter 1.10.1 of the documentation: 

 :help csupport-doxygen-enable


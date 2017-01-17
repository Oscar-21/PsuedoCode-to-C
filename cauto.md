gh-Tech 
Health 
Sign Up
Language
Log In
 
        
 
Forum
How To
Download
News
Encyclopedia



 
How To 
Hardware 


The autocompletion C/C + + in vim 
 Ask a question



January 2017


Autocompletion is great feature for programmers who work on various types of programming languages like the C/C + + languages. Vim editor provides this feature under Windows or Linux. The autocompletion of C/C + + in Vim searches for words that are typed in from a file that has previously saved its tags in it. The user, with help of the hardware component of the system - i.e. the keyboard, will configure a key to jumpstart the process of looking through the stored tags. However, it would be prudent to keep an eye open for any words that do not make sense. 

Installation 
Configuration 
Use 
Links
Related: Vim c autocomplete ubuntu

This tutorial is aimed at people running Vim on Linux. Auto-complete is a familiar function to Linux users, however it can sometimes suggest words that do not make sense in context. This can be frustrating when programming, as Auto-complete may suggest, for example, a type when a method is expected at that point in the code. 


class plop(){      
  protected:      
   int plopons;      
  public:      
   plop(){}      
   void plopez(){}      
};      

int main(){      
  plop p;      
  p. // <-- Ctrl P proposera successivement : plopez, plop... alors que c'est forcment plopons      
  return 0;      
}


A plugin, based on ctags Vim enables you to create a more intelligent Auto-complete that can take into account the context in which a word is used. 
Installation
We begin by installing ctags. For example, under Debian or Debian based distributions (ubuntu, xandros etc.): 

sudo aptitude update      
sudo aptitude safe-upgrade      
sudo aptitude install exuberant-ctags


It also recovers the Vim plugin for auto-completion: 

http://www.vim.org/scripts/script.php?script_id=1520 

We will do everything regarding self-completion in ~ /. Vim: 

mkdir -p ~/.vim/tags      
mv omnicpp*zip ~/.vim      
cd ~/.vim      
unzip omnicpp*zip      
cd -


Ctags is able to consider the problem of headers QT, OpenGL, SDL. However, for the STL, you must retrieve headers "simple" here: 

http://www.vim.org/scripts/script.php?script_id=2358 

It unpacks the archive and creates tags from the STL: 

tar xjvf cpp_src.tar.bz2      
ctags -R --c++-kinds=+p --fields=+iaS --extra=+q --language-force=C++ cpp_src && mv tags ~/.vim/tags/stl


Now it generates the tags for the libraries installed (to be adapted if the libraries are installed elsewhere). For example, in the libraries OpenGL, SDL and QT, simply type the following three commands: 

c
tags -R --c++-kinds=+p --fields=+iaS --extra=+q --language-force=C++ /usr/include/GL/  && mv tags ~/.vim/tags/gl      

ctags -R --c++-kinds=+p --fields=+iaS --extra=+q --language-force=C++ /usr/include/SDL/ && mv tags ~/.vim/tags/sdl      

ctags -R --c++-kinds=+p --fields=+iaS --extra=+q --language-force=C++ /usr/include/qt4/ && mv tags ~/.vim/tags/qt4

Configuration
Now we must tell vim to load the plugin files and the different tags. To do this, simply add to the end of the file ~ /. Vimrc the following lines: 

" prrequis tags      
set nocp      
filetype plugin on      

" configure tags - add additional tags here or comment out not-used ones      
set tags+=~/.vim/tags/stl      
set tags+=~/.vim/tags/gl      
set tags+=~/.vim/tags/sdl      
set tags+=~/.vim/tags/qt4      

" build tags of your own project with CTRL+F12      
"map <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>      
noremap <F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<cr>      
inoremap <F12> <Esc>:!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<cr>      

" OmniCppComplete      
let OmniCpp_NamespaceSearch = 1      
let OmniCpp_GlobalScopeSearch = 1      
let OmniCpp_ShowAccess = 1      
let OmniCpp_MayCompleteDot = 1      
let OmniCpp_MayCompleteArrow = 1      
let OmniCpp_MayCompleteScope = 1      
let OmniCpp_DefaultNamespaces = ["std", "_GLIBCXX_STD"]      

" automatically open and close the popup menu / preview window      
au CursorMovedI,InsertLeave * if pumvisible() == 0|silent! pclose|endif      
set completeopt=menuone,menu,longest,preview


If tags were only generated for some files, comment on the other by adding to the beginning of the line. For example if we have not generated ~ /.vim/tags/gl and ~ / .vim/tags/sdl: 

set tags+=~/.vim/tags/stl      
"set tags+=~/.vim/tags/gl      
"set tags+=~/.vim/tags/sdl      
set tags+=~/.vim/tags/qt4



We just have to save the file and (re) start vim so that they reflect changes to ~ /. Vimrc. 
Use
Everything that has been previously tagged (ie in this tutorial tags STL, QT, SDL, and OpenGL) is already available in the auto completion. Simply press ctrl p or n. Once the list appears, you can use the arrows to highlight the good proposal and press enter. 

However, it is not completely finished. It should regenerate the tags of symbols (variables, functions, types ...) specific to the project that is being developed. This will once again generate a tags file. And of course, it will refresh the file every time you add, delete or change a symbol of the project so that it is current. 

As is quite common, it is recommended that you map a key on the keyboard to trigger a process of ctags. In the example file ~/.Vimrc that I gave, this is ensured by pressing F12. 
Links
http://vim.wikia.com/wiki/C++_code_completion 
http://www.vim.org/scripts/script.php?script_id=1520 
http://www.vim.org/scripts/script.php?script_id=2358 
Related
The autocompletion C/C + + in vim 
G.c/recover 
C programming software 
C m security 
Graphics programming in C 
I forget my gmail a/c's pasword how it is recovered 

 Download this article for free (PDF) 
 




Sponsored Links
You May Like


Shop The Razor Causing So Many Guys To Switch
Harry's


Why HelloFresh Will Make You Fall In Love With Cooking All Over Again
PayPath for HelloFresh


Augusta, Georgia: How 2 Boston Grads Are Disrupting a $19 Billion Industry
EverQuote Insurance Quotes


Myth: Keeping data on-site is safer than in the cloud.
Microsoft


Can Your Last Name Tell You Where You Came From?
Ancestry


This Simple Skin Fix May Surprise You
Primal Plants Supplement - Gundry MD

by Taboola
Published by netty5. Latest update on February 9, 2012 at 07:45 AM by Paul Berentzen. 
This document, titled "The autocompletion C/C + + in vim," is available under the Creative Commons license. Any copy, reuse, or modification of the content should be sufficiently credited to CCM (ccm.net).
Previous

Basic Excel Formulas 2
Next

Choosing the right Hard drive



Sponsored Links
You May Like


7 Reasons Why Glasses Should be Bought Online
GlassesUSA.com


Augusta: This Meal Service is Cheaper Than Your Local Store
Home Chef


Enter Today to Win $5,000 a Week "Forever"
Publishers Clearing House


"Shark Tank" Star's Brilliant Tip On Paying Off Mortgage
The Easy Loan Site by Bills.com

by Taboola





Subscribe to our newsletter
 
 
Sign Up Team Terms of Use Contact Policies 

health.ccm.net 




# Description:
Once is quite boring to type "gcc -o output progName.c" everytime you need to compile a C program, a made this program that allows you to compile a C program using only its name as an argument. You can also specify the output name, if you want to. If you don't, the output name will be the name of your program without the extension.

# How to run it?
To run the program you just need to type the command "./.mcc progName.c", where: ".mcc" is my program name and "progName" is the name of your C source code. As I said before you can also specify the output name, you just need to type it after your program name, like this: "./.mcc progName.c output".

# Making it easy:
In order to skip to type "./.mcc" everytime you want to run my program, you can use the bash aliases.                           

  1 - Open a terminal and type: vi .bash_aliases                                                                               
  2 - Hit i to enter in the insert mode                                                                                     
  3 - Type: alias mcc='~/.mcc'                                                                                                 
  4 - Hit Esc to enter in the command mode, then type: :wq                                                                      
  
After doing this, you will just need to type "mcc" to run the program instead of "./.mcc".
  







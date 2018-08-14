# Description:
Once is quite boring to type "gcc -o output progName.c" everytime you need to compile a C program, I made this script that allows you to compile a C program using only its name as an argument. You can also specify the output file if you want to. If you don't, the output name will be the name of your program without the extension.

# How to run it:
To run the script you just need to type the command "./.mcc progName.c", where: ".mcc" is my script and "progName" is the name of your C source code. As I said before you can also specify the output name, you just need to type it after your program name, like this: "./.mcc progName.c output".

# Making it easy:
In order to avoid typing "./.mcc" everytime you want to run my script, you can use aliases.                           

  1 - Open a terminal.\n
  2 - Type: alias mcc='/path/to/the/script'.
  
After doing this, you will just need to type "mcc" to run the script instead of "./.mcc".
  







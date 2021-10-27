                               Linux Shell in C Programming Language
                            Georgios Gerasimos Leventopoulos   csd4152  

Are working:
-cd command and exit command are working well
-also simple commands without pipes and redirections

Are not working:
-Pipes
-Redirections
-Shortcuts

In file cs345sh.c , the main fuction has a while loop which in every iteration prints a message to the cmd.
Specifically prints the userID and the current working directory. th

Reads one line from stdin kai using the function "tokenizeThePipe" the user commands are divided
where ">" exists. Then they are saved in an array of strings.

After that,  execCommands takes as an argument this array, divides this command into tokens and using tokenizeTheLine,
executes the commands.

In addition the "helpers.c" file, has the implementation of some methods that can be used from "cs345sh.c" file.
(For example methods that helps us understand if the command that the user gaved from the stdin has redirections or pipes).
Also in the "helpers.h" file, there are the signatures of these functions that are used from helpers.c (that is the interface of the helpers.c file).

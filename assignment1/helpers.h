/*  Georgios Gerasimos Leventopoulos   csd4152    */
/*  Create the Interface for C Shell   helpers.h  */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>  /* This is for chdir() */  
#include<pwd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include <sys/wait.h>

#define TRUE 1

int hasRedirections(char *command);
int hasInputRedirection(char *command);
int hasOutputRedirection(char *command);
int hasAppendRedirection(char *command);
int hasPipes(char *temp);
char **tokenizeThePipe(char *temp);
char **tokenizeTheLine(char *temp);
void printTokens(char **tokens);

/*                 Georgios Gerasimos Leventopoulos csd4152            */
/*      Create the implementation for helper methods      helpers.c    */

#include "helpers.h"

/* >   Pipes */
int hasPipes(char *pipe) {
   char **token = tokenizeTheLine(pipe);
   int i;
   i = 0;
   while(token[i] != NULL){
      if(strcmp(token[i],">") == 0)
         return 1;
      i = i + 1;
   }
   return 0;
}

/* Check if the string command contains redirections */
int hasRedirections(char *command){
   if(strstr(command, "|")  || strstr(command,"||") || strstr(command,"|||")) 
      return 1;
   return 0;
}

/* |  Input Redirection */
int hasInputRedirection(char *command) {
   char **token = tokenizeTheLine(command); /* Put tokens into the array */
   int i = 0;
   /* Check if "|" operation exists in the command */
   while(token[i]) {
      if(strcmp(token[i], "|") == 0) return 1;
      i++;
   }
   return 0;
}

/* ||  Output Redirection */
int hasOutputRedirection(char *command) {
   char **token = tokenizeTheLine(command); /* Put tokens into the array */
   int i = 0;
   /* Check if "||" operation exists in the command */
   while(token[i]) {
      if(strcmp(token[i], "||") == 0) return 1;
      i++;
   }
   return 0;
}

/* |||  Append Redirection */
int hasAppendRedirection(char *command) {
   char **token = tokenizeTheLine(command); /* Put tokens into the array */
   int i = 0;
   /* Check if "|||" operation exists in the command */
   while(token[i]) {
      if(strcmp(token[i], "|||") == 0) return 1;
      i++;
   }
   return 0;
}

/* Stores the command before ">" and command after ">" into an array of string. The same thing happens if we have 3 or more ">" */  
char **tokenizeThePipe(char *temp) {
  char **table = (char **)malloc(100*sizeof(char *)); 
  char *token;
  int j = 0;
  token = strtok(temp, ">"); /* Store first token */
  while(token) {  /* Walk through the other tokens */
    table[j] = token;
    token = strtok(NULL, " \t\r\n\a");
    j++;
  }
  /* End of the table */
  table[j] = NULL; 
  return table;
}

/* Holds the command before the first "<" and tokenize every element before every space and keeps it into an array */
char **tokenizeTheLine(char *temp) {
  char **table = (char **) malloc(100*sizeof(char *)); /* create an array of strings */
  char *token, *newString;
  int j;
  j = 0;
  newString = (char *) malloc(100);
  newString = strcpy(newString, temp);
  token = strtok(newString, " \t\r\n\a"); 
  while(token) {    /* Walk through the rest of the tokens */
    table[j] = token;
    token = strtok(NULL, " \t\r\n\a");
    j++;
  }
   /* End of table */
  table[j] = NULL;  
  /* printTokens(table);  Uncomment for Debug */
  return table;
}

/* Pirnt Method for Debugging */
void printTokens(char **tokens){
  int i = 0;
  do {
      printf("Token Number %d = %s\n", i, tokens[i]);
      i++;
  } while (tokens[i]); 
}


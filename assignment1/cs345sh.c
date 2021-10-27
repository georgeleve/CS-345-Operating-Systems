/*    Georgios Gerasimos Leventopoulos csd4152  */
/*         I create my own C Shell  cs345sh.c   */
#include "helpers.h"

void handleShortcuts(char *shortcut) {
   /* I don't need fork() (I will only use signal_handler() or termios) */
   switch (*shortcut) {
      case 'C': /* kills the program  SIGINT */
         /* kill();  */
         break;
         
      case 'H': /* backspace */
         break;

      case 'S': /* pause output */
         break;

      case 'Q': /* resume output */
         break;
   }
}

/* |   read redirection */
void handleInputRedirection(char *parameters) {
   /* dup2()    
      fopen()     "r" for input "<"   */
}  
/* ||   write redirection */
void hanldeOutputRedirection(char *parameters) {
   /* dup2() 
      fopen()      "w+"" for output ">"  */
}

/* |||   append redirection */
void handleAppendRedirection(char *parameters) {
   /* dup2() 
      fopen()    "a" for append output  */ 
}

/*  >   Pipe */
void handlePipes(char *parameters) {
   /* pipe() */
}

int executeCommands(int length, char **pipes) {
  char **tokens;
  tokens = tokenizeTheLine(pipes[0]);
  if(strcmp(tokens[0], "cd") == 0){
      chdir(tokens[1]);
      return 1;
  }else if(strcmp(tokens[0], "exit") == 0) {
      exit(-1);
  }else{
      int i;
      pid_t pid;

      pid = fork(); /* Call a new process */

      if(pid < 0) { /* Error */
         perror("Error while doing the fork()");
         exit(-1);
      }
      /* Child process */
      if (pid == 0) {
         execvp(tokens[0], tokens); /* execute command */
         printf("This should not be printed"); 
         exit(-1);
      }
      /* Parent process */
      else {   
         wait(NULL); /* Wait for the child to finish */
      }
  }
}

char *getCommands(void){
   size_t bufferLength;
   char *command;
   command = NULL;
   bufferLength = 0;
   getline(&command, &bufferLength, stdin); /* get the user commands */
   return command;
}

void typePrompt() {
   char *onScreenMessage = (char *)malloc(100 * sizeof(char));
   char *userID = getenv("USER"); /* Find login userID */
   if(!userID){
      printf("Error: Couldn't find the login user\n");
      exit(1);
   }
   strcat(onScreenMessage, "[cs345sh]["); 
   strcat(onScreenMessage, userID); /* print user ID */
   strcat(onScreenMessage, "]["); 
   strcat(onScreenMessage, getcwd(NULL,0)); /* print Current Directory */
   strcat(onScreenMessage, "]~$ ");
   printf("\n%s", onScreenMessage);
}

int main(void) {
   char *command;
   while(TRUE){ /* repeat forever */
      typePrompt(); /* Display prompt on the screen */
      command = getCommands();
      char **pipes;
      pipes = tokenizeThePipe(command);
      int length = 0;
      while(pipes[length]) length++; /* Count the commands */
      executeCommands(length, pipes);
   }
   return 0;
}

/*
   I may use these methods:
   fork(2), exec(3), execv(3), wait(2),  waitpid(2), pipe(2), dup2(2), sh(1), bash(1), chdir(2), getcwd(2), getlogin(2) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXARGS 5
#define MAXLINE 8192




void* cd(char* input) {
  // TODO: Implement cd
  chdir(input);
}

void* help(char* input) {
  // TODO: Implement cd
  printf("-------------- help ----------------\n");
  printf("-cd : open a folder\n");
  printf("-help : give you instructions\n");
  printf("-exit_Ksea : exit the terminal\n");
  printf("-game : this system will tell you a random joke\n");
}

void* exit_Ksea(char* input) {
  printf("You have already exited.\n");
  exit(0);
}

void* game(char* input) {
  printf("a random joke\n");
}
// TODO: Put your command names here
char* commands[] = { "cd", "help", "exit_Ksea", "game"};

// TODO: Put your command function pointers here
void* (*command_functions[])(char* input) = {cd, help, exit_Ksea, game};



/***
 **  Wrapper of fork(). Checks for fork errors, quits on error.
 **/
pid_t Fork(void) {
  pid_t pid;
  if ((pid = fork()) < 0) {
    fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
    exit(0);
  }
  return pid;
}

/***
 **  Wrapper of fgets. Checks and quits on Unix error.
 **/
char* Fgets(char* ptr, int n, FILE* stream) {
  char* rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}



// Is the command one built into the shell?
// That is, that the *shell* has implemented?
// If so, execute it here
int builtin_command(char** argv) {
  // Loop through
  int i = 0;
  int COMMANDS_NUMBER = 4;
  while (i < COMMANDS_NUMBER) {
    int res = strcmp(commands[i], argv[0]);// command name
    if (res == 0) { // call the right function.
      command_functions[i](argv[1]); // some argument
      return 1;
    }
    i++;
  }
  return 0; // return false
}



// divide buffer into pieces of args
void divide(char* buffer, char* argv[]){
  char* token;
  token = strtok(buffer, " ");
  argv[0] = token;
  token = strtok(NULL, " ");
  argv[1] = token;
  token = strtok(NULL, " ");
  argv[2] = token;
}


void eval(char* cmdline) {
  char* argv[MAXARGS]; /* Argument list execve() */
  char buf[MAXLINE]; /* Holds modified command line */
  pid_t pid; /* Process id */

  strcpy(buf, cmdline);
  // Split buf into args
  divide(buf, argv);

  if (argv[0] == NULL)
    return; /* Ignore empty lines */

  if (!builtin_command(argv)) {
    // Check that the command/program exists in Unix (ie /bin/) OR (see below) 
    // Create a child process 
    // Run the program/command (execve...)-- what is the result of exec if the command is bogus?
    argv[0]="/bin";
    pid = Fork();
    
    if(pid == 0){
      int res = execve(argv[0], argv, NULL); // see run_ls.c for an example
      // execve(argv[0], argv, NULL);
      if (res < 0){//print error message
        printf("There is an error command. Or there should be parameters.\n");
      } 
      exit(1);
    }
    else{
      // What do we do if it *IS* a command built into the shell?
      wait(NULL);  
    } 
  }
  
  // TODO: Be sure to wait for the child process to terminate
  printf("This is the final of this process.\n");
  return;
}



int main() {
  char cmdline[MAXLINE]; /* command line buffer */
  while (1) {
    // Print command prompt
    printf("> ");
    // Read input from user
    Fgets(cmdline, MAXLINE, stdin);
    // If we get the eof, quit the program/shell
    if (feof(stdin))
      exit(0);

    // Otherwise, evaluate the input and execute. 
    eval(cmdline);
  }
}

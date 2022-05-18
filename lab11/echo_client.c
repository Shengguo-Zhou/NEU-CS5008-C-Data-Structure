#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 999

void PrintBlue(char* str) {
  printf("\033[1;94m%s\033[0m", str);
}

void PrintYellow(char* str) {
  printf("\033[1;93m%s\033[0m", str);
}

char* Fgets(char *ptr, int n, FILE *stream) {
  char *rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}


int main() {

  struct addrinfo hints, *result;

  // Allows "global"
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET; /* IPv4 only */
  hints.ai_socktype = SOCK_STREAM; /* TCP */
  
  int s;

  s = getaddrinfo("localhost", // 127.0.0.1
                  "1234", // port
                  &hints,
                  &result);

  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  connect(sock_fd, result->ai_addr, result->ai_addrlen);

  while (1) {
  
    //  char *buffer = "COVID OVER";
    char buffer[MAXLINE];
    printf("Enter your message: ");
    // Read input from user
    Fgets(buffer, MAXLINE, stdin);

    PrintYellow("SENDING: ");
    printf("%s\n", buffer);
    write(sock_fd, buffer, strlen(buffer));
    
    char resp[1000];
    int len = read(sock_fd, resp, 999);
    resp[len] = '\0';

    PrintBlue("FROM SERVER: ");
    printf("%s\n", resp);
  }
  close(sock_fd); 
    
}

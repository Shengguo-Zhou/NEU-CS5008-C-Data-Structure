#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int do_connect(char *host, char *port) {
  int s;
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  
  struct addrinfo hints, *result;
  
  // Allows "global"
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET; /* IPv4 only */
  hints.ai_socktype = SOCK_STREAM; /* TCP */
  
  s = getaddrinfo(host, port, &hints, &result);
  
  // If I can't get the address, write an error.
  if (s != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    exit(1);
  }
  
  // Try to connect; if I can't, write an error.
  if(connect(sock_fd, result->ai_addr, result->ai_addrlen) == -1){
    perror("connect");
    exit(2);
  }
  else{
    printf("Connection is good!\n");
  }
  
  return sock_fd;
}

void send_message(char *msg, int sock_fd){
  printf("\033[1;93mSENDING: \033[0m %s", msg);
  printf("===\n");
  write(sock_fd, msg, strlen(msg));
}

void read_response(int sock_fd){
  // Response
  char resp[1000];
  int len = read(sock_fd, resp, 999);
  resp[len] = '\0';
  
  printf("\033[1;94mRECEIVED: \033[0m %s\n", resp);
}

int main(int argc, char **argv) {
  int sock_fd = do_connect("localhost", "7533");
  
  printf("socket fd (client): %d\n", sock_fd);
  
  sleep(1);
  send_message("Knock knock", sock_fd);
  read_response(sock_fd);

  sleep(1);
  send_message("doris.", sock_fd);
  read_response(sock_fd);

  sleep(1);
  send_message("door is closed. That's why I knocked!", sock_fd);
  read_response(sock_fd);
  
  close(sock_fd);
  
  return 0;
}

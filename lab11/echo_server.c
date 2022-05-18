#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int s;
    // Step 1: Get address stuff
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    s = getaddrinfo(NULL, "1234", &hints, &result);
    if (s != 0) {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
      exit(1);
    }

    // Step 2: Open socket
    int yes = 1;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    // lose the pesky "Address already in use" error message
    if (setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof yes) == -1) {
      perror("setsockopt");
      exit(1);
    } 
    
    // Step 3: Bind socket
    if (bind(sock_fd, result->ai_addr, result->ai_addrlen) != 0) {
      perror("bind()");
      exit(1);
    }

    // Step 4: Listen on the socket
    if (listen(sock_fd, 10) != 0) {
      perror("listen()");
      exit(1);
    }
    
    struct sockaddr_in *result_addr = (struct sockaddr_in *) result->ai_addr;
    printf("Listening on file descriptor %d, port %d\n", sock_fd, ntohs(result_addr->sin_port));

    // Step 5: Accept connection
    printf("Waiting for connection...\n");

    while (1) {
    
    int client_fd = accept(sock_fd, NULL, NULL);
    
    printf("Connection made: client_fd=%d\n", client_fd);
    // Step 6: Read, then write if you want
    char buffer[1000];
    int len = read(client_fd, buffer, sizeof(buffer) - 1);

    while (buffer[0] != 'x') {
      buffer[len] = '\0';
      printf("Read %d chars\n", len);
      printf("===\n");
      printf("%s\n", buffer); 
      
      write(client_fd, buffer, strlen(buffer));
      len = read(client_fd, buffer, sizeof(buffer) - 1);
    }

    printf("Got terminating signal from client...Closing connection.\n");

    // Step 7: Close
    close(client_fd);
    }
    return 0;
}

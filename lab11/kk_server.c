#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int do_open(){
        int s;

        // Step 1: Get Address stuff
        struct addrinfo hints, *result;

        // Setting up the hints struct...
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        s = getaddrinfo("localhost", "7533", &hints, &result);
        if (s != 0) {
                fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
                exit(1);
        }

        // Step 2: Create the socket
        int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

        // Step 3: Bind the socket
        if (bind(sock_fd, result->ai_addr, result->ai_addrlen) != 0) {
                perror("bind()");
                exit(1);
        }

        // Step 4: Listen
        if (listen(sock_fd, 10) != 0) {
                perror("listen()");
                exit(1);
        }

        struct sockaddr_in *result_addr = (struct sockaddr_in *) result->ai_addr;
        printf("Listening on file descriptor %d, port %d\n", sock_fd, ntohs(result_addr->sin_port));

        // Step 5: Accept a connection
        printf("Waiting for connection...\n");
        int client_fd = accept(sock_fd, NULL, NULL);
        printf("Connection made: client_fd=%d\n", client_fd);

        return client_fd;
}

void recieve_message(int client_fd){
        char buffer[1000];
        int len = read(client_fd, buffer, sizeof(buffer) - 1);
        buffer[len] = '\0';
        printf("\033[1;93mSERVER RECEIVED:\033[0m %s \n", buffer);
}

void send_message(char *msg, int sock_fd){
        printf("\033[1;94mSERVER SENDING: \033[0m%s", msg);
        printf("===\n");
        write(sock_fd, msg, strlen(msg));
}

int main(int argc, char **argv){

        int client_socket_id = do_open();

        // Step 6: Read and write
        recieve_message(client_socket_id);

        send_message("Who's there?", client_socket_id);

        recieve_message(client_socket_id);

        send_message("Doris who? ", client_socket_id);

        recieve_message(client_socket_id);
        printf("haha. not funny. \n");

        // Step 7: Close
        close(client_socket_id);

        return 0;
}

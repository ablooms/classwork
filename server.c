#include <stdio.h> // perror, printf
#include <stdlib.h> // exit, atoi
#include <unistd.h> // read, write, close
#include <arpa/inet.h> // sockaddr_in, AF_INET, SOCK_STREAM, INADDR_ANY, socket etc...
#include <string.h> // memset

int main(int argc, char const *argv[]) {
  // These lines declare some vars and allocate some buffer space
  int serverFd, clientFd;
  struct sockaddr_in server, client;
  int len;
  int port = 1234;
  char buffer[1024];

  // Conver an argument (string) to the int we'll need later
  if (argc == 2) {
    port = atoi(argv[1]);
  }
  // Make an endpoint for a connection
  serverFd = socket(AF_INET, SOCK_STREAM, 0);
  if (serverFd < 0) {
    perror("Cannot create socket");
    exit(1);
  }
  // Fillout information in a struct about the socket/connection we want
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);

  // Ask the OS to connect the socket in the way we want
  len = sizeof(server);
  if (bind(serverFd, (struct sockaddr *)&server, len) < 0) {
    perror("Cannot bind sokcet");
    exit(2);
  }
  // Start checking for connections
  if (listen(serverFd, 10) < 0) {
    perror("Listen error");
    exit(3);
  }

  while (1) {
    len = sizeof(client);
    printf("waiting for clients\n");
    // Establish the connection with a specific client
    // cliendFd is the file descriptor that will read/write with this client
    if ((clientFd = accept(serverFd, (struct sockaddr *)&client, &len)) < 0) {
      perror("accept error");
      exit(4);
    }
    // recover some metadata about the connection to display
    char *client_ip = inet_ntoa(client.sin_addr);
    printf("Accepted new connection from a client %s:%d\n", client_ip, ntohs(client.sin_port));

    // empty the buffer so that we don't expose extra stuff from memory
    memset(buffer, 0, sizeof(buffer));
    // read upto sizeof(buffer) bytes into the buffer
    int size = read(clientFd, buffer, sizeof(buffer));
    if ( size < 0 ) {
      perror("read error");
      exit(5);
    }

    printf("received %s from client\n", buffer);

    // Actually send data back to client
    if (write(clientFd, buffer, size) < 0) {
      perror("write error");
      exit(6);
    }

    // close the connection between client/server
    close(clientFd);
  }

  // closes the port we were listening on
  close(serverFd);
  return 0;
}

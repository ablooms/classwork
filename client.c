#include <stdio.h> // perror, printf
#include <stdlib.h> // exit, atoi
#include <unistd.h> // write, read, close
#include <arpa/inet.h> // sockaddr_in, AF_INET, SOCK_STREAM, INADDR_ANY, socket etc...
#include <string.h> // strlen, memset

const char message[] = "Hello sockets world\n";

int main(int argc, char const *argv[]) {

  // make some variables and give initial values
  int serverFd;
  struct sockaddr_in server;
  int len;
  int port = 1234;
  char *server_ip = "127.0.0.1";
  char *buffer = "hello server";

  // Convert the commandline inputs to what we need
  if (argc == 3) {
    server_ip = argv[1];
    port = atoi(argv[2]);
  }

  // Setup an endpoint
  serverFd = socket(AF_INET, SOCK_STREAM, 0);
  if (serverFd < 0) {
    perror("Cannot create socket");
    exit(1);
  }

  // Filling out a struct with some information about the connection we want
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(server_ip);
  server.sin_port = htons(port);

  // Actually start the connection (if possible)
  len = sizeof(server);
  if (connect(serverFd, (struct sockaddr *)&server, len) < 0) {
    perror("Cannot connect to server");
    exit(2);
  }

  // Try to write data to the server
  if (write(serverFd, buffer, strlen(buffer)) < 0) {
    perror("Cannot write");
    exit(3);
  }

  // Try and receive data from the server
  char recv[1024];
  memset(recv, 0, sizeof(recv));
  if (read(serverFd, recv, sizeof(recv)) < 0) {
    perror("cannot read");
    exit(4);
  }

  // Print out what the server sent and close the connection
  printf("Received %s from server\n", recv);
  close(serverFd);
  return 0;
}

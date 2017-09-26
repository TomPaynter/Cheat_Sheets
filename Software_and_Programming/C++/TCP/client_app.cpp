// With Modififications from:
// http://www.bogotobogo.com/cplusplus/sockets_server_client.php

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int verbose = 1;
void output(const char *msg, int should_exit)
{
    if (verbose)
      printf(msg);

    if (should_exit)
      exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    portno = 9999;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        output("ERROR opening socket", 1);

    server = gethostbyname("127.0.0.1");
    if (server == NULL)
        output("ERROR, no such host\n", 1);

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        output("ERROR connecting", 1);

    bzero(buffer,256);

    int i = 0;

    while(1) {

      int l = sprintf(buffer, "Client Message %d\n\r", i);

      n = send(sockfd, buffer, l, 0);

      if (n < 0)
           output("ERROR writing to socket", 1);


      n = read(sockfd, buffer, 255);
      if (n < 0)
           output("ERROR reading from socket", 1);

      printf("%s\n", buffer);

      i++;
    }

    close(sockfd);
    return 0;
}

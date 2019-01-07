#include <netinet/in.h>
#include <string.h>
#include "MySerialServer.h"

void MySerialServer::open(int port , ClientHandler* clientHandler) {

    int sockfd, clilen , newsockfd;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t) port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    while (true) {
        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection
        */
        listen(sockfd, 1);
        clilen = sizeof(cli_addr);

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        clientHandler->handleClient(newsockfd);
    }
}






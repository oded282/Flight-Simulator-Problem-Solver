#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "MySerialServer.h"


void *communicationServer(void *args) {
    struct TreadParms *t = (TreadParms *) args;
    int clilen , newsockfd = 0;
    struct sockaddr_in  cli_addr;


    while (true) {
        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection
        */
        listen(t->sockfd, 1);
        clilen = sizeof(cli_addr);
        int i =0;
        //time out for waiting to client.
        while (i < 10 && newsockfd <= 0){
            newsockfd = accept(t->sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
            sleep(1);
            i++;
        }
        if (i == 10){
            break;
        }

        /* Accept actual connection from the client */

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
       t-> clientHandler->handleClient(newsockfd);
    }
}



void MySerialServer::open(int port , ClientHandler* clientHandler) {

    int sockfd, clilen , newsockfd = 0;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // make the sock "no block".
    fcntl(sockfd, F_SETFL, O_NONBLOCK);

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

    TreadParms* t = new TreadParms();
    t->sockfd = sockfd;
    t->clientHandler = clientHandler;

    pthread_t pthreadS;
    pthread_create(&pthreadS, nullptr, communicationServer, (void *) t);

 /*
    while (true) {
        // Now start listening for the clients, here process will
          // * go in sleep mode and will wait for the incoming connection
        //
        listen(sockfd, 1);
        clilen = sizeof(cli_addr);
        int i =0;
        //time out for whiting to client.
        while (i < 10 && newsockfd == 0){
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
            sleep(1);
            i++;
        }
        if (i == 10){
            break;
        }

        // Accept actual connection from the client

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        clientHandler->handleClient(newsockfd);
    }
    */
}






#include <iostream>
#include "MyParallelServer.h"
#include "StringRevers.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include<pthread.h>
#include <thread>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* socketThread(void *arg){

    arg_struct arg_struct1 = *((arg_struct *)arg);
    int newSocket = arg_struct1.newSockfd;
    ClientHandler* clientHandler = arg_struct1.clientHandler;

    clientHandler->handleClient(newSocket);

    countCurrentTreaths--;
    printf("Exit socketThread \n");
    close(newSocket);
    pthread_exit(NULL);
}

void MasterOfThreads (int port, ClientHandler *c){
    ClientHandler *clientHandler = c;
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    //Create the socket.
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    // Configure settings of the server address struct
    // Address family = Internet
    serverAddr.sin_family = AF_INET;
    //Set port number, using htons function to use proper byte order
    serverAddr.sin_port = htons(port);
    //Set IP address to localhost
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //Set all bits of the padding field to 0
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    //Bind the address struct to the socket
    bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    //Listen on the socket, with 40 max connection requests queued
    if(listen(serverSocket,1) == 0 )
        printf("Listening\n");
    else
        printf("Error\n");

    pthread_t tid[60];
    while(shouldRun){

        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        setsockopt(serverSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        //Accept call creates a new socket for the incoming connection
        addr_size = sizeof serverStorage;
        arg_struct arg_struct1;
        newSocket = accept(serverSocket, (struct sockaddr *) &serverStorage, &addr_size);

        if (newSocket < 0)	{
            if (errno == EWOULDBLOCK)	{
                cout << "timeout!" << endl;
                break;
            }	else	{
                perror("other error");
                break;
            }
        }

        arg_struct1.newSockfd=newSocket;
        arg_struct1.clientHandler=clientHandler;

        //for each client request creates a thread and assign the client request to it to process
        //so the main thread can entertain next request
        if(pthread_create(&tid[countCurrentTreaths], NULL, socketThread, &arg_struct1) != 0 ) {
            printf("Failed to create thread\n");
        }
//        countCurrentTreaths++;
        if( countCurrentTreaths >= 50)
        {
            countCurrentTreaths = 0;
            while(countCurrentTreaths < 50)
            {
                pthread_join(tid[countCurrentTreaths++],NULL);
            }
            countCurrentTreaths = 0;
        }
    }
}

void MyParallelServer::open (int port, ClientHandler * c){
    std::thread th1(MasterOfThreads, port, c);
    cout<< "start MasterOfThreads"<<endl;
    th1.join();
    cout<< "end MasterOfThreads"<<endl;

}
/*

int main(){

    auto myParallelServer = new MyParallelServer();
    auto stringRevers = new StringRevers();
    auto cache = new FileCacheManager();
    auto clientHandler = new MyTestClientHandler(cache , stringRevers);

    myParallelServer->open(5400 ,clientHandler);


    return 1;
}*/

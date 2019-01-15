#include <iostream>
#include "MyParallelServer.h"


extern pthread_mutex_t mutex;

void* socketThread(void *arg){

    arg_struct arg_struct1 = *((arg_struct *)arg);

    int newSocket = arg_struct1.newSockfd;
    ClientHandler* clientHandler = arg_struct1.clientHandler;

    clientHandler->handleClient(newSocket);
    delete clientHandler;
    countCurrentTreaths--;
    close(newSocket);
    pthread_exit(NULL);
}

void MasterOfThreads (int port, ClientHandler *c , int serverSocket){
    ClientHandler *clientHandler = c;
    int  newSocket;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;


    pthread_t tid[60];
    bool isFirstItr = true;
    while(shouldRun){

        //Accept call creates a new socket for the incoming connection
        addr_size = sizeof serverStorage;
        newSocket = accept(serverSocket, (struct sockaddr *) &serverStorage, &addr_size);
        if (isFirstItr) {
            isFirstItr = false;
            timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;

            setsockopt(serverSocket, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        }
        if (newSocket < 0)	{
            if (errno == EWOULDBLOCK)	{
                cout << "timeout!" << endl;
                while(countCurrentTreaths > 0)
                {
                    pthread_join(tid[countCurrentTreaths],NULL);
                    countCurrentTreaths--;
                }
                break;
            }	else	{
                perror("other error");
                break;
            }
        }
        auto arg_struct1 = new arg_struct();
        arg_struct1->newSockfd=newSocket;
        arg_struct1->clientHandler= clientHandler->duplicate();

        //for each client request creates a thread and assign the client request to it to process
        //so the main thread can entertain next request
        if(pthread_create(&tid[countCurrentTreaths], NULL, socketThread, arg_struct1) != 0 ) {
            printf("Failed to create thread\n");
        }
        countCurrentTreaths++;
        if(countCurrentTreaths >= 50)
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
    struct sockaddr_in serverAddr;

    //Create the socket.
    this->serverSocket = socket(PF_INET, SOCK_STREAM, 0);
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
    bind(this->serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    listen(this->serverSocket,1);

    std::thread th1(MasterOfThreads, port, c , this->serverSocket);
    th1.join();
}
#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H

#include <unistd.h>
#include "Server.h"
#include <iostream>
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


struct arg_struct {
    int newSockfd;
    ClientHandler* clientHandler;
};


class MyParallelServer : public Server {
    int serverSocket;
    ClientHandler* clientHandler;


public:
    MyParallelServer(){
        shouldRun = true;
    }
    void open(int port ,ClientHandler* c) ;
    void done(){
        shouldRun = false;
    }

    ~MyParallelServer(){
        delete clientHandler;
        close(serverSocket);
    }
};


#endif //MILESTONE2_MYPARALLELSERVER_H

#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H


#include "Server.h"



struct arg_struct {
    int newSockfd;
    ClientHandler* clientHandler;
};


class MyParallelServer : public Server {

    ClientHandler* clientHandler;


public:
    MyParallelServer(){
        shouldRun = true;
    }
    void open(int port ,ClientHandler* c) ;
    void close(){
        shouldRun = false;
    }


};


#endif //MILESTONE2_MYPARALLELSERVER_H

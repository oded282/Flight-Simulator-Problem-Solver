#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H

#include "Server.h"


/*
 * This class creates threads and deals with client one by one.
 */
struct TreadParms {
    int sockfd;
    ClientHandler *clientHandler;

};

class MySerialServer : public Server {


public:
    MySerialServer() {
        shouldRun = true;
    }

    void open(int port, ClientHandler *c);

    void done() {
        shouldRun = false;
    }

};


#endif //MILESTONE2_MYSERIALSERVER_H

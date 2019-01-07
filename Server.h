#ifndef MILESTONE2_SERVER_H
#define MILESTONE2_SERVER_H


#include "ClientHandler.h"

class Server {

protected:
bool shouldRun;

public:

    virtual void open(int port ) = 0;
    virtual void close() = 0;

};


#endif //MILESTONE2_SERVER_H

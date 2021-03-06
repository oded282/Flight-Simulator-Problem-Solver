#ifndef MILESTONE2_SERVER_H
#define MILESTONE2_SERVER_H


#include "ClientHandler.h"

extern bool shouldRun;
extern int countCurrentTreaths;

/*
 * This interface responsible of opening servers.
 */
class Server {

protected:

public:

    virtual void open(int port, ClientHandler *c) = 0;

    virtual void done() = 0;

};


#endif //MILESTONE2_SERVER_H

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

#define SIZE_OF_READ_DATA 256

/*
 * This class responsible on the communication between client and the program.
 */
class MyTestClientHandler : public ClientHandler {

    Solver *solver;
    CacheManager *cm;

public:
    MyTestClientHandler(CacheManager *c, Solver *s) {
        solver = s;
        cm = c;
    }

    virtual void handleClient(int sockfd);


};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H

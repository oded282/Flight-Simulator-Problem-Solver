#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {

    Solver* solver;
    CacheManager* cm;

public:
    MyTestClientHandler(CacheManager* c , Solver* s){
        solver = s;
        cm = c;
    }

    virtual void handlerClient(Stream input , stream output);
    

};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H

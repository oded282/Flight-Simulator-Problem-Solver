
#ifndef MILESTONE2_MATRIXCLIENTHANDLER_H
#define MILESTONE2_MATRIXCLIENTHANDLER_H

#define SIZE_OF_READ_DATA 256
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"

class MatrixClientHandler : public ClientHandler{
    Solver* solver;
    CacheManager* cacheManager;

public:
    MatrixClientHandler(CacheManager* c , Solver* s){
        solver = s;
        cacheManager = c;
    }

    virtual void handleClient(int sockfd);

    virtual ClientHandler* duplicate();

    ~MatrixClientHandler(){
        delete solver;
        delete cacheManager;
    }
    };


#endif //MILESTONE2_MATRIXCLIENTHANDLER_H

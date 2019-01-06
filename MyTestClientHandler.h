#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {

public:

    virtual void handlerClient(Stream input , stream output);
    

};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H

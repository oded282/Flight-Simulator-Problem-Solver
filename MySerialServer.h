#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public Server {


public:
    MySerialServer(){
        shouldRun = true;
    }
    virtual void open(int port);
    virtual void close(){
        shouldRun = false;
    }


};


#endif //MILESTONE2_MYSERIALSERVER_H

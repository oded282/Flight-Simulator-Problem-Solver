#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public Server {


public:
    MySerialServer(){
        shouldRun = true;
    }
     void open(int port ,ClientHandler* c) ;
     void close(){
        shouldRun = false;
    }

};


#endif //MILESTONE2_MYSERIALSERVER_H

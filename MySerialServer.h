#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H

#include "Server.h"


//struct for the thread.
struct TreadParms {
    int sockfd;
    ClientHandler* clientHandler;

};
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

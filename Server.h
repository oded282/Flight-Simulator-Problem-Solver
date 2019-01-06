#ifndef MILESTONE2_SERVER_H
#define MILESTONE2_SERVER_H


class Server {

public:

    virtual void open(int port ,ClientHandler c );
    virtual void stop();


};


#endif //MILESTONE2_SERVER_H

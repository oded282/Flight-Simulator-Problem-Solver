#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H

#include <ios>

using namespace std;

class ClientHandler
{

public:
    virtual void handleClient(ios& , ios&) = 0;


};




#endif //MILESTONE2_CLIENTHANDLER_H

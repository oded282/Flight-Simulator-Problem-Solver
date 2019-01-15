#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H

#include <ios>
#include "CacheManager.h"

using namespace std;
class ClientHandler
{

public:

    virtual void handleClient(int sock) = 0;

    virtual ClientHandler* duplicate() = 0;

    virtual ~ClientHandler()= default;
};




#endif //MILESTONE2_CLIENTHANDLER_H

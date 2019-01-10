#include <iostream>
#include <unistd.h>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringRevers.h"
#include "State.h"

template <class T>
struct KeyHasher
{
    std::size_t operator()(const State<T> k) const
    {
        using std::size_t;
        using std::hash;
        using std::string;

        return ((hash<string>()(k.first)
                 ^ (hash<string>()(k.second) << 1)) >> 1)
               ^ (hash<int>()(k.third) << 1);
    }
};



//
//int main (){
//
//    Server* server = new MySerialServer();
//    server->open(5402 , new MyTestClientHandler(new FileCacheManager() , new StringRevers()));
//
//    sleep(500);
//
//
//    return 1;
//}

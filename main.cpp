#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringRevers.h"

int main (){

    Server* server = new MySerialServer();
    server->open(100 , new MyTestClientHandler(new FileCacheManager() , new StringRevers()));


    return 1;
}
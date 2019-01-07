#include <iostream>
#include <unistd.h>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringRevers.h"

int main (){

    Server* server = new MySerialServer();
    server->open(5402 , new MyTestClientHandler(new FileCacheManager() , new StringRevers()));

    sleep(500);


    return 1;
}

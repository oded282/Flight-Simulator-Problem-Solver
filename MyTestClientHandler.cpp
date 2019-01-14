#include <unistd.h>
#include <iostream>
#include <cstring>
#include "MyTestClientHandler.h"


void MyTestClientHandler::handleClient(int sockfd) {
    char buffer[SIZE_OF_READ_DATA] = {};
    ssize_t n;
    while (true){

        bzero(buffer , SIZE_OF_READ_DATA);

        n = read(sockfd , buffer , SIZE_OF_READ_DATA);

        if (strcmp(buffer , "end\r\n") == 0){
            break;
        }

        if (n < 0){
            cout << "not read fro, the client in from MyTestClientHandler"<<endl;
            break;
        }
        string result = cm->getSolution(buffer);
        if (result.empty()){
            result = solver->solve(buffer);
            cm->addSolution(buffer , result);
        }

        n = write(sockfd , result.data(), result.size());

        if (n < 0){
            cout << "not write to client from MyTestClientHandler"<<endl;
            break;
        }

    }
}

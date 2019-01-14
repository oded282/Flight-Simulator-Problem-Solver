
#include "MatrixClientHandler.h"
#include <unistd.h>
#include <iostream>
#include <cstring>


void MatrixClientHandler::handleClient(int sockfd) {
    string problem;
    char buffer[SIZE_OF_READ_DATA] = {};
    ssize_t n;
    while (true){

        bzero(buffer , SIZE_OF_READ_DATA);

        while(strstr(buffer,"end") != nullptr) {
            n = read(sockfd, buffer, SIZE_OF_READ_DATA);
            problem += buffer;
            memset(buffer, 0, sizeof(buffer));
        }

        if (strcmp(buffer , "end\r\n") == 0){
            break;
        }

        if (n < 0){
            cout << "not read fro, the client in from MyTestClientHandler"<<endl;
            break;
        }
        string result = cacheManager->getSolution(problem);
        if (result.empty()){
            result = solver->solve(problem);
            cacheManager->addSolution(problem , result);
        }

        n = write(sockfd , result.data(), result.size());

        if (n < 0){
            cout << "not write to client from MyTestClientHandler"<<endl;
            break;
        }
    }
}

#include "MatrixClientHandler.h"
#include <unistd.h>
#include <iostream>
#include <cstring>

bool isEndData(char* buffer){
    int c = 0;
    while(buffer[c] != '\0'){
        if(buffer[c] == 'e'){
            return true;
        }
        c++;
    }
    return false;
}


void MatrixClientHandler::handleClient(int sockfd) {
    string problem;
    char buffer[SIZE_OF_READ_DATA] = {};
    ssize_t n;
    while (true){

        bzero(buffer , SIZE_OF_READ_DATA);

        while(true) {
            n = read(sockfd, buffer, SIZE_OF_READ_DATA);
            problem += buffer;
            cout<< buffer << endl;
            if (isEndData(buffer)){
                break;
            }
            bzero(buffer , SIZE_OF_READ_DATA);
        }

        if (n < 0){
            cout << "not read fro, the client in from MyTestClientHandler"<<endl;
            break;
        }
        string result = cacheManager->getSolution(problem);
        if (result.empty()){
            cout << "trying to solve problem"<< endl;
            cout<< problem << endl;
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
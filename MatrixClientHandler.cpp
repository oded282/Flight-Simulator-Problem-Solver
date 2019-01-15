
#include "MatrixClientHandler.h"
#include "SearchProblemSolver.h"
#include <unistd.h>
#include <iostream>
#include <cstring>
extern pthread_mutex_t mutex;


bool isEndData(char *buffer) {
    int c = 0;
    while (buffer[c] != '\0') {
        if (buffer[c] == 'e') {
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
    bzero(buffer, SIZE_OF_READ_DATA);

    while (true) {
        n = read(sockfd, buffer, SIZE_OF_READ_DATA);

        problem += buffer;
        if (isEndData(buffer)) {
            break;
        }
        bzero(buffer, SIZE_OF_READ_DATA);
    }

    if (n < 0) {
        cout << "not read fro, the client in from MyTestClientHandler" << endl;
        return;
    }

    string result = cacheManager->getSolution(problem);

    if (result.empty()) {

        result = solver->solve(problem);

        cacheManager->addSolution(problem, result);

    }

    n = write(sockfd, result.data(), result.size());
    if (n < 0) {
        cout << "not write to client from MyTestClientHandler" << endl;
        return;
    }
}

ClientHandler* MatrixClientHandler::duplicate(){

    auto newClient = new MatrixClientHandler(cacheManager, new SearchProblemSolver());

    return newClient;
}

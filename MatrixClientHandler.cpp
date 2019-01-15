
#include "MatrixClientHandler.h"
#include "SearchProblemSolver.h"
#include <unistd.h>
#include <iostream>
#include <cstring>
extern pthread_mutex_t mutex;

/*
 * This func check if got to the end of the data.
 */
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

/*
 * This func will open thread for each new client.
 * That way we can treat all client at the same time.
 */
void MatrixClientHandler::handleClient(int sockfd) {
    string problem;
    char buffer[SIZE_OF_READ_DATA] = {};
    ssize_t n;
    bzero(buffer, SIZE_OF_READ_DATA);

    while (true) { // start reading info from the clien.
        n = read(sockfd, buffer, SIZE_OF_READ_DATA);

        problem += buffer;
        if (isEndData(buffer)) { // case their is no more data.
            break;
        }
        bzero(buffer, SIZE_OF_READ_DATA);
    }

    if (n < 0) {
        cout << "not read fro, the client in from MyTestClientHandler" << endl;
        return;
    }

    string result = cacheManager->getSolution(problem); // check if solution already exist.

    if (result.empty()) {

        result = solver->solve(problem); // solve the problem.

        cacheManager->addSolution(problem, result); // add the solution to the cach manager.

    }

    n = write(sockfd, result.data(), result.size()); // write back the solution to the client.
    if (n < 0) {
        cout << "not write to client from MyTestClientHandler" << endl;
        return;
    }
}

/*
 * create new client handler.
 */
ClientHandler* MatrixClientHandler::duplicate(){

    auto newClient = new MatrixClientHandler(cacheManager, new SearchProblemSolver());

    return newClient;
}

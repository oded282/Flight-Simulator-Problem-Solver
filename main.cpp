#include <iostream>
#include <unistd.h>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringRevers.h"
#include "State.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "AStar.h"
#include "DepthFirstSearch .h"
#include "MyParallelServer.h"
#include "MatrixClientHandler.h"
#include "SearchProblemSolver.h"

bool shouldRun = true;
int countCurrentTreaths = 0;
pthread_mutex_t mutex;


/*
 * The main create the parallel server the cach manager, some searcher and solver
 * and start the prog that will start listen to all the clients.
 * we will take care of each client at the same time, get solutions to their problems.
 */
int main(int argc, char *argv[]){

    int port = stoi(argv[1]);

    auto parallelServer = new MyParallelServer();
    auto cacheManager = new FileCacheManager();
    auto solver = new SearchProblemSolver();
    auto clientHandler = new MatrixClientHandler(cacheManager,solver);

    parallelServer->open(port,clientHandler);

    delete cacheManager;
    delete parallelServer;

    return 1;
}


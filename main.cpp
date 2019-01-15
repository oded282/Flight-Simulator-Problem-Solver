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

int main(){


    auto parallelServer = new MyParallelServer();
    auto cacheManager = new FileCacheManager();
    auto b = new BreadthFirstSearch<std::pair<int,int>>();
    auto solver = new SearchProblemSolver(b);
    auto clientHandler = new MatrixClientHandler(cacheManager,solver);

    parallelServer->open(5400,clientHandler);

    return 1;
}


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

int main() {
    auto parallelServer = new MyParallelServer();
    auto cacheManager = new FileCacheManager();
    auto solver = new SearchProblemSolver();
    auto clientHandler = new MatrixClientHandler(cacheManager, solver);
    parallelServer->open(5400, clientHandler);


   // string buffer = "4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8\r\n4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4\r\n4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7\r\n3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7\r\n0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1\r\n7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9\r\n6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8\r\n10, 8, 0, 2, 3, 8, 0,10,10, 2, 7\r\n5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1\r\n7, 7, 5,10, 8,10, 1, 6, 9, 9, 1\r\n5,10, 1,10, 7, 7, 3,10, 8, 0, 6\r\n0,0\r\n10,10\r\nend\r\n";
//
   // string result;
//
   // auto cacheManager = new FileCacheManager();
//
   // auto b = new DepthFirstSearch<std::pair<int, int>>();
//
   // auto solver = new SearchProblemSolver(b);
//
   // auto clientHandler = new MatrixClientHandler(cacheManager, solver);
//
//
   // result = solver->solve(buffer);
//

    return 1;
}


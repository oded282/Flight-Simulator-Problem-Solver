cmake_minimum_required(VERSION 3.13)
project(MileStone2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(MileStone2 main.cpp Server.h ClientHandler.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h FileCacheManager.cpp FileCacheManager.h CacheManager.h MySolver.cpp MySolver.h StringRevers.cpp StringRevers.h Searcher.h Searchable.h State.cpp State.h SearchableMatrix.cpp SearchableMatrix.h BestFirstSearch.h "DepthFirstSearch .h" AbstractSearcher.h BreadthFirstSearch.h AStar.cpp AStar.h SearchProblemSolver.cpp SearchProblemSolver.h MyParallelServer.cpp MyParallelServer.h MatrixClientHandler.cpp MatrixClientHandler.h)
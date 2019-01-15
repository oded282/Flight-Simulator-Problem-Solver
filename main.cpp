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
    auto solver = new SearchProblemSolver();
    auto clientHandler = new MatrixClientHandler(cacheManager,solver);

    parallelServer->open(5400,clientHandler);






 //  std::vector<double >* v1 = new std::vector<double>{    10, 1, 7, 8, 4, 9,10, 5, 3, 5, 9, 2, 3, 4,10, 1, 2, 8, 8, 5, 4, 4, 9, 5};
 //  std::vector<double >* v2 = new std::vector<double>{    6, 6, 9, 9, 5, 4, 5,10,10, 5, 9, 7, 6, 4, 4, 1, 5, 3, 5, 6,10,10, 2, 4
 //  };
 //  std::vector<double >* v3 = new std::vector<double>{    9, 6,10, 0, 7, 3, 1, 3, 3, 4, 6, 6, 2, 5, 5, 9, 9, 3,-1, 4, 3, 7, 0,10};
 //  std::vector<double >* v4 = new std::vector<double>{    9, 0, 3, 3, 6, 2, 6, 3, 8, 4, 8, 8, 9, 1, 8, 3,10, 1,10, 8, 4,10, 1, 9};
 //  std::vector<double >* v5 = new std::vector<double>{    10, 8,10, 0, 8, 0, 5, 4, 7, 1,10, 6, 6,-1, 9, 8, 7, 5, 6, 8, 6,10, 5, 2};
 //  std::vector<double >* v6 = new std::vector<double>{    6,10,10, 1, 1, 5, 4, 5, 2,-1, 3, 7, 7, 2, 9, 6, 9, 4, 4, 3, 6, 1,10,10};
 //  std::vector<double >* v7 = new std::vector<double>{    6, 5, 2, 1, 2, 9, 9, 9, 1, 0, 2, 1, 5, 5, 5, 2, 0, 5,10, 3, 9, 4, 5, 3};
 //  std::vector<double >* v8 = new std::vector<double>{    3, 9, 7,10,-1, 4, 4, 3,-1, 9, 2, 9, 9, 1, 8, 7, 4, 7,10, 8, 4, 8, 9,10};
 //  std::vector<double >* v9 = new std::vector<double>{    0,-1, 6, 6, 0, 9, 3, 9,10, 1, 2, 8, 5, 6, 7, 5, 1, 3, 0, 5, 7,10,10, 3};
 //  std::vector<double >* v10 = new std::vector<double>{     9, 9, 8, 8, 3,10,10, 6, 6, 6, 0, 7, 9, 5, 7, 1, 5, 2, 4, 8,10, 0, 4, 6};
 //  std::vector<double >* v11 = new std::vector<double>{    2, 8, 0, 1, 5, 4, 3, 7, 4, 6, 5, 5, 9, 6,10, 4, 1, 8,-1, 5, 2, 4, 9, 4
 //  };
 //  std::vector<double >* v12 = new std::vector<double>{    8, 5, 8,10,-1, 5, 8, 8, 4, 6, 9, 9, 4, 4,-1, 5, 1, 5, 9, 3, 8, 8, 6, 9
 //  };
 //  std::vector<double >* v13 = new std::vector<double>{    2, 7, 0,-1, 8,10, 9, 8, 1, 7, 7, 6, 3, 9, 2,10, 8, 5, 0, 7, 6, 3,10, 1
 //  };
 //  std::vector<double >* v14 = new std::vector<double>{    -1, 9,-1, 0, 5, 8, 4, 1, 0, 4, 1, 6, 7, 7, 5, 7, 1, 9, 7, 0, 4, 1, 3, 2
 //  };
 //  std::vector<double >* v15 = new std::vector<double>{    8, 5, 4, 7, 6, 0, 5,10,10, 1, 1, 8, 2, 5, 7, 8, 1, 7, 3, 0,10, 3, 9, 6
 //  };
 //  std::vector<double >* v16 = new std::vector<double>{    -1, 8, 4, 2, 2, 3, 0, 9, 5, 1, 2,10, 7, 8, 8, 2, 7, 9, 4, 1, 2, 9, 9, 5
 //  };
 //  std::vector<double >* v17 = new std::vector<double>{    3, 9, 8, 9, 5, 8, 2, 0, 7, 1, 1,10, 3, 5,-1, 6, 2, 9, 5, 3, 0, 1, 3, 5
 //  };
 //  std::vector<double >* v18 = new std::vector<double>{    7, 1, 2, 8, 3, 1, 6, 2, 9, 7, 2, 1, 7, 7, 1, 6, 1, 6, 5, 6,10, 5, 3, 9
 //  };
 //  std::vector<double >* v19 = new std::vector<double>{    9, 5, 0, 5, 6,-1, 9, 9, 8, 4, 1, 0, 6, 0, 2, 3, 5, 9, 7, 5, 4, 3, 3, 7
 //  };
 //  std::vector<double >* v20 = new std::vector<double>{    4, 6, 4,-1, 0, 0, 4, 2, 2, 5, 6,-1, 6, 1,10, 9, 3, 8, 6, 2, 7, 3, 8, 2
 //  };
 //  std::vector<double >* v21 = new std::vector<double>{    10,10, 6, 8, 6, 6, 4, 7, 2, 0, 0, 3, 9,-1, 2,10,10, 4,-1,10,10, 6, 5,10
 //  };
 //  std::vector<double >* v22 = new std::vector<double>{    10, 8, 1, 2, 9, 3, 3, 6, 3, 6, 8, 0, 6, 7, 4, 5, 4, 1, 9, 1, 2, 1, 4, 4
 //  };
 //  std::vector<double >* v23 = new std::vector<double>{    4, 5,10,10, 4, 3, 7, 1, 9, 5, 8, 3,-1, 0, 3, 9, 5,10, 0,-1,-1, 3, 4, 6
 //  };
 //  std::vector<double >* v24 = new std::vector<double>{    0, 7,10, 6, 1, 0,-1, 6, 5, 1, 5,-1, 8, 9,10, 5, 4, 4, 6, 4, 9, 0, 1, 9
 //  };



 //  std::vector<std::vector<double >*>* matrix = new std::vector<std::vector<double>*> {v1,v2,v3 ,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15 ,v16,v17,v18,v19,v20,v21,v22,v23,v24} ;


 //  std::pair<int,int>* p1 = new std::pair<int,int> (0,0) ;
 //  // auto s1 = new State<std::pair<int,int>> (p1 , 0);

 //  std::pair<int,int>* p8 = new std::pair<int,int> (23,23) ;

 //  auto s = new SearchableMatrix(*p1 , *p8 , matrix ,24, 24);

 //  auto b = new DepthFirstSearch<std::pair<int,int>>();

 //  std::vector<State<pair<int,int>>*>* vec = b->search(s);


 //  return 1;
}


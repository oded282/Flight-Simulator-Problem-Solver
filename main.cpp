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
bool shouldRun;
int countCurrentTreaths = 0;



//int main(){
//
//    std::vector<double >* v1 = new std::vector<double>{ 4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8};
//    std::vector<double >* v2 = new std::vector<double>{ 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4};
//    std::vector<double >* v3 = new std::vector<double>{4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7};
//    std::vector<double >* v4 = new std::vector<double>{3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7};
//    std::vector<double >* v5 = new std::vector<double>{0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1};
//    std::vector<double >* v6 = new std::vector<double>{7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9};
//    std::vector<double >* v7 = new std::vector<double>{6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8};
//    std::vector<double >* v8 = new std::vector<double>{10, 8, 0, 2, 3, 8, 0,10,10, 2, 7};
//    std::vector<double >* v9 = new std::vector<double>{5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1};
//    std::vector<double >* v10 = new std::vector<double>{ 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1};
//    std::vector<double >* v11 = new std::vector<double>{5,10, 1,10, 7, 7, 3,10, 8, 0, 6};
//
//    std::vector<std::vector<double >*>* matrix = new std::vector<std::vector<double>*> {v1,v2,v3 ,v4,v5,v6,v7,v8,v9,v10,v11} ;
//
//
//    std::pair<int,int>* p1 = new std::pair<int,int> (0,0) ;
//    // auto s1 = new State<std::pair<int,int>> (p1 , 0);
//
//    std::pair<int,int>* p8 = new std::pair<int,int> (10,10) ;
//
//    auto s = new SearchableMatrix(*p1 , *p8 , matrix , 11);
//
//    auto b = new DepthFirstSearch<std::pair<int,int>>();
//
//    std::vector<State<pair<int,int>>*>* vec = b->search(s);
//
//
//    return 1;
//}


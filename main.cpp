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
/*
int main(){

    std::vector<double >* v1 = new std::vector<double>{0 , 4 , 7};
    std::vector<double >* v2 = new std::vector<double>{2 , 5 ,8};
    std::vector<double >* v3 = new std::vector<double>{3, 6,9};

    std::vector<std::vector<double >*>* matrix ;
    matrix->push_back(v1);
    matrix->push_back(v2);
    matrix->push_back(v3);


    std::pair<int,int>* p1 = new std::pair<int,int> (0,0) ;
    auto s1 = new State<std::pair<int,int>> (p1 , 0);

    std::pair<int,int>* p8 = new std::pair<int,int> (2,2) ;
    auto s8 = new State<std::pair<int,int>> (p8 , 0);

    auto s = new SearchableMatrix(s1 , s8 , matrix , 3);

    auto b = new BreadthFirstSearch<std::pair<int,int>>();

    std::vector<State<pair<int,int>>*>* vec = b->search(s);

    return 1;
}
*/
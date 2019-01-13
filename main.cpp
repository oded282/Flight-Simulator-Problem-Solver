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

int main(){

    std::vector<double >* v1 = new std::vector<double>{0 ,8 ,7 ,10};
    std::vector<double >* v2 = new std::vector<double>{1 ,2 ,4 ,15};
    std::vector<double >* v3 = new std::vector<double>{50 ,3 ,6 ,-1};
    std::vector<double >* v4 = new std::vector<double>{10,21 ,5,23};


    std::vector<std::vector<double >*>* matrix = new std::vector<std::vector<double>*> {v1,v2,v3 ,v4} ;


    std::pair<int,int>* p1 = new std::pair<int,int> (0,0) ;
    // auto s1 = new State<std::pair<int,int>> (p1 , 0);

    std::pair<int,int>* p8 = new std::pair<int,int> (3,3) ;

    auto s = new SearchableMatrix(*p1 , *p8 , matrix , 4);

    auto b = new AStar<std::pair<int,int>>();

    std::vector<State<pair<int,int>>*>* vec = b->search(s);


    return 1;
}

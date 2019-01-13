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
#include "DepthFirstSearch .h"

int main(){



    std::vector<double >* v1 = new std::vector<double>{0 ,8 ,7 ,10,20};
    std::vector<double >* v2 = new std::vector<double>{1 ,2 ,4 ,15,1 };
    std::vector<double >* v3 = new std::vector<double>{1 ,3 ,7 ,5 ,70};
    std::vector<double >* v4 = new std::vector<double>{10,2 ,90,1 ,10};
    std::vector<double >* v5 = new std::vector<double>{15,30,99,3 ,11 };


    std::vector<std::vector<double >*>* matrix =new std::vector<std::vector<double>*> {v1,v2,v3 ,v4,v5} ;


    std::pair<int,int>* p1 = new std::pair<int,int> (0,0) ;
   // auto s1 = new State<std::pair<int,int>> (p1 , 0);

    std::pair<int,int>* p8 = new std::pair<int,int> (4,4) ;

    auto s = new SearchableMatrix(*p1 , *p8 , matrix , 5);

    auto b = new DepthFirstSearch<std::pair<int,int>>();

    std::vector<State<pair<int,int>>*>* vec = b->search(s);

    vec->empty();

    return 1;
}

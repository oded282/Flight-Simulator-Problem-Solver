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

int main(){

    std::vector<std::vector<double >> matrix = {{0 , 4 , 7} , {2 , 5 ,8} , {3, 6,9}};

    std::pair<int,int> p1 (0,0) ;
    auto s1 = new State<std::pair<int,int>> (p1 , 0);

    std::pair<int,int> p8 (2,2) ;
    auto s8 = new State<std::pair<int,int>> (p8 , 0);
    auto s = new SearchableMatrix(s1 , s8 , matrix , 3);

    auto b = new BestFirstSearch<std::pair<int,int>>();

    b->search(s);

    return 1;
}

#include <utility>
#include "BestFirstSearch.h"
#include "SearchableMatrix.h"

int main(){

    std::vector<std::vector<double >> matrix = {{0 , 4 , 7} , {2 , 5 ,8} , {3, 6,9}};

    std::pair<int,int> p1 (0,0) ;
    auto s1 = new State<std::pair<int,int>> (p1 , 0);

    std::pair<int,int> p8 (2,2) ;
    auto s8 = new State<std::pair<int,int>> (p8 , 0);
    auto s = new SearchableMatrix(s1 , s8 , matrix , 3);

    auto b = new BestFirstSearch<std::pair<int,int>>();

    b->search(s);




/*
    std::pair<int,int> p1 (0,0) ;
    State<std::pair<int,int>> s1(p1 , 1);

    std::pair<int,int> p2 (1,0) ;
    State<std::pair<int,int>> s2(p2 , 1);

    std::pair<int,int> p3 (2,0) ;
    State<std::pair<int,int>> s3(p3 , 5);

    std::pair<int,int> p4 (1,1) ;
    State<std::pair<int,int>> s4(p4 , 50);

    std::pair<int,int> p5 (1,2) ;
    State<std::pair<int,int>> s5(p5 , 0);

    std::pair<int,int> p6 (0,2) ;
    State<std::pair<int,int>> s6(p6 , 8);

    std::pair<int,int> p7 (2,1) ;
    State<std::pair<int,int>> s7(p7 , 20);

    std::pair<int,int> p8 (2,2) ;
    State<std::pair<int,int>> s8(p8 , 0);

    std::pair<int,int> p9 (0,1) ;
    State<std::pair<int,int>> s9(p9 , 7);

    std::vector<State<std::pair<int,int>>> v1;
    v1.push_back(s2);
    v1.push_back(s9);

    std::vector<State<std::pair<int,int>>> v2;
    v2.push_back(s1);
    v2.push_back(s4);
    v2.push_back(s3);

    std::vector<State<std::pair<int,int>>> v3;
    v3.push_back(s2);
    v3.push_back(s7);

    std::vector<State<std::pair<int,int>>> v4;
    v4.push_back(s2);
    v4.push_back(s9);
    v4.push_back(s5);
    v4.push_back(s7);

    std::vector<State<std::pair<int,int>>> v5;
    v5.push_back(s6);
    v5.push_back(s4);
    v5.push_back(s8);

    std::vector<State<std::pair<int,int>>> v6;
    v6.push_back(s4);
    v6.push_back(s9);
    v6.push_back(s5);

    std::vector<State<std::pair<int,int>>> v7;
    v1.push_back(s3);
    v1.push_back(s4);
    v1.push_back(s8);

    std::vector<State<std::pair<int,int>>> v8;
    v8.push_back(s5);
    v8.push_back(s7);

    std::vector<State<std::pair<int,int>>> v9;
    v1.push_back(s1);
    v1.push_back(s4);
    v1.push_back(s6);

    std::unordered_map<State<std::pair<int,int>>,std::vector<State<std::pair<int,int>>>>* map = {};


    std::unordered_map<std::string , int >* map1;
    map1->insert({"oded" , 1});

    map->insert({s1 , v1});
    map->insert({s2 , v2});
    map->insert({s3 , v3});
    map->insert({s4 , v4});
    map->insert({s5 , v5});
    map->insert({s6 , v6});
    map->insert({s7 , v7});
    map->insert({s8 , v8});
    map->insert({s9 , v9});

    auto matrix = new SearchableMatrix(&s1 , &s8 , map , 3);

    auto bfs = new BestFirstSearch<State<std::pair<int,int>>>();
*/
    return 1;
}
#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H


#include "AbstractSearcher.h"
template<class T>
class AStar : public AbstractSearcher<T> {

    std::unordered_map<State<T>, unsigned int>distansMap;


    void initialize(std::vector<State<T>> s){
        for(State<T> state:s){
            //this->visited[s] = WHITE;




        }
    }


public:

    std::vector<State<T>> search (Searchable<T> s){












    }



};


#endif //MILESTONE2_ASTAR_H

#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H


#include "AbstractSearcher.h"
template<class T>
class AStar : public AbstractSearcher<T> {

    std::unordered_map<State<T>, unsigned int>distanceMap;


    void initialDistance(std::vector<State<T>> s){
    //    for(State<T> s : ){

      //  }
    }


public:

    std::vector<State<T>> search (Searchable<T> s){












    }



};


#endif //MILESTONE2_ASTAR_H

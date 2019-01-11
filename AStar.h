#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H

#include <math.h>
#include "AbstractSearcher.h"

template<class T>
class AStar : public AbstractSearcher<T> {

    std::unordered_map<State<T>, double> distanceMap;


    void initialDistance(std::vector<State<T>> s , std::pair<int,int> pair){
        for(State<T> state : s){ //TODO  state.getState()).first -> won't work need to think about other solution.
            distanceMap[s] = sqrt(pow(pair.first + state.getState()).first + pow(pair.second + state.getState().second));
        }
    }


public:

    std::vector<State<T>> search (Searchable<T> s){

        initialDistance(s.getPossibleStates(), s.getGoal()->getState());










    }



};


#endif //MILESTONE2_ASTAR_H

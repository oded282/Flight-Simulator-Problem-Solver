#ifndef MILESTONE2_ABSTRACTSEARCHER_H
#define MILESTONE2_ABSTRACTSEARCHER_H


#include <queue>
#include <map>
#include "Searcher.h"

enum color {WHITE ,GRAY , BLACK };
template <class T>

class myComparator
{
public:
    int operator() (const State<T>* p1, const State<T>* p2)
    {
        return p1->getPathCost() > p2->getPathCost();
    }
};

template <class T>
class AbstractSearcher : public Searcher<State<T>>{
protected:
    std::map<State<T>* , color> visited;
    //std::unordered_map<State<T>*, color> visited;
    std::priority_queue<State<T>*,std::vector<State<T>*>,myComparator<T>> open ;


public:
    AbstractSearcher(){}

   //virtual std::vector<State<T>*>* search (Searchable<State<T>>* s)=0;
    double getNumOfNodesEvaluated(){
       return this->numOfNodes;
    };

    // get the gol after the running of the search and return the path.
    static std::vector<State<T>*>* backTrace(State<T>* state) {
       std::vector<State<T>*>* trace;
       while (state != NULL) {
          trace->push_back(state);
          state = state->getFather();
       }
       return trace;
    }

};


#endif //MILESTONE2_ABSTRACTSEARCHER_H

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include <queue>
#include "AbstractSearcher.h"

template <class T>

class myComparator
{
public:
    int operator() (const State<T>& p1, const State<T>& p2)
    {
        return p1.getPathCost() > p2.getPathCost();
    }
};





template <class T>

class BestFirstSearch : public AbstractSearcher<State<T>> {

    std::priority_queue <State<T>,std::vector<State<T>>,myComparator<T>> open;

    void initializ (std::vector<State<T>> vector);
public:
    BestFirstSearch(){
        open();
    }
    std::vector<State<T>> search (Searchable<T> s);
    //double getNumOfNodesEvaluated(){}
    //std::vector<State<T>> backTrace(State<T> end){}


};


#endif //MILESTONE2_BESTFIRSTSEARCH_H

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include <queue>
#include "Searcher.h"
template <class T>

class myComparator
{
public:
    int operator() (const State<T>& p1, const State<T>& p2)
    {
        return p1.getCost() > p2.getCost();
    }
};


template <class T>

class BestFirstSearch : public Searcher<State<T>> {

    std::priority_queue <State<T>,std::vector<State<T>>,myComparator<T>> open;

public:


    std::vector<State<T>> search (Searchable<T> s);

    std::vector<State<T>> backTrace(State<T> end);


};


#endif //MILESTONE2_BESTFIRSTSEARCH_H

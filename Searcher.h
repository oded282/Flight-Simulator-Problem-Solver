#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H


#include "Searchable.h"

/*
 * This interface represent all the class who can search.
 * all the algorithms implement that interface and can solve
 * something that is searchable.
 */
template<class T>
class Searcher {
protected:
    double numOfNodes;

public:
    Searcher() {}

    virtual std::vector<State<T> *> *search(Searchable<T> *s) = 0;

    virtual double getNumOfNodesEvaluated() = 0;

    virtual ~Searcher() = default;

};

#endif //MILESTONE2_SEARCHER_H

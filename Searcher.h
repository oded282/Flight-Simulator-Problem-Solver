#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H


#include "Searchable.h"
template <class T>
class Searcher {
protected:
    double numOfNodes;

public:
    Searcher(){}
   virtual std::vector<State<T>*>* search (Searchable<T>* s) = 0;
    virtual double getNumOfNodesEvaluated() = 0;

};


#endif //MILESTONE2_SEARCHER_H

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H


#include "Searchable.h"
template <class T>

class Searcher {
protected:
    double numOfNodes;

public:
    Searcher(){}
   virtual std::vector<State<T>*>* search (Searchable<State<T>>* s) = 0;

};


#endif //MILESTONE2_SEARCHER_H

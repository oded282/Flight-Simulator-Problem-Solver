#ifndef MILESTONE2_ABSTRACTSEARCHER_H
#define MILESTONE2_ABSTRACTSEARCHER_H


#include "Searcher.h"
template <class T>

class AbstractSearcher : public Searcher<State<T>>{
protected:


public:

   // virtual std::vector<State<T>> search (Searchable<T> s)=0;
   double getNumOfNodesEvaluated();
    std::vector<State<T>> backTrace(State<T> end);



};


#endif //MILESTONE2_ABSTRACTSEARCHER_H

#ifndef MILESTONE2_ABSTRACTSEARCHER_H
#define MILESTONE2_ABSTRACTSEARCHER_H


#include "Searcher.h"

template <class T>
class AbstractSearcher : public Searcher<State<T>>{

public:
    AbstractSearcher(){}
   //virtual std::vector<State<T>*>* search (Searchable<State<T>>* s)=0;


    double getNumOfNodesEvaluated(){
       return this->numOfNodes;
    };


    // get the gol after the running of the search and return the path.

    std::vector<State<T>*>* backTrace(State<T>* state) {
       std::vector<State<T>*>* trace;
       while (state != NULL) {
          trace->push_back(state);
          state = state->getFather();
       }
       return trace;
    }

};


#endif //MILESTONE2_ABSTRACTSEARCHER_H

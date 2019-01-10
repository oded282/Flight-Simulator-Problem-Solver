#include "AbstractSearcher.h"
template<class T>

double AbstractSearcher<T>::getNumOfNodesEvaluated(){
    return this->numOfNodes;
};


// get the gol after the running of the search and return the path.
template<class T>
std::vector<State<T>>* AbstractSearcher<T>::backTrace(State<T> state) {
    std::vector<State<T>> trace;
    while (state != NULL) {
        trace.push_back(state);
        state = state.getFather();
    }
    return trace;
}



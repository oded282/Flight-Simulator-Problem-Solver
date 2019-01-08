#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H


#include "State.h"
#include <unordered_map>
template <class T>

class Searchable {

protected:
    State<T> initial;
    State<T> goal;
    std::unordered_map<State<T>,std::vector<State<T>>> possibleStates;

public:
    Searchable(){};

    const State<T> &getInitial() = 0;

    const State<T> &getGoal() = 0;

    std::vector<State<T>> getAllPossibleStates(State<T> s);

};


#endif //MILESTONE2_SEARCHABLE_H

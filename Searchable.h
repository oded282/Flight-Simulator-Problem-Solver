#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H


#include "State.h"
template <class T>

class Searchable {

    State<T> initial;
    State<T> goal;

public:
    const State<T> &getInitial() = 0;

    const State<T> &getGoal() = 0;

};


#endif //MILESTONE2_SEARCHABLE_H

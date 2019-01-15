#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H


#include "State.h"
#include <unordered_map>

/*
 * This inteface describe some class that we can execute search upon them.
 */
template<class T>
class Searchable {

protected:
    State<T> *initial;
    State<T> *goal;
    std::vector<State<T> *> *allStates;

public:
    Searchable() {};

    virtual State<T> *getInitial() = 0;

    virtual State<T> *getGoal() = 0;

    virtual std::vector<State<T> *> *getAllStates() = 0;


    virtual std::vector<State<T> *> *getPossibleStates(State<T> *state) = 0;

    virtual void setDistance(State<std::pair<int, int>> *state, State<std::pair<int, int>> *goal) = 0;

//    ~Searchable() = 0;

};


#endif //MILESTONE2_SEARCHABLE_H

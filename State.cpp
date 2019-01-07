
#include "State.h"

template <class T>
State<T> ::State(T state){
    State::state = state;
}


template <class T>
bool State<T> ::equals(T state){
    return state == State::state;
}


template <class T>
void State<T> ::setState(T state) {
    State::state = state;
}


template <class T>
void State<T> ::setCost(double cost) {
    State::cost = cost;
}


template <class T>
void State<T> ::setCameFrom(T cameFrom) {
    State::cameFrom = cameFrom;
}
#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>

template <class T>

class State {
    T state;
    double cost;
    T cameFrom;
    std::vector<T> canGoTo;

public:
    State(T s){
        state = s;
    }

    bool equals(T s){
        return s == state;
    }

    void setState(T state) {
        State::state = state;
    }

    void setCost(double cost) {
        State::cost = cost;
    }

    void setCameFrom(T cameFrom) {
        State::cameFrom = cameFrom;
    }


};


#endif //MILESTONE2_STATE_H

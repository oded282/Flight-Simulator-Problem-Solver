#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>



template <class T> class State {

    T state;
    double cost;
    State<T> cameFrom;

public:
    State(T state);

    bool equals(T state);

    void setState(T state);

    void setCost(double cost);

    void setCameFrom(T cameFrom);

};


#endif //MILESTONE2_STATE_H

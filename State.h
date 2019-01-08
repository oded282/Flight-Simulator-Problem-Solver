#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>
#include <cstring>
#include <limits>


template<class T>
class State {

    T state;
    double nodeCost;
    double pathCost;
    State<T>* father;

public:

    State(T state);

    State(T state, double c);

    bool equals(T state);

    void setState(T state);

    void setNodeCost(double nodeCost);

    void setPathCost(double pathCost);

    void setFather(const State<T> &father);

    //void setFather(T father);

    double getCost();

    State<T> getFather();

    double getNodeCost() const;

    double getPathCost() const;
};


template <class T>
State<T> ::State(T state ){
    State::state = state;
    State::father = NULL;
    State::nodeCost = 1;
    State::pathCost =  std::numeric_limits<double>::infinity();
}

template <class T>
State<T> ::State(T state , double c){
    State::state = state;
    State::father = NULL;
    State::nodeCost = c;
    State::pathCost =  std::numeric_limits<double>::infinity();
}


template <class T>
bool State<T> ::equals(T state){
    return state == State::state;
}


template <class T>
void State<T> ::setState(T state) {
    State::state = state;
}


//template <class T>
//void State<T> ::setFather(T f) {
//  State::father = f;
//}
template <class T>
double State<T> ::getCost(){
    return nodeCost;
}

template <class T>
State<T> State<T>::getFather() {
    return father;
}

template<class T>
double State<T>::getNodeCost() const {
    return nodeCost;
}

template<class T>
double State<T>::getPathCost() const {
    return pathCost;
}

template<class T>
void State<T>::setNodeCost(double nodeCost) {
    State::nodeCost = nodeCost;
}

template<class T>
void State<T>::setPathCost(double pathCost) {
    State::pathCost = pathCost;
}

template<class T>
void State<T>::setFather(const State<T> &father) {
    State::father = father;
}



#endif //MILESTONE2_STATE_H

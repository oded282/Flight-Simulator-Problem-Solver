#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>



template <class T> class State {

    T state;
    double nodeCost;
    double pathCost;
    State<T>* father;

public:

    State(T state){
        State::state = state;
    }



    bool equals(T state){
        return state == State::state;
    }



    void setState(T state) {
        State::state = state;
    }

    double getCost(){
        return nodeCost;
    }


    State<T> getFather() {
        return father;
    }

    double getNodeCost() const {
        return nodeCost;
    }

    double getPathCost() const {
        return pathCost;
    }


    void setNodeCost(double nodeCost) {
        State::nodeCost = nodeCost;
    }


    void setPathCost(double pathCost) {
        State::pathCost = pathCost;
    }


    void setFather(const State<T> &father) {
        State::father = father;
    }
};


#endif //MILESTONE2_STATE_H

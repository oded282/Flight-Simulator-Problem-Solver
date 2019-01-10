#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>
#include <cstring>
#include <limits>
#include <cstdlib>


template<class T>
class State {

    T state;
    double nodeCost;
    double pathCost;
    State<T> *father;
    int numHash;

public:


    State<T>(T state) {
        State::state = state;
        State::father = NULL;
        State::nodeCost = 1;
        State::pathCost = std::numeric_limits<double>::infinity();
        State::numHash = rand() + 1;
    }

    State<T>(T state, double c) {
        State::state = state;
        State::father = NULL;
        State::nodeCost = c;
        State::pathCost = std::numeric_limits<double>::infinity();
    }

    bool equals(T state) {
        return state == State::state;
    }

    int getNumHash() const{
        return numHash;
    }

    void setState(T state) {
        State::state = state;
    }

    T getState() {
        return State::state ;
    }

    double getCost() {
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

    bool operator==(const State<T> &anotherLine) const
    {
        return (state == anotherLine.state);
    }

};

namespace std
{
    template <>
    struct hash<State<pair<int,int>>>
    {
        size_t operator()(const State<pair<int,int>>& k) const
        {
            // Compute individual hash values for two data members and combine them using XOR and bit shifting
            return (size_t)k.getNumHash();
        }
    };
}


#endif //MILESTONE2_STATE_H

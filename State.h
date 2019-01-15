#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>
#include <cstring>
#include <limits>
#include <cstdlib>

/*
 * This class descrive state.
 * who is the current node, who is his father,
 * and what is the cost to go from the father to his son.
 * another member is the distance between some node to the goal of the matrix.
 */
template<class T>
class State {

    T *state;
    double nodeCost;
    double pathCost;
    State<T> *father;
    int numHash;
    double distToGoal;

public:


    State<T>(T *state) {
        State::state = state;
        State::father = nullptr;
        State::nodeCost = 1;
        State::pathCost = std::numeric_limits<double>::infinity();
        State::numHash = rand() + 1;
        distToGoal = 0;
    }

    State<T>(T *state, double c) {
        State::state = state;
        State::father = nullptr;
        State::nodeCost = c;
        State::pathCost = std::numeric_limits<double>::infinity();
        State::numHash = rand() + 1;
        distToGoal = 0;
    }

    double getDistance() const {
        return distToGoal;
    }

    void setDistance(double distance) {
        this->distToGoal = distance;
    }

    bool equals(State<T> *state) {
        return *(state->getState()) == *(State::state);
    }

    int getNumHash() {
        return numHash;
    }

    void setState(T *state) {
        State::state = state;
    }

    T *getState() {
        return State::state;
    }

    State<T> *getFather() {
        return State::father;
    }

    double getNodeCost() const {
        return State::nodeCost;
    }

    double getPathCost() const {
        return State::pathCost;
    }


    void setNodeCost(double nodeCost) {
        State::nodeCost = nodeCost;
    }


    void setPathCost(double pathCost) {
        State::pathCost = pathCost;
    }


    void setFather(State<T> *father) {
        State::father = father;
    }

    bool operator==(State<T> *state) {
        return *(state->getState()) == *(State::state);
    }

};

#endif //MILESTONE2_STATE_H

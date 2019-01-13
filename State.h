#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>
#include <cstring>
#include <limits>
#include <cstdlib>


template<class T>
class State {

    T* state;
    double nodeCost;
    double pathCost;
    State<T> *father;
    int numHash;
    double distToGoal;

public:


    State<T>(T* state) {
        State::state = state;
        State::father = nullptr;
        State::nodeCost = 1;
        State::pathCost = std::numeric_limits<double>::infinity();
        State::numHash = rand() + 1;
        distToGoal = 0;
    }

    State<T>(T* state, double c) {
        State::state = state;
        State::father = nullptr;
        State::nodeCost = c;
        State::pathCost = std::numeric_limits<double>::infinity();
        State::numHash = rand() + 1;
        distToGoal = 0;
    }

    double getDistance() const{
        return distToGoal;
    }
    void setDistance(double distance){
        this->distToGoal = distance;
    }

    bool equals(State<T>* state) {
        return *(state->getState()) == *(State::state);
    }

    int getNumHash() {
        return numHash;
    }

    void setState(T* state) {
        State::state = state;
    }

    T* getState() {
        return State::state ;
    }

    State<T>* getFather() {
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


    void setFather(State<T>* father) {
        State::father = father;
    }

    bool operator==(State<T>* state)
    {
        return *(state->getState()) == *(State::state);
    }



/*
    bool operator< (const State<T>& b) {
        return pathCost < b->getPathCost();
    }
    bool operator> (const State<T>& b) {
        return pathCost > b->getPathCost();
    }

 */



};
/*
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

*/
#endif //MILESTONE2_STATE_H

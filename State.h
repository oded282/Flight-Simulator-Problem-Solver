#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>



template <class T> class State {

    T state;
    double nodeCost;
    double pathCost;
    State<T>* father;

public:
    State(T state);

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


#endif //MILESTONE2_STATE_H

#ifndef MILESTONE2_ABSTRACTSEARCHER_H
#define MILESTONE2_ABSTRACTSEARCHER_H


#include <queue>
#include <map>
#include <iostream>
#include "Searcher.h"

enum color {
    WHITE, GRAY, BLACK
};

template<class T>
class myComparator {
public:
    int operator()(const State<T> *p1, const State<T> *p2) {
        return p1->getPathCost() + p1->getDistance() > p2->getPathCost() + p2->getDistance();
    }
};

template<class T>
class AbstractSearcher : public Searcher<T> {
protected:
    std::unordered_map<State<T>*, color> visited;
    std::priority_queue<State<T>*, std::vector<State<T> *>, myComparator<T>> open;
    std::queue<State<T>*> queue;

    //privet func.
    void initialize(std::vector<State<T> *> *vector) {
        for (State<T> *s : *vector) {
            this->visited[s] = WHITE;
        }
    }

    std::vector<State<T> *> *backTrace(State<T> *state) {
        auto trace = new std::vector<State<T> *>;
        while (state != nullptr) {
            trace->push_back(state);
            state = state->getFather();
        }
        return trace;
    }


public:
    AbstractSearcher() {}

    ~AbstractSearcher() {}

    virtual std::vector<State<T> *> *search(Searchable<T> *s) = 0;

    double getNumOfNodesEvaluated() {
        return this->numOfNodes;
    };

};

#endif //MILESTONE2_ABSTRACTSEARCHER_H

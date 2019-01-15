#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include <queue>
#include <bits/unordered_set.h>
#include <algorithm>
#include "AbstractSearcher.h"
#include "State.h"

/*
 * This algorithm is one of the searchers.
 * it search for the solution and work as best first search works.
 * we use pririty queue for this algorithm.
 */

template <class T>
class BestFirstSearch : public AbstractSearcher<T> {


public:

    BestFirstSearch(){
        this->numOfNodes=0;
    };


    std::vector<State<T>*>* search(Searchable<T>* s) {
        this->initialize(s->getAllStates());
        // initial open
        State<T>* first = s->getInitial();
        first->setPathCost(first->getNodeCost());
        this->open.push(first);

        while (!this->open.empty()) { // untill the queue isn't empty
            // get the most lower path cost.
            State<T>* n = this->open.top();
            this->open.pop();
            this->visited.at(n) = BLACK;
            this->numOfNodes++;

            // check if it is the goal.
            if (n->equals(s->getGoal())) {
                return this->backTrace(n);
            }
            // get all the neighbors.
            std::vector<State<T>*>* succerssors = (s->getPossibleStates(n));

            for (State<T>* it : *succerssors) { // check state's children.

                if (it->getNodeCost() == -1){
                    continue;
                }
                double currentPathCost = n->getPathCost() + it->getNodeCost();
                // if s is not in open and not in closed.
                if (this->visited.at(it) == WHITE) {
                    this->visited.at(it) = GRAY;
                    it->setFather(n);
                    it->setPathCost(currentPathCost);
                    this->open.push(it);

                } else if (currentPathCost < it->getPathCost()) {
                    it->setFather(n);
                    it->setPathCost(currentPathCost);
                    if (this->visited.at(it) == BLACK) {
                        this->visited.at(it) = GRAY;
                        this->open.push(it);
                    }
                }
            }
        }
        return nullptr;
    }
};




#endif //MILESTONE2_BESTFIRSTSEARCH_H

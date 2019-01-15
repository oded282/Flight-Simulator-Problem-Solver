#ifndef MILESTONE2_BREADTHFIRSTSEARCH_H
#define MILESTONE2_BREADTHFIRSTSEARCH_H

#include <queue>
#include "State.h"
#include "AbstractSearcher.h"

/*
 * This algorithm is one of the searchers.
 * it search for the solution and work as breadth first search works.
 * we use queue for this algorithm.
 */
template<class T>
class BreadthFirstSearch : public AbstractSearcher<T> {

public:

    virtual std::vector<State<T>*> *search(Searchable<T>* s) {
        this->initialize(s->getAllStates());
        State<T>* first = s->getInitial();
        first->setPathCost(first->getNodeCost());
        this->queue.push(first);

        while (!this->queue.empty()) { // run until the queue is empty

            State<T>* currentState = this->queue.front(); // get the root of searchable.
            this->queue.pop();
            this->numOfNodes++;

            this->visited[currentState] = BLACK;

            for (State<T>* child : *s->getPossibleStates(currentState)) { // check state's children.

                if (child->getNodeCost() == -1) {
                    this->visited.at(child) == BLACK;
                    continue;
                }
                if (this->visited.at(child) == WHITE) {
                    child->setFather(currentState);
                    child->setPathCost(currentState->getPathCost() + child->getNodeCost());
                    this->visited.at(child) = GRAY;

                    if (child == s->getGoal()) { // case the children in our goal.
                        return this->backTrace(child);
                    }
                    this->queue.push(child);
                }
            }
        }
        return nullptr;
    }

};


#endif //MILESTONE2_BREADTHFIRSTSEARCH_H

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H

#include "AbstractSearcher.h"
#include <unordered_map>
#include <stack>
#include <iostream>

/*
 * This algorithm is one of the searchers.
 * it search for the solution and work as depth first search works.
 * we use stack for this algorithm.
 */

template<class T>
class DepthFirstSearch : public AbstractSearcher<T> {

public:



    virtual std::vector<State<T>*>* search (Searchable<T>* s){

        if (s->getInitial() == s->getGoal()){
            return this->backTrace(s->getInitial());
        }

        this->initialize(s->getAllStates());

        std::stack<State<T>*> stack;
        State<T>* first = s->getInitial();
        first->setPathCost(first->getNodeCost());
        stack.push(first);

        while (!stack.empty()){

            State<T>* n = stack.top(); // get the root of this searchable.
            stack.pop();
            this->visited.at(n) = BLACK;
            this->numOfNodes++;

            std::vector<State<T>*>* succerssors = s->getPossibleStates(n);

            for(State<T>* it : *succerssors) { // check state's children.

                if (it == s->getGoal()){ // case the child is the goal
                    it->setFather(n);
                    it->setPathCost(n->getPathCost() + it->getNodeCost());
                    return this->backTrace(it);
                }

                if (it->getNodeCost() == -1){
                    continue;
                }

                if (this->visited.at(it) == WHITE) { // if this child checked for the first time.
                    this->visited.at(it) = GRAY;
                    it->setFather(n);
                    it->setPathCost(n->getPathCost() + it->getNodeCost());
                    stack.push(it);
                }
            }
        }
        return nullptr;
    }
};


#endif //MILESTONE2_DFS_H

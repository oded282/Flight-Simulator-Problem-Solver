#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H

#include "AbstractSearcher.h"
#include <unordered_map>
#include <stack>
#include <iostream>

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

            State<T>* n = stack.top();
            stack.pop();
            this->visited.at(n) = BLACK;

            std::vector<State<T>*>* succerssors = s->getPossibleStates(n);

            for(State<T>* it : *succerssors) {

                if (it == s->getGoal()){
                    it->setFather(n);
                    it->setPathCost(n->getPathCost() + it->getNodeCost());
                    return this->backTrace(it);
                }

                if (it->getNodeCost() == -1){
                    continue;
                }

                if (this->visited.at(it) == WHITE) {
                    this->visited.at(it) = GRAY;
                    it->setFather(n);
                    it->setPathCost(n->getPathCost() + it->getNodeCost());
                    stack.push(it);
                    this->numOfNodes++;
                }
            }
        }
        return nullptr;
    }
};


#endif //MILESTONE2_DFS_H

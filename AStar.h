#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H

#include <math.h>
#include <unordered_set>
#include "AbstractSearcher.h"

template<class T>
class AStar : public AbstractSearcher<T> {

    std::unordered_map<State<T>*, color> visited;
    std::priority_queue<State<T>*,std::vector<State<T>*>,myComparator<T>> open ;

    void initialization (std::vector<State<T>*>* vector){
        for (State<T>* s : *vector ) {
            this->visited[s] = WHITE;
        }
    }

    static std::vector<State<T> *> *backTrace(State<T> *state) {
        std::vector<State<T> *> *trace = new std::vector<State<T> *>;
        while (state != nullptr) {
            trace->push_back(state);
            state = state->getFather();
        }
        return trace;
    }


public:

    std::vector<State<T>*>* search (Searchable<T>* s){

        initialization(s->getAllStates());
        State<T>* first = s->getInitial();
        first->setPathCost(first->getNodeCost());
        s->setDistance(first,s->getGoal());
        this->open.push(first);

        while (!this->open.empty()) {

            this->numOfNodes++;
            // get the most lower path cost.
            State<T>* n = this->open.top();
            this->open.pop();
            this->visited.at(n) = BLACK;

            // check if it is the goal.
            if (n->equals(s->getGoal())) {
                return backTrace(s->getGoal());
            }
            // get all the neighbors.
            std::vector<State<T>*>* succerssors = s->getPossibleStates(n);

            for (State<T>* it : *succerssors) {
                if (it->getNodeCost() == -1){
                    continue;
                }
                double currentPathCost = n->getPathCost() + it->getNodeCost();
                // if s is not in open and not in closed.
                if (this->visited.at(it) == WHITE) {
                    this->visited.at(it) = GRAY;
                    s->setDistance(it,s->getGoal());
                    it->setFather(n);
                    it->setPathCost(currentPathCost);
                    this->open.push(it);

                } else if (currentPathCost < it->getPathCost() && this->visited.at(it) != BLACK) {
                    it->setFather(it);
                    it->setPathCost(currentPathCost);
                    if (this->visited.at(it) == GRAY) {
                        this->open.push(it);
                    }
                }
            }
        }
        return nullptr;
    }




};


#endif //MILESTONE2_ASTAR_H

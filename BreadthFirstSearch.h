#ifndef MILESTONE2_BREADTHFIRSTSEARCH_H
#define MILESTONE2_BREADTHFIRSTSEARCH_H

#include <queue>
#include "State.h"
#include "AbstractSearcher.h"


template<class T>
class BreadthFirstSearch : public AbstractSearcher<State<T>> {
    std::queue<State<T>*> queue;
    std::map<State<T>*,color> visited;

public:

    void initialize(std::vector<State<T>*>* vector) {
        for (State<T>* state: *vector) {
            this->visited[state] = WHITE;
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


    virtual std::vector<State<T>*> *search(Searchable<T>* s) {
        initialize(s->getAllStates());
        State<T>* first = s->getInitial();
        first->setPathCost(first->getNodeCost());
        queue.push(first);

        while (!queue.empty()) {

            State<T>* currentState = queue.front();
            queue.pop();

            this->visited[currentState] = BLACK;

            for (State<T>* child : *s->getPossibleStates(currentState)) {

                if (child->getNodeCost() == -1) {
                    this->visited.at(child) == BLACK;
                    continue;
                }
                if (this->visited.at(child) == WHITE) {
                    child->setFather(currentState);
                    child->setPathCost(currentState->getPathCost() + child->getNodeCost());
                    this->visited.at(child) = GRAY;
                    this->numOfNodes++;
                    if (child == s->getGoal()) {
                        return backTrace(child);
                    }
                    queue.push(child);
                }
            }
        }
        return nullptr;
    }

};


#endif //MILESTONE2_BREADTHFIRSTSEARCH_H

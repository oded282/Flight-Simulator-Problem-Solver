#ifndef MILESTONE2_BREADTHFIRSTSEARCH_H
#define MILESTONE2_BREADTHFIRSTSEARCH_H

#include <queue>
#include "State.h"
#include "AbstractSearcher.h"



template <class T>
class BreadthFirstSearch :public AbstractSearcher<State<T>>  {
    std::queue <State<T>*> queue;

public:

    void initialize(std::vector<State<T>>* s){
        for(State<T> state:s){
            this->visited[s] = WHITE;
        }
    }

    static std::vector<State<T>*>* backTrace(State<T>* state) {
        std::vector<State<T>*>* trace;
        while (state != NULL) {
            trace->push_back(state);
            state = state->getFather();
        }
        return trace;
    }


    virtual std::vector<State<T>*>* search(Searchable<T>* s){
        initialize(s->getAllStates());
        State<T>* first = s->getInitial();
        first->setPathCost(first->getNodeCost());
        queue.push(first);

        while(!queue.empty()){

            State<T>* currentState = queue.front();
            queue.pop();

            if(currentState == s->getGoal()){
                return backTrace(currentState);
            }

            this->visited[currentState] = BLACK;

            for(State<T> child : s->getPossibleStates(currentState)){

                if (child.getNodeCost() == -1){
                    continue;
                }
                if (this->visited.at(child) == WHITE) {
                    child.setFather(currentState);
                    child.setPathCost(currentState->getPathCost() + child.getNodeCost());
                    this->visited.at(child) = GRAY;

                    queue.push(child);
                }
            }
        }
        return nullptr;
    }

};


#endif //MILESTONE2_BREADTHFIRSTSEARCH_H
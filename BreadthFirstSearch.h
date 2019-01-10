#ifndef MILESTONE2_BREADTHFIRSTSEARCH_H
#define MILESTONE2_BREADTHFIRSTSEARCH_H

#include <queue>
#include "State.h"
#include "AbstractSearcher.h"

template <class T>
class BreadthFirstSearch :public AbstractSearcher<State<T>>  {
    std::queue <State<T>> queue;

public:

    virtual std::vector<State<T>>* search(Searchable<T>* s){
        initialize(s->getAllStates());
        State<T> first = s->getInitial();
        first.setPathCost(first.getNodeCost());
        queue.push(first);

        while(!queue.empty()){

            State<T> currentState = queue.top();
            queue.pop();

            if(currentState == s->getGoal()){
                return backTrace(currentState);
            }

            this->visited.at(currentState) = BLACK;

            for(State<T> child: s->getPossibleStates(s)){

                if (child.getNodeCost() == -1){
                    continue;
                }
                if (this->visited.at(child) == WHITE) {
                    child.setFather(currentState);
                    child.setPathCost(currentState.getPathCost() + child.getNodeCost());
                    this->visited.at(child) = GRAY;

                    queue.push(child);
                }
            }
        }
        return nullptr;
    }

    void initialize(std::vector<State<T>> s){
        for(State<T> state:s){ //  0 = didn't visit, 1 reached but not done, treatment finished.
            this->visited[s] = WHITE;
        }
    }

};


#endif //MILESTONE2_BREADTHFIRSTSEARCH_H

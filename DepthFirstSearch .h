#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H


#include "AbstractSearcher.h"
#include <unordered_map>
#include <stack>

template<class T>
class DepthFirstSearch : public AbstractSearcher<T> {
protected:
    std::unordered_map<State<T>*, color> visited;
    //std::unordered_map<State<T>*, unsigned int>mapTimeD;
    //std::unordered_map<State<T>*, unsigned int>mapTimeF;

    static std::vector<State<T> *>* backTrace(State<T> *state) {
        auto trace =  new std::vector<State<T> *>;
        while (state != nullptr) {
            trace->push_back(state);
            state = state->getFather();
        }
        return trace;
    }

    void initialize (std::vector<State<T>*>* vector){
        for (State<T>* s : *vector ){
            this->visited[s] = WHITE;
      //      this->mapTimeD[s] = 0;
        //    this->mapTimeF[s] = 0;
        }
    }

public:
    virtual std::vector<State<T>*>* search (Searchable<T>* s){

        if (s->getInitial() == s->getGoal()){
            return backTrace(s->getInitial());
        }

        initialize(s->getAllStates());

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
                    return backTrace(it);
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

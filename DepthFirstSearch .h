#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H


#include "AbstractSearcher.h"
#include <unordered_map>
#include <stack>

template<class T>
class DFS : public AbstractSearcher<T> {
protected:
    std::unordered_map<State<T>, unsigned int>mapTimeD;
    std::unordered_map<State<T>, unsigned int>mapTimeF;



    void initializ (std::vector<State<T>> vector){
        for (State<T> s : vector ){
            this->visited[s] = WHITE;
            this->mapTimeD[s] = 0;
            this->mapTimeF[s] = 0;
        }
    }

public:
    virtual std::vector<State<T>> search (Searchable<T> s){

        initializ(s.getAllStates());
        std::stack<State<T>> stack;
        s.getInitial()->setPathCost(s.getInitial()->getNodeCost());
        stack.push(s.getInitial());
        unsigned int t = 0;

        while (!stack.empty()){

            State<T> n = stack.top();
            stack.pop();
            this->visited.at(n) = BLACK;

            if (n == s.getGoal()){
                return backTrace(n);
            }

            std::vector<State<T>> succerssors = s.getAllPossibleStates(n);
            // remove the father.
            succerssors.erase(n);

            for(State<T> it : succerssors) {

                if (it.getNodeCost() == -1){
                    continue;
                }

                if (this->visited.at(it) == WHITE) {
                    this->visited.at(n) = GRAY;
                    stack.push(it);
                }
            }
        }

        std::vector<State<T>> v;
        return v;
    }


};


#endif //MILESTONE2_DFS_H

#include <stack>
#include "DepthFirstSearch .h"


template <class T>

void DFS<T>::initializ (std::vector<State<T>> vector){

    for (State<T> s : vector ){
        this->mapColor[s] = WHITE;
        this->mapTimeD[s] = 0;
        this->mapTimeF[s] = 0;
    }
}


template <class T>
std::vector<State<T>> DFS<T>::search(Searchable<T> s) {

    initializ(s.getAllStates());
    std::stack<State<T>> stack;
    s.getInitial()->setPathCost(s.getInitial()->getNodeCost());
    stack.push(s.getInitial());
    unsigned int t = 0;

    while (!stack.empty()){

        State<T> n = stack.top();
        stack.pop();
        mapColor.at(n) = BLACK;

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

            if (mapColor.at(it) == WHITE) {
                mapColor.at(n) = GRAY;
                stack.push(it);
            }
        }
    }

    std::vector<State<T>> v;
    return v;
}


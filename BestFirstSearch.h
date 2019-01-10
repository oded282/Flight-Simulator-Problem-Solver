#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include <queue>
#include <bits/unordered_set.h>
#include "AbstractSearcher.h"

template <class T>

class myComparator
{
public:
    int operator() (const State<T>* p1, const State<T>* p2)
    {
        return p1->getPathCost() > p2->getPathCost();
    }
};




template<
        class T,
        class Container = std::vector<T>,
        class Compare = std::less<typename Container::value_type>
>
class MyQueue : public std::priority_queue<T, Container, myComparator<T>> {
public:
    typedef typename
    std::priority_queue<
            T,
            Container,
            Compare>::container_type::const_iterator const_iterator;

    const_iterator find(const T &val) const {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first != last) {
            if (*first == val) return first;
            ++first;
        }
        return last;
    }
};




template <class T>
class BestFirstSearch : public AbstractSearcher<State<T>> {

    std::priority_queue<State<T>*,std::vector<State<T>*>,myComparator<T>> open ;
    void initialization (std::vector<State<T>>* vector){
            for (State<T> s : *vector ) {
            }
    }

public:


    BestFirstSearch(){
        this->numOfNodes=0;
    };

    std::vector<State<T>*>* search(Searchable<T>* s) {
        //initialization(s->getAllStates());
        //TODO initialis func.
        // initial open
        s->getInitial()->setPathCost(s->getInitial()->getCost());
        this->open.push(s->getInitial());
        std::unordered_set<State<T>*> closed;

        while (!open.empty()) {
            //TODO check if this is the right place for counting.
            this->numOfNodes++;
            // get the most lower path cost.
            State<T>* n = open.top();
            open.pop();
            // insert to closed.
            closed.insert(n);
            // check if it is the goal.
            if (n->equals(s->getGoal())) {
                return backTrace(s->getGoal());
            }
            // get all the neighbors.
            std::vector<State<T>> succerssors = *(s->getPossibleStates(n->getState()));
            // remove the father.
            succerssors.erase(n);
            for (State<T> it : succerssors) {
                if (it.getNodeCost() == -1){
                    continue;
                }
                double currentPathCost = n->setPathCost() + it.getCost();
                // if s is not in open and not in closed.
                if (MyQueue<T>::find(it) != it && closed.contains(it)) {
                    it.setFather(n);
                    it.setPathCost(currentPathCost);
                    open.push(it);

                } else if (currentPathCost < it.getPathCost()) {
                    it.setFather(n);
                    it.setPathCost(currentPathCost);
                    if (MyQueue<T>::find(it) != it) {
                        open.push(it);
                    }
                }
            }
        }
        return nullptr;
    }

};




#endif //MILESTONE2_BESTFIRSTSEARCH_H

#include <unordered_set>
#include "BestFirstSearch.h"
#include <queue>


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


template<class T>
std::vector<State<T>> BestFirstSearch<T>::search(Searchable<T> s) {
    //TODO initialis func.
    // initial open
    s.getInitial().setPathCost(s.getInitial().getCost());
    open.push(s.getInitial());
    std::unordered_set<State<T>> closed;

    while (!open.empty()) {
        //TODO check if this is the right place for counting.
        this->numOfNodes++;
        // get the most lower path cost.
        State<T> n = open.top();
        open.pop();
        // insert to closed.
        closed.insert(n);
        // check if it is the goal.
        if (n.equals(s.getGoal())) {
            return backTrace(s.getGoal());
        }
        // get all the neighbors.
        std::vector<State<T>> succerssors = s.getAllPossibleStates(n);
        // remove the father.
        succerssors.erase(n);
        for (State<T> s : succerssors) {

            double currentPathCost = n.setPathCost() + s.getCost();
            // if s is not in open and not in closed.
            if (MyQueue<T>::find(s) != s && closed.find(s) == closed.end()) {
                s.setFather(n);
                s.setPathCost(currentPathCost);
                open.push(s);

                } else if (currentPathCost < s.getPathCost()) {
                s.setFather(n);
                s.setPathCost(currentPathCost);
                if (MyQueue<T>::find(s) != s) {
                    open.push(s);
                }
            }
        }
    }
    std::vector<State<T>> v;
    return v;
}


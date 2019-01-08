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
std::vector<State<T>> BestFirstSearch<T>::backTrace(State<T> state) {
    std::vector<State<T>> trace;
    while (state != NULL) {
        trace.push_back(state);
        state = state.getFather();
    }
    return trace;
}

template<class T>
std::vector<State<T>> BestFirstSearch<T>::search(Searchable<T> s) {
    s.getInitial().setPathCost(s.getInitial().getCost());
    open.push(s.getInitial());
    std::unordered_set<State<T>> close;

    while (!open.empty()) {

        State<T> n = open.top();
        open.pop();

        close.insert(n);

        if (n.equals(s.getGoal())) {
            return backTrace(s.getGoal());
        }

        std::vector<State<T>> succerssors = s.getAllPossibleStates(n);

        for (State<T> s : succerssors) {
            double currentPathCost = n.setPathCost() + s.getCost();
            if (MyQueue<T>::find(s) != s && close.find(s) == close.end()) {
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

int main (){





}


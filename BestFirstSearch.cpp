#include <unordered_set>
#include "BestFirstSearch.h"
#include "SearchableMatrix.h"
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

template <class T>

void BestFirstSearch<T>::initializ (std::vector<State<T>> vector){

    for (State<T> s : vector ){

    }


}


template<class T>
std::vector<State<T>> BestFirstSearch<T>::search(Searchable<T> s) {
    initializ(s.getAllStates());
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


int main(){

    std::pair<int,int> p1 (0,0) ;
    State<std::pair<int,int>> s1(p1 , 1);

    std::pair<int,int> p2 (1,0) ;
    State<std::pair<int,int>> s2(p2 , 1);

    std::pair<int,int> p3 (2,0) ;
    State<std::pair<int,int>> s3(p3 , 5);

    std::pair<int,int> p4 (1,1) ;
    State<std::pair<int,int>> s4(p4 , 50);

    std::pair<int,int> p5 (1,2) ;
    State<std::pair<int,int>> s5(p5 , 0);

    std::pair<int,int> p6 (0,2) ;
    State<std::pair<int,int>> s6(p6 , 8);

    std::pair<int,int> p7 (2,1) ;
    State<std::pair<int,int>> s7(p7 , 20);

    std::pair<int,int> p8 (2,2) ;
    State<std::pair<int,int>> s8(p8 , 0);

    std::pair<int,int> p9 (0,1) ;
    State<std::pair<int,int>> s9(p9 , 7);

    std::vector<State<std::pair<int,int>>> v1;
    v1.push_back(s2);
    v1.push_back(s9);

    std::vector<State<std::pair<int,int>>> v2;
    v2.push_back(s1);
    v2.push_back(s4);
    v2.push_back(s3);

    std::vector<State<std::pair<int,int>>> v3;
    v3.push_back(s2);
    v3.push_back(s7);

    std::vector<State<std::pair<int,int>>> v4;
    v4.push_back(s2);
    v4.push_back(s9);
    v4.push_back(s5);
    v4.push_back(s7);

    std::vector<State<std::pair<int,int>>> v5;
    v5.push_back(s6);
    v5.push_back(s4);
    v5.push_back(s8);

    std::vector<State<std::pair<int,int>>> v6;
    v6.push_back(s4);
    v6.push_back(s9);
    v6.push_back(s5);

    std::vector<State<std::pair<int,int>>> v7;
    v1.push_back(s3);
    v1.push_back(s4);
    v1.push_back(s8);


    std::vector<State<std::pair<int,int>>> v8;
    v8.push_back(s5);
    v8.push_back(s7);

    std::vector<State<std::pair<int,int>>> v9;
    v1.push_back(s1);
    v1.push_back(s4);
    v1.push_back(s6);

    std::unordered_map<State<std::pair<int,int>>,std::vector<State<std::pair<int,int>>>> map;

    map[s1] = v1;
    map[s2] = v2;
    map[s3] = v3;
    map[s4] = v4;
    map[s5] = v5;
    map[s6] = v6;
    map[s7] = v7;
    map[s8] = v8;
    map[s9] = v9;

    auto matrix = new SearchableMatrix(s1 , s8 , map , 3);

    auto bfs = new BestFirstSearch<State<std::pair<int,int>>>();

    return 1;
}




#include <unordered_set>
#include "BreadthFirstSearch.h"
#include "Searchable.h"
#include <unordered_map>

template<class T>
void BreadthFirstSearch<T>::initialize(std::vector<State<T>> s){
    for(State<T> state:s){
        visited[s] = false;
    }
}


template<class T>
std::vector<State<T>>* BreadthFirstSearch<T>::search(Searchable<T>* s) {
    initialize(s->getAllStates());



}
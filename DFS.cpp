#include "DFS.h"


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






}


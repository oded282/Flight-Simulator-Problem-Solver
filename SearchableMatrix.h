

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H


#include "Searchable.h"
template <class T>


class SearchableMatrix : public Searchable<std::pair<int,int>> {

    std::pair<int,int> pair;

public:

    SearchableMatrix(State<std::pair<int,int>> initial ,State<std::pair<int,int>> goal){
        this->initial = initial;
        this->goal = goal;
    }

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H

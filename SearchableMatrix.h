

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H


#include "Searchable.h"

class SearchableMatrix : public Searchable<T> {

    std::pair<int,int>

public:

    SearchableMatrix(State<T> initial ,State<T> goal){
        Searchable::initial = initial;
        Searchable::goal = goal;
    }

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H

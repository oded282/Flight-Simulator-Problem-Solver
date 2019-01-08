

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H


#include "Searchable.h"

class SearchableMatrix : public Searchable<std::pair<int,int>> {

    std::pair<int,int> pair;

public:

    SearchableMatrix(State<std::pair<int,int>> initial ,State<std::pair<int,int>> goal){
        Searchable::initial = initial;
        Searchable::goal = goal;
    }

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H

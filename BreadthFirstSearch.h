//
// Created by almog on 10/01/19.
//

#ifndef MILESTONE2_BREADTHFIRSTSEARCH_H
#define MILESTONE2_BREADTHFIRSTSEARCH_H

#include "State.h"
#include "AbstractSearcher.h"

template <class T>
class BreadthFirstSearch :public AbstractSearcher<State<T>>  {
    std::unordered_map<State<T>,bool> visited;;

public:


    virtual std::vector<State<T>>* search(Searchable<T>* s);

    void initialize(std::vector<State<T>> s);

};


#endif //MILESTONE2_BREADTHFIRSTSEARCH_H

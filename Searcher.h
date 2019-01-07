#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H


#include "Searchable.h"

class Searcher {

    double numOfNodes;
    double totalCost;

public:

    double search (Searchable s);
    double getNumOfNodesEvaluated();



};


#endif //MILESTONE2_SEARCHER_H

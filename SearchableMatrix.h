

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H
#include "Searchable.h"




class SearchableMatrix : public Searchable<std::pair<int,int>> {

    std::vector<std::vector<State<std::pair<int,int>>*>*>* stateMatrix;
    int matrixSize;

public:

    SearchableMatrix(State<std::pair<int,int>>* initial ,State<std::pair<int,int>>* goal, std::vector<std::vector<double>>* matrix, int matrixSize){
        this->initial = initial;
        this->goal = goal;
        this->matrixSize = matrixSize;

        stateMatrix = setStatesMatrix(matrix);

    }

    virtual std::vector<State<std::pair<int, int>>>* getPossibleStates(std::pair<int, int> pair);

    virtual std::vector<State<std::pair<int,int>>>* getAllStates();

    virtual State<std::pair<int,int>>* getInitial();

    virtual State<std::pair<int,int>>* getGoal();

    std::vector<std::vector<State<std::pair<int, int>>*>*>* setStatesMatrix(std::vector<std::vector<double>>* matrix);

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H

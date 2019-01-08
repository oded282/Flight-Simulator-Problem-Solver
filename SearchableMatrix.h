

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H
#include "Searchable.h"




class SearchableMatrix : public Searchable<std::pair<int,int>> {

    //std::unordered_map<State<std::pair<int,int>>,std::vector<State<std::pair<int,int>>>>* stateMatrix;
    std::vector<std::vector<State<std::pair<int,int>>>>* stateMatrix;
    int matrixSize;

public:

    SearchableMatrix(State<std::pair<int,int>>* initial ,State<std::pair<int,int>>* goal, std::vector<std::vector<int>>* matrix, int matrixSize){
        this->initial = initial;
        this->goal = goal;
        this->matrixSize = matrixSize;

        stateMatrix = setStatesMatrix(matrix);
       // this->possibleStates = setPossibleStates(stateMatrix);

    }

    virtual std::vector<State<std::pair<int,int>>*>* getAllPossibleStates(State<std::pair<int,int>> s){};

    virtual std::vector<State<std::pair<int,int>>> getAllStates(){};

    virtual State<std::pair<int,int>>* getInitial(){};

    virtual State<std::pair<int,int>>* getGoal(){};

    //std::unordered_map<State<State<std::pair<int,int>>*>*,std::vector<State<State<std::pair<int,int>>*>*>*>* setPossibleStates(std::vector<std::vector<State<std::pair<int,int>>*>>* stateMatrix);
    std::vector<std::vector<State<std::pair<int,int>>>>* setStatesMatrix(std::vector<std::vector<int>>* matrix);

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H

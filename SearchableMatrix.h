

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H
#include "Searchable.h"

using namespace std;
//template <class T>
class SearchableMatrix : public Searchable<std::pair<int,int>> {

    unordered_map<State<pair<int,int>>,vector<State<pair<int,int>>>>* stateMatrix;

public:

    SearchableMatrix(State<std::pair<int,int>>* initial ,State<std::pair<int,int>>* goal,unordered_map<State<pair<int,int>>,vector<State<pair<int,int>>>>* matrix, int matrixSize){
        this->initial = initial;
        this->goal = goal;
        stateMatrix = matrix;
        //this->possibleStates = setPossibleStates(stateMatrix);

    }

    SearchableMatrix(State<std::pair<int,int>>* initial ,State<std::pair<int,int>>* goal, std::vector<std::vector<int>>* matrix, int matrixSize){
        this->initial = initial;
        this->goal = goal;
        stateMatrix = setStatesMatrix(matrix);
        //this->possibleStates = setPossibleStates(stateMatrix);

    }

    virtual State<std::pair<int,int>>* getInitial(){};

    virtual State<std::pair<int,int>>* getGoal(){};

    //std::vector<std::vector<int>>* setPossibleStates(std::vector<std::vector<int>>* stateMatrix);
    std::unordered_map<State<std::pair<int,int>>,std::vector<State<std::pair<int,int>>>>* setStatesMatrix(std::vector<std::vector<int>>* matrix);

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H

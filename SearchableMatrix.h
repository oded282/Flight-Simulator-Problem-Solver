

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H
#include "Searchable.h"


using namespace std;
template <class T>
class SearchableMatrix : public Searchable<pair<int,int>> {

    std::vector<std::vector<std::pair<int,int>>>* stateMatrix;

public:

    SearchableMatrix(State<std::pair<int,int>>* initial ,State<std::pair<int,int>>* goal, std::vector<std::vector<int>>* matrix, int matrixSize){
        this->initial = initial;
        this->goal = goal;
        stateMatrix = setStatesMatrix(matrix);
        //this->possibleStates = setPossibleStates(stateMatrix);

    }

    virtual State<std::pair<int,int>>* getInitial(){};

    virtual State<std::pair<int,int>>* getGoal(){};

    //std::vector<std::vector<int>>* setPossibleStates(std::vector<std::vector<int>>* stateMatrix);
    unordered_map<State<pair<int,int>>,vector<State<pair<int,int>>>>* setStatesMatrix(vector<vector<int>>* matrix);

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H

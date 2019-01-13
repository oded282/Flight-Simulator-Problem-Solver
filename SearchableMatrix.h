

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H
#include "Searchable.h"




class SearchableMatrix : public Searchable<std::pair<int,int>> {

    std::vector<std::vector<State<std::pair<int,int>>*>*>* stateMatrix;
    int matrixSize;

public:

    SearchableMatrix(std::pair<int,int> initial ,std::pair<int,int> goal, std::vector<std::vector<double>*>* matrix, int matrixSize){
        this->matrixSize = matrixSize;

        stateMatrix = setStatesMatrix(matrix);
        initAndGoal(initial,goal);

    }

    void initAndGoal(std::pair<int,int> init, std::pair<int,int> goal);

    virtual std::vector<State<std::pair<int, int>>*>* getPossibleStates(State<std::pair<int, int>>* state);

    virtual std::vector<State<std::pair<int,int>>*>* getAllStates();

    virtual State<std::pair<int,int>>* getInitial();

    virtual State<std::pair<int,int>>* getGoal();

    std::vector<std::vector<State<std::pair<int, int>>*>*>* setStatesMatrix(std::vector<std::vector<double>*>* matrix);

    virtual void setDistance(State<std::pair<int, int>> *state, State<std::pair<int, int>> *goal);

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H

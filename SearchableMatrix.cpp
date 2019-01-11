
#include "SearchableMatrix.h"


std::vector<State<std::pair<int, int>>*>* SearchableMatrix::getPossibleStates(std::pair<int, int> pair) {
    int i = pair.first;
    int j = pair.second;
    auto temp = new std::vector<State<std::pair<int, int>>*>();

    if (i > 0 && i < matrixSize - 1 && j > 0 && j < matrixSize - 1) {

        temp->push_back((stateMatrix->at(j + 1))->at(i));
        temp->push_back((stateMatrix->at(j - 1))->at(i));
        temp->push_back((stateMatrix->at(j))->at(i + 1));
        temp->push_back((stateMatrix->at(j))->at(i - 1));
        return temp;
    }
    if (j - 1 >= 0) {
        temp->push_back((stateMatrix->at(j-1))->at(i));
    }
    if (j + 1 < matrixSize) {
        temp->push_back((stateMatrix->at(j + 1))->at(i));
    }
    if (i - 1 >= 0) {
        temp->push_back((stateMatrix->at(j))->at(i -1));
    }
    if (i + 1 < matrixSize) {
        temp->push_back((stateMatrix->at(j))->at(i + 1));
    }
    return temp;
}


std::vector<std::vector<State<std::pair<int, int>> *> *> *
SearchableMatrix::setStatesMatrix(std::vector<std::vector<double>*> *matrix) {
    int i = 0, j = 0;
    auto tempMatrix = new std::vector<std::vector<State<std::pair<int, int>> *> *>;
    //auto tempVec = new std::vector<State<std::pair<int, int>> *>;
    auto tempAllStates = new std::vector<State<std::pair<int, int>> *>();
    for (std::vector<double> *vec : *matrix) { // create matrix of state and array of states.
        auto tempVec = new std::vector<State<std::pair<int, int>> *>;
        for (double c : *vec) {
            auto pair = new std::pair<int, int>(i, j);
            auto s = new State<std::pair<int, int>>(pair, c);

            tempVec->push_back(s);
            j++;
        }
        tempMatrix->push_back(tempVec);
        (*tempAllStates).insert(tempAllStates->end(), tempVec->begin(), tempVec->end());
        j = 0;
        i++;
    }
    allStates = tempAllStates;
    return tempMatrix;
}

std::vector<State<std::pair<int, int>> *> *SearchableMatrix::getAllStates() {
    return allStates;
}

State<std::pair<int, int>> *SearchableMatrix::getInitial() {
    return initial;
};

State<std::pair<int, int>> *SearchableMatrix::getGoal() {
    return this->goal;
};

int main() {
    std::vector<double >* v1 = new std::vector<double>{0 , 4 , 7};
    std::vector<double >* v2 = new std::vector<double>{2 , 5 ,8};
    std::vector<double >* v3 = new std::vector<double>{3, 6,9};

    std::vector<std::vector<double >*>* matrix  = new std::vector<std::vector<double >*>;
    matrix->push_back(v1);
    matrix->push_back(v2);
    matrix->push_back(v3);


    std::pair<int,int>* p1 = new std::pair<int,int> (0,0) ;
    auto s1 = new State<std::pair<int,int>> (p1 , 0);

    std::pair<int,int>* p8 = new std::pair<int,int> (2,2) ;
    auto s8 = new State<std::pair<int,int>> (p8 , 0);

    auto s = new SearchableMatrix(s1 , s8 , matrix , 3);

    s->getPossibleStates(std::pair<int,int> (1,1));


}

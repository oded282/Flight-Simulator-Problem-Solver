
#include "SearchableMatrix.h"


std::vector<State<std::pair<int, int>>>* SearchableMatrix::getPossibleStates(std::pair<int, int> pair) {
    int i = pair.first;
    int j = pair.second;
    auto temp = new std::vector<State<std::pair<int, int>>>();
    //for (int i = 0; i < matrixSize; i++) {
        //for (int j = 0; j < matrixSize; j++) {
            //temp.erase(temp.begin(), temp.end());
            if (i > 0 && i < matrixSize - 1 && j > 0 && j < matrixSize - 1) {
                temp->push_back(stateMatrix[j + 1][i]);
                temp->push_back(stateMatrix[j - 1][i]);
                temp->push_back(stateMatrix[j][i + 1]);
                temp->push_back(stateMatrix[j][i - 1]);
                return temp;
            }
            if (j - 1 >= 0) {
                temp->push_back(stateMatrix[j - 1][i]);
            }
            if (j + 1 < matrixSize) {
                temp->push_back(stateMatrix[j + 1][i]);
            }
            if (i - 1 >= 0) {
                temp->push_back(stateMatrix[j][i - 1]);
            }
            if (i + 1 < matrixSize) {
                temp->push_back(stateMatrix[j][i + 1]);
            }
            return temp;
       // }
    //}
}


std::vector<std::vector<State<std::pair<int, int>>>>
SearchableMatrix::setStatesMatrix(std::vector<std::vector<double>> matrix) {
    int i = 0, j = 0;
    std::vector<std::vector<State<std::pair<int, int>>>> tempMatrix;
    std::vector<State<std::pair<int, int>>> tempVec;
    auto tempAllStates = new std::vector<State<std::pair<int, int>>>();
    for (std::vector<double> vec : matrix) { // create matrix of state and array of states.
        for (double c : vec) {
            std::pair<int, int> pair(i, j);
            State<std::pair<int, int>> s = State<std::pair<int, int>>(pair,c);
            tempVec.push_back(s);
            j++;
        }
        tempMatrix.push_back(tempVec);
        (*tempAllStates).insert(tempAllStates->end(),tempVec.begin(),tempVec.end());
        tempVec.erase(tempVec.begin(), tempVec.end());
        j = 0;
        i++;
    }
    allStates = tempAllStates;
    return tempMatrix;
}

std::vector<State<std::pair<int,int>>>*  SearchableMatrix::getAllStates(){
    return allStates;
}

State<std::pair<int,int>>* SearchableMatrix::getInitial(){
    return initial;
};

State<std::pair<int,int>>* SearchableMatrix::getGoal(){
    return goal;
};


int main() {
    std::pair<int, int> pair00(0, 0);
    std::pair<int, int> pair11(1, 1);

    std::vector<double> vec3;
    std::vector<double> vec2;
    std::vector<double> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    vec3.push_back(7);
    vec3.push_back(8);
    vec3.push_back(9);

    auto init = new State<std::pair<int, int>>(pair00);
    auto goal = new State<std::pair<int, int>>(pair11);

    std::vector<std::vector<double>> matrix;
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    int matrixSize = 3;
    SearchableMatrix *m = new SearchableMatrix(init, goal, matrix, matrixSize);

}
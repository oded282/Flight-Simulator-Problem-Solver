
#include "SearchableMatrix.h"



//std::unordered_map<State<State<std::pair<int,int>>*>*,std::vector<State<State<std::pair<int,int>>*>*>*>* SearchableMatrix::setPossibleStates(std::vector<std::vector<State<std::pair<int,int>>*>>*stateMatrix) {
//    for (std::vector<State<std::pair<int,int>>> vec : *stateMatrix) {
//        for (State<std::pair<int,int>> s : *stateMatrix) {
//
//        }
//    }
//}
//








std::vector<std::vector<State<std::pair<int,int>>>>* SearchableMatrix::setStatesMatrix(std::vector<std::vector<int>> *matrix) {
    int i =0, j=0;
    std::vector<std::vector<State<std::pair<int,int>>>>* tempMatrix;
    std::vector<State<std::pair<int,int>>> tempVec;
    for (std::vector<int> vec : *matrix) {
        for (int c : vec) {
            std::pair <int,int> pair (i,j);
            State<std::pair <int,int>> s = State<std::pair <int,int>>(pair);
            s.setNodeCost(c);
            tempVec.push_back(s);
            j++;
        }
        tempMatrix->push_back(tempVec); //  need to initial all states as well
        j = 0;
        i++;
    }
    return tempMatrix;
}




int main(){
    std::pair <int,int> pair00 (0,0);
    std::pair <int,int> pair11 (1,1);

    std::vector<int> vec2;
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);

    auto init = new State<std::pair<int,int>>(pair00);
    auto goal = new State<std::pair<int,int>>(pair11);

    std::vector<std::vector<int>>* matrix;
    matrix->push_back(vec1);
    matrix->push_back(vec2);
    int matrixSize = 1;
    SearchableMatrix* m = new SearchableMatrix(init,goal,matrix,matrixSize);

}
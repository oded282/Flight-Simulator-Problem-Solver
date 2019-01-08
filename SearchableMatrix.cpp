
#include "SearchableMatrix.h"


//template<>
//void SearchableMatrix<std::pair<int, int>>::setPossibleStates(std::vector<std::vector<int>> *stateMatrix) {
//     for () {
//         for () {
//
//         }
//     }
//}








template<>
unordered_map<State<pair<int,int>>,vector<State<pair<int,int>>>>* SearchableMatrix<std::pair<int, int>>::setStatesMatrix(std::vector<std::vector<int>> *matrix) {
    int i =0, j=0;
    std::vector<std::vector<int>>::iterator it;
    for (std::vector<int> vec : *matrix) {
        for (int c : vec) {
            std::pair <int,int> pair (i,j);
            State<std::pair<int,int>>* s = new State<std::pair <int,int>>(pair);
            s->setNodeCost(c);
            j++;
        }
        j = 0;
        i++;
    }
}




int main(){
    std::pair <int,int> pair00 (0,0);
    std::pair <int,int> pair01 (0,1);
    std::pair <int,int> pair10 (1,0);
    std::pair <int,int> pair11 (1,1);
    std::vector<int> vec1 = {1,2};
    std::vector<int> vec2 = {3,4};
    auto init = new State<std::pair<int,int>>(pair00);
    auto goal = new State<std::pair<int,int>>(pair11);
    std::vector<std::vector<int>>* matrix;
    matrix->push_back(vec1);
    matrix->push_back(vec2);
    int matrixSize = 1;
    SearchableMatrix<std::pair<int,int>>* m = new SearchableMatrix<std::pair<int,int>>(init,goal,matrix,matrixSize);


}
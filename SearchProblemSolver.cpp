#include "SearchProblemSolver.h"
#include <string>
#include <algorithm>
#include <iostream>

void initAndGoal(std::pair<int, int> &initial, std::pair<int, int> &goal, std::string::iterator it) {
    it--;
    goal.first = (int) (--(*it) - '0');
    goal.second = (int) (--(*it) - '0');
    it--;
    initial.first = (int) (--(*it) - '0');
    initial.second = (int) (--(*it) - '0');
}

std::vector<std::vector<double> *>* initTheMatrix(string problem){
    auto matrix = new std::vector<std::vector<double> *>;
    auto temp = new std::vector<double>;

    problem.erase(std::remove(problem.begin(), problem.end(), ','), problem.end());
    std::string::iterator it = problem.end();

    for (it; it != problem.begin(); it--) {
        if (*it == '\n') {
            matrix->push_back(temp);
            temp = new std::vector<double>;
        }
        temp->push_back(*it - '0');
    }
    return matrix;
}

template <class T>
string createPath(std::vector<State<T>*>* vector){
    std::string path;
}


string SearchProblemSolver:: solve(string problem) {

    std::pair<int, int> initial;
    std::pair<int, int> goal;

    initAndGoal(initial, goal, it);

    std::vector<std::vector<double> *>* matrix = initTheMatrix(problem);

    int col = (int)matrix->size();
    int row = *matrix[0].size();

    auto searcheableMatrix = new SearchableMatrix(initial,goal,matrix,matrix,row,col);

    return createPath(searcher.search(searcheableMatrix));



}
#include "SearchProblemSolver.h"
#include "BreadthFirstSearch.h"
#include <string>
#include <algorithm>
#include <iostream>


vector<string> splitByComma(string str) {
    vector<string> result;
    string val;
    for (auto itr = str.begin(); itr != str.end(); itr++) {
        if (*itr != ',' && *itr != '\r') {
            val += *itr;
        } else {
            result.push_back(val);
            val.clear();
            if (*itr == '\r') {
                result.push_back("\r\n");
                itr++;
            }
        }
    }
    return result;
}

void initAndGoal(std::pair<int, int> &initial, std::pair<int, int> &goal, std::vector<std::string>::iterator &it) {
    goal.second = stoi(*it);
    it--;
    goal.first = stoi(*it);
    it -= 2;
    initial.second = stoi(*it);
    it--;
    initial.first = stoi(*it);
    it -= 2;
}

std::vector<std::vector<double> *> *
initTheMatrix(string problem, std::pair<int, int> &initial, std::pair<int, int> &goal) {
    auto matrix = new std::vector<std::vector<double> *>;
    auto temp = new std::vector<double>;
    std::vector<string> problemVec;

    problemVec = splitByComma(problem);
    auto itBegin = problemVec.begin();
    auto it = problemVec.end();
    it -= 2;
    initAndGoal(initial, goal, it);
    it += 2;
    for (itBegin; itBegin != it + 1; itBegin++) {
        if (*itBegin == "\r\n") {
            itBegin++;
            matrix->push_back(temp);
            temp = new std::vector<double>;
        }
        temp->push_back(stod(*itBegin));
    }
    return matrix;
}

string createDirection(int i, int j){
    if(i == 0 && j ==1){
        return "Right";
    }
    if(i == 1 && j == 0){
        return "Down";
    }
    if(i  == -1 && j == 0){
        return "Up";
    }
    if(i == 0 && j == -1){
        return "Left";
    }
    return "";
}

template<class T>
string checkDirections(State<T> *s1, State<T> *s2) {
    int i;
    int j;
    if (s1->getState()->first == s2->getState()->first) {
        i = 0;
        if (s2->getState()->second > s1->getState()->second) {
            j = 1;
        } else {
            j = -1;
        }
    } else if (s1->getState()->first > s2->getState()->first) {
        i = -1;
        j = 0;
    } else {
        i = 1;
        j = 0;
    }
    return createDirection(i,j);
}

template<class T>
string createPath(std::vector<State<T>*> *vector) {
    std::string path;
    auto it = vector->end();
    it--;
    for (it; it != vector->begin(); it--) {
        path += checkDirections(*it,*(it - 1)) += ",";
    }
    path.erase(path.end() - 1);
    return path;
}


string SearchProblemSolver::solve(string problem) {

    std::pair<int, int> initial;
    std::pair<int, int> goal;


    std::vector<std::vector<double> *> *matrix = initTheMatrix(problem, initial, goal);

    int row = (int) matrix->size();
    int col = (int) (*matrix)[0]->size();

    auto searchMatrix = new SearchableMatrix(initial, goal, matrix, row, col);

    return createPath(searcher->search(searchMatrix));


}
/*

int main() {
    string problem = "4,7,2,9,10\r\n5,7,6,12,14\r\n11,12,19,45,23\r\n77,88,99,66,44\r\n0,0\r\n3,4\r\nend";
    auto b = new BreadthFirstSearch<std::pair<int, int>>();
    auto s = new SearchProblemSolver(b);
    s->solve(problem);
}*/

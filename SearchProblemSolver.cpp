#include "SearchProblemSolver.h"
#include "BreadthFirstSearch.h"
#include <string>
#include <algorithm>
#include <iostream>

/*
 * erase all the commas from the string and put each value inside
 * vector of all values.
 */
vector<string> splitByComma(string str) {
    vector<string> result;
    string val;
    for (auto itr = str.begin(); itr != str.end(); itr++) {
        if (*itr != ',' && *itr != '\n') {
            val += *itr;
        } else {
            result.push_back(val);
            val.clear();
            if (*itr == '\n') {
                result.push_back("\n");
            }
        }
    }
    return result;
}


/*
 * this function initial the goal and init values of the problem.
 */
void initAndGoal(std::pair<int, int> &initial, std::pair<int, int> &goal, std::vector<std::string>::iterator &it) {
    it-=2;
    goal.second = stoi(*it);
    it--;
    goal.first = stoi(*it);
    it -= 2;
    initial.second = stoi(*it);
    it--;
    initial.first = stoi(*it);
    it -= 2;
}


/*
 * This func run over the problem and push each value to vector of douvle values.
 */
std::vector<std::vector<double> *> *
initTheMatrix(string problem, std::pair<int, int> &initial, std::pair<int, int> &goal) {
    auto matrix = new std::vector<std::vector<double> *>;
    auto temp = new std::vector<double>;
    std::vector<string> problemVec;


    problem.erase( remove( problem.begin(), problem.end(), ' ' ), problem.end() );
    problemVec = splitByComma(problem); // erase commas.
    auto itBegin = problemVec.begin();
    auto it = problemVec.end();
    it -= 2;
    initAndGoal(initial, goal, it); // initial the start and end of the problem.
    it += 2;
    for (itBegin; itBegin != it + 1; itBegin++) { // run over values and push them to vector.
        if (*itBegin == "\n") {
            itBegin++;
            matrix->push_back(temp);
            temp = new std::vector<double>;
        }
        temp->push_back(stod(*itBegin));
    }
    return matrix;
}
 /*
  * This func create the needed string of the direction from
  * one state to another.
  */
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

/*
 *This func check the relation between two states
 * by their position(i,j). if the next state is left to the current initial
 * j to -1, if it's to the right initial j to 1
 * if next above current initial i to -1 if it's underneath initial  j to -1.
 */
template<class T>
string checkDirections(State<T> *s1, State<T> *s2) {
    int i;
    int j;
    if (s1->getState()->first == s2->getState()->first) { // case i's equals.
        i = 0;
        if (s2->getState()->second > s1->getState()->second) {
            j = 1;
        } else {
            j = -1;
        }
    } else if (s1->getState()->first > s2->getState()->first) { // case  i  < j
        i = -1;
        j = 0;
    } else {
        i = 1;
        j = 0;
    }
    return createDirection(i,j);
}

/*
 * This func check for position relation between two states in the path.
 */
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

/*
 *
 */
string SearchProblemSolver::solve(string problem) {

    std::pair<int, int> initial;
    std::pair<int, int> goal;

    cout<<"before initTheMatrix"<<endl;
    std::vector<std::vector<double> *> *matrix = initTheMatrix(problem, initial, goal);
    cout<<"after initTheMatrix"<<endl;
    int row = (int) matrix->size();
    int col = (int) (*matrix)[0]->size();

    this->searchMatrix = new SearchableMatrix(initial, goal, matrix, row, col);
    string s = createPath(searcher->search(searchMatrix));
    return s;


}

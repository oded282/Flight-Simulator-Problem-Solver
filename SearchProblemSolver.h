
#ifndef MILESTONE2_SEARCHPROBLEMSOLVER_H
#define MILESTONE2_SEARCHPROBLEMSOLVER_H


#include "Solver.h"
#include "SearchableMatrix.h"
#include "Searcher.h"
#include "AStar.h"


/*
 * This class is specific solver.
 * it contains solver who can solve problems.
 */
class SearchProblemSolver : public Solver {

    Searcher<std::pair<int, int>> *searcher;
    SearchableMatrix* searchMatrix ;

public:
    SearchProblemSolver() {
        searcher = new AStar<std::pair<int, int>>();
        searchMatrix = nullptr;
    }

    SearchProblemSolver(Searcher<std::pair<int, int>> *s) {
        searcher = s;
    }

    virtual string solve(string problem);

    ~SearchProblemSolver() {
        delete searcher;
        if (searchMatrix != nullptr) {
            delete searchMatrix;
        }
    }
};


#endif //MILESTONE2_SEARCHPROBLEMSOLVER_H

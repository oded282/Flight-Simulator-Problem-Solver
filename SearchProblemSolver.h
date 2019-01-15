
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


public:
    SearchProblemSolver() {
        searcher = new AStar<std::pair<int, int>>();
    }

    SearchProblemSolver(Searcher<std::pair<int, int>> *s) {
        searcher = s;
    }

    virtual string solve(string problem);

    ~SearchProblemSolver() {
        delete searcher;
    }
};


#endif //MILESTONE2_SEARCHPROBLEMSOLVER_H

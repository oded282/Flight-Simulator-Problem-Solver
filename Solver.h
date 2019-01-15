
#ifndef MILESTONE2_SOLVER_H
#define MILESTONE2_SOLVER_H

#include <string>

using namespace std;

/*
 * This interface represent the algorithms or any other thing
 * that can solve problem.
 */
class Solver {

public:
    virtual string solve(string) = 0;

    virtual ~Solver() = default;
};

#endif //MILESTONE2_SOLVER_H

#ifndef MILESTONE2_FILECACHMANAGER_H
#define MILESTONE2_FILECACHMANAGER_H


#include "Solver.h"
#include "CacheManager.h"

class FileCachManager : public CacheManager {


public:

    void saveSolution(Problem problem, Solution solution) override;

    bool isSolution(Problem problem) override;

    Solution getSolution(Problem problem) override;
};


#endif //MILESTONE2_FILECACHMANAGER_H

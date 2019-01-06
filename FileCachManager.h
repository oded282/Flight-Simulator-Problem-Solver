#ifndef MILESTONE2_FILECACHMANAGER_H
#define MILESTONE2_FILECACHMANAGER_H


#include "Solver.h"
#include "CacheManager.h"
#include <unordered_map>


class FileCachManager : public CacheManager {
    unordered_map<string, string> oldMap;
    unordered_map<string,string> newMap;

public:

    virtual void saveSolution(string problem, string solution);
    virtual string getSolution(string problem);
    virtual void addSolution(string problem, string solution );
    virtual void loadSolution();
};


#endif //MILESTONE2_FILECACHMANAGER_H

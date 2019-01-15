#ifndef MILESTONE2_FILECACHMANAGER_H
#define MILESTONE2_FILECACHMANAGER_H


#include "Solver.h"
#include "CacheManager.h"
#include <unordered_map>

class FileCacheManager : public CacheManager {
    unordered_map<string, string> oldMap;
    unordered_map<string,string> newMap;

public:
    FileCacheManager(){};
    virtual void saveSolution();
    virtual string getSolution(string problem);
    virtual void addSolution(string problem, string solution);
    virtual void loadSolution();
};


#endif //MILESTONE2_FILECACHMANAGER_H

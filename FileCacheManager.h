#ifndef MILESTONE2_FILECACHMANAGER_H
#define MILESTONE2_FILECACHMANAGER_H


#include "Solver.h"
#include "CacheManager.h"
#include <unordered_map>


/*
 * This class saves info in files.
 */
class FileCacheManager : public CacheManager {
    unordered_map<string, string> oldMap;
    unordered_map<string,string> newMap;

public:
    FileCacheManager(){
        loadSolution();
    };
    virtual void saveSolution();
    virtual string getSolution(string problem);
    virtual void addSolution(string problem, string solution);
    virtual void loadSolution();
    virtual ~FileCacheManager() {
        saveSolution();
    };

};


#endif //MILESTONE2_FILECACHMANAGER_H

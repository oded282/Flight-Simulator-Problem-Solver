
#ifndef MILESTONE2_CACHMANAGER_H
#define MILESTONE2_CACHMANAGER_H

#include <string>

using namespace std;

class CacheManager {

public:
    virtual void saveSolution(string problem, string solution) = 0;
    virtual string getSolution(string problem) = 0;
    virtual void addSolution(string problem, string solution )=0;
    virtual void loadSolution()=0;


};


#endif //MILESTONE2_CACHMANAGER_H

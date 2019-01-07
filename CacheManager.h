
#ifndef MILESTONE2_CACHMANAGER_H
#define MILESTONE2_CACHMANAGER_H

#include <string>

using namespace std;
template <class s, class p>

class CacheManager {

public:

    virtual void saveSolution() = 0;

    virtual s getSolution(p problem) = 0;

    virtual void addSolution(p problem, s solution) = 0;

    virtual void loadSolution() = 0;


};


#endif //MILESTONE2_CACHMANAGER_H

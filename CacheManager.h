
#ifndef MILESTONE2_CACHMANAGER_H
#define MILESTONE2_CACHMANAGER_H


class CacheManager {

public:
    void saveSolution(Problem, Solution);
    bool isSolution(Problem);
    Solution getSolution(Problem);


};


#endif //MILESTONE2_CACHMANAGER_H

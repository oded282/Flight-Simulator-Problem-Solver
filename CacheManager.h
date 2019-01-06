
#ifndef MILESTONE2_CACHMANAGER_H
#define MILESTONE2_CACHMANAGER_H


class CacheManager {

public:
    virtual void saveSolution(int, int) = 0;
    virtual bool isSolution(int) = 0;
    virtual int getSolution(int) = 0;


};


#endif //MILESTONE2_CACHMANAGER_H

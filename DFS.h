#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H


#include "AbstractSearcher.h"
#include <unordered_map>

enum Color {BLACK, GRAY, WHITE};
template<class T>
class DFS : public AbstractSearcher<T> {

    std::unordered_map<State<T>, Color> mapColor;
    std::unordered_map<State<T>, unsigned int>mapTimeD;
    std::unordered_map<State<T>, unsigned int>mapTimeF;



    void initializ (std::vector<State<T>> vector);

public:
    virtual std::vector<State<T>> search (Searchable<T> s);


};


#endif //MILESTONE2_DFS_H

#include <iostream>
#include <unistd.h>
#include <fstream>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringRevers.h"
#include "State.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "AStar.h"
#include "DepthFirstSearch .h"
#include "MyParallelServer.h"
#include "MatrixClientHandler.h"
#include "SearchProblemSolver.h"


bool shouldRun = true;
int countCurrentTreaths = 0;
pthread_mutex_t mutex;

int main(){


    std::vector<int> v = {10,20,30,40,50,60,70,80,90,100};
    std::vector<std::vector<std::vector<double >*>*> allMatrixs;
    int k = 0;
    for (int size : v) {
            auto col = new std::vector<std::vector<double>*>;
        for (int i = 0; i< size ; i++){

            auto raw = new std::vector<double> ;
            for (int j = 0; j < size ; j++) {
                double d =(double)(rand() % 10) + 1;
                raw->push_back(d);
            }
            col->push_back(raw);
        }
        allMatrixs.push_back(col);
        k++;
    }


    allMatrixs.size();





        int p = 0;

        for (std::vector<std::vector<double>*>* m : allMatrixs) {
            int size = v[p];
            std::pair<int,int> i(0,0);
            std::pair<int,int> g(size-1,size-1);
            p++;

            auto algo1 = new BestFirstSearch<std::pair<int, int>>();
            auto matrix = new SearchableMatrix(i, g,m , size,size);
            algo1->search(matrix);


            auto algo2 = new DepthFirstSearch<std::pair<int, int>>();
            auto matrix2 = new SearchableMatrix(i, g,m , size,size);
            algo2->search(matrix2);

            auto algo3 = new BreadthFirstSearch<std::pair<int, int>>();
            auto matrix3 = new SearchableMatrix(i, g,m , size,size);
            algo3->search(matrix3);

            auto algo4 = new AStar<std::pair<int, int>>();
            auto matrix4 = new SearchableMatrix(i, g,m , size,size);
            algo4->search(matrix4);

        }


    ofstream outfile;
    outfile.open("Matrix.txt", ios::app);

    for (auto allM : allMatrixs) {
        for (auto it : *allM) {
            for (auto d : *it) {
                outfile << d << " , ";
            }
            outfile << '\n';
        }
        outfile << '\n' << endl;
        outfile << "$" << endl;
    }
    outfile.close();
    return 1;
}


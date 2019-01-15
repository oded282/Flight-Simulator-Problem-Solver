#include <fstream>
#include <iostream>
#include "FileCacheManager.h"

extern pthread_mutex_t mutex;

void FileCacheManager::saveSolution() {

    ofstream outfile;
    outfile.open("Data.txt", ios::app);
    unordered_map<string, string>::iterator it;
    for (it = newMap.begin(); it != newMap.end(); it++) {
        outfile << (*it).first << endl;
        outfile<< "$" <<endl;
        outfile << (*it).second << endl;
        outfile<< "$" <<endl;
    }
    outfile.close();

}


string FileCacheManager::getSolution(string problem) {
    /*// lock thread.
    pthread_mutex_lock(&mutex);*/
    string result;
    if (newMap.find(problem) != newMap.end()) {
        result = newMap[problem];
    } else if (oldMap.find(problem) != oldMap.end()) {
        result = oldMap[problem];
    } else {
        result = "";
    }
/*    // unlock thread.
    pthread_mutex_unlock(&mutex);*/
    return result;

}

void FileCacheManager::addSolution(string problem, string solution) {
    // lock thread.
    pthread_mutex_lock(&mutex);
    newMap[problem] = solution;
    // unlock thread.
    pthread_mutex_unlock(&mutex);
}

void FileCacheManager::loadSolution() {

    string tempLine;
    string problem;
    string result;
    ifstream myReadFile;
    myReadFile.open("Data.txt");
    if (myReadFile.is_open()) {
        while (getline(myReadFile, tempLine)) {
            while (tempLine != "$") {
                problem += tempLine + '\n';
                getline(myReadFile, tempLine);
            }
            problem.erase(problem.end() -1);
            getline(myReadFile, tempLine);
            while (tempLine != "$"){
                result += tempLine;
                getline(myReadFile, tempLine);
            }
            oldMap[problem] = result;
            problem.clear();
            result.clear();
        }
        myReadFile.close();
    }
}



#include <fstream>
#include <iostream>
#include "FileCacheManager.h"

void FileCacheManager::saveSolution() {
    ofstream outfile;
    outfile.open("Data.txt", ios::app);
    unordered_map<string, string>::iterator it;
    for (it = newMap.begin(); it != newMap.end(); it++) {
        outfile << (*it).first << endl;
        outfile << (*it).second << endl;
    }
    outfile.close();
}


string FileCacheManager::getSolution(string problem) {
    if (newMap.find(problem) != newMap.end()) {
        return newMap[problem];
    } else if (oldMap.find(problem) != oldMap.end()) {
        return oldMap[problem];
    } else {
        return "";
    }
}

void FileCacheManager::addSolution(string problem, string solution) {
    newMap[problem] = solution;
}

void FileCacheManager::loadSolution() {
    string tempLine;
    string firstLine;
    ifstream myReadFile;
    myReadFile.open("Data.txt");
    if (myReadFile.is_open()) {
        while (getline(myReadFile, tempLine)) {
            firstLine = tempLine;
            getline(myReadFile, tempLine);
            oldMap[firstLine] = tempLine;
        }
        myReadFile.close();
    } else {
        cout << "Failed to open file." << endl;
    }

}

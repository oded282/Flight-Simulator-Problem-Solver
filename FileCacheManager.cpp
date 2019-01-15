#include <fstream>
#include <iostream>
#include "FileCacheManager.h"

extern pthread_mutex_t mutex;

/*
 * This func save all the data set to the new map and write to file
 * called Data.txt
 */
void FileCacheManager::saveSolution() {

    ofstream outfile;
    outfile.open("Data.txt", ios::app);
    unordered_map<string, string>::iterator it;
    for (it = newMap.begin(); it != newMap.end(); it++) {
        outfile << (*it).first << endl;
        outfile << "$" << endl;
        outfile << (*it).second << endl;
        outfile << "$" << endl;
    }
    outfile.close();

}

/*
 * This func check if there is any solution in the memory.
 * we run on the mao searching for our problrem.
 */
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

/*
 * This func we add new solution for some problem to the new map.
 */
void FileCacheManager::addSolution(string problem, string solution) {
    // lock thread.
    pthread_mutex_lock(&mutex);
    newMap[problem] = solution;
    // unlock thread.
    pthread_mutex_unlock(&mutex);
}


/*
 * This func we will go to the Data.txt if exist,
 * and load all our problems from the file.
 * we will save them in "old map" so we won't write some
 * old info when we shut the prog and save the new solution
 * added this time.
 */
void FileCacheManager::loadSolution() {

    string tempLine;
    string problem;
    string result;
    ifstream myReadFile;
    myReadFile.open("Data.txt");
    if (myReadFile.is_open()) { // open the file
        while (getline(myReadFile, tempLine)) { //read line by line.
            while (tempLine != "$") {
                problem += tempLine + '\n';
                getline(myReadFile, tempLine);
            }
            problem.erase(problem.end() - 1);
            getline(myReadFile, tempLine);
            while (tempLine != "$") {
                result += tempLine;
                getline(myReadFile, tempLine);
            }
            oldMap[problem] = result; // insert data to map.
            problem.clear();
            result.clear();
        }
        myReadFile.close();
    }
}

#include <algorithm>
#include <iostream>
#include "StringRevers.h"

string StringRevers::solve(string s) {
    string newstring , temp;
    string::iterator it;
    for (it = s.begin() ; it != s.end(); it++){
        if (*it != '\r'){
            temp += *it;
        }else{
            reverse(temp.begin() , temp.end());
            newstring += temp + "\r\n";
            temp.erase();
            it++;
        }
    }

    return newstring;
}


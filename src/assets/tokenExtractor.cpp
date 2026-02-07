#include "../headers/tokenExtractor.h"
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

inline void trim(std::string& s) {
    // left trim
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        [](unsigned char ch) { return !std::isspace(ch); }));

    // right trim
    s.erase(std::find_if(s.rbegin(), s.rend(),
        [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

vector<string> tokenExtractor(string parent){
    vector<string> result;  //should contain 'keyword', 'degree', 'func', 'var' and 'lim' (if applicable)
    bool isInner = false;  //accounts whether we're inside a '[]' already, to prevent inner expression splitting.
    bool prevState = false;
    int openCount = 0;
    string currentToken = "";
    for(int i = 0; i < parent.length(); i++){
                                                // logic: if openCount flips, change expression
        if(parent[i]=='[') openCount++;
        else if(parent[i]==']') openCount--;
        isInner = (bool) openCount;
        if(prevState != isInner){
            
            if(currentToken!="") {trim(currentToken); result.push_back(currentToken);}
            currentToken = "";
            prevState = isInner;
        }
        else currentToken += parent[i]; 
    }
    if(currentToken != "") {trim(currentToken); result.push_back(currentToken);}
    return result;
}
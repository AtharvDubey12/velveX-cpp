#include "../headers/tokenExtractor.h"

using namespace std;

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
            if(currentToken!="") result.push_back(currentToken);
            currentToken = "";
            prevState = isInner;
        }
        else currentToken += parent[i]; 
    }
    if(currentToken != "") result.push_back(currentToken);
    return result;
}
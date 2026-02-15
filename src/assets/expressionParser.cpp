#include "../headers/expressionParser.h"
#include "../headers/tokenProcessor.h"
#include "../headers/tokenExtractor.h"
#include <unordered_map>

using namespace std;

string expressionParser(string expression){
    // Integ[2][x][x][lim] + x + Diff[2][x][x]
    vector<string> listOfExp;
    string currentExp = "";
    int openCount = 0;
    bool isInner = false;
    

    for(int i = 0; i < expression.length(); i++){
        if(expression[i]=='[') openCount++;
        else if(expression[i]==']') openCount--;
        isInner = (bool) openCount;
        if(!isInner && expression[i]==' ' && currentExp != ""){
            listOfExp.push_back(currentExp);
            currentExp="";
        }
        else currentExp += expression[i];
    }
    if(currentExp!="") listOfExp.push_back(currentExp);
    currentExp="";   // will be the final processed output.
    for(int i=0; i<listOfExp.size(); i++){
        vector<string> operation = tokenExtractor(listOfExp[i]);
        currentExp += tokenProcessor(operation);
    }
    return currentExp;
}
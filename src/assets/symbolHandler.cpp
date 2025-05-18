#include "../headers/symbolHandler.h"
#include "../headers/expressionParser.h"
using namespace std;

vector<vector<string>> limitExtractor(string arrowLims){

    vector<vector<string>> limitVector;
    string current = "";
    vector<string> currentSet;
    string limit = arrowLims;
    int openCount = 0;
    for(int i=0; i<limit.length() ; i++){
        if(!openCount && limit[i]==','){
            if(current!=""){
                currentSet.push_back(current);
                current="";
            }
            limitVector.push_back(currentSet);
            currentSet.clear();
            i++;
        }
        if(limit[i]=='[' || limit[i]=='(') openCount++;
        else if(limit[i]==']' || limit[i]==')') openCount--;

        if(!openCount && i<limit.length()-1 && limit[i]=='-' && limit[i+1]=='>'){
            if(current!="") currentSet.push_back(current);
            i++;
            current="";
        }
        else current+= limit[i];
    }
    if(current!="") currentSet.push_back(current);
    if(currentSet.size()==2) limitVector.push_back(currentSet);
    return limitVector;
}

string limitHandler(vector<string>& tokenList){
    string finalExpression = "";
    vector<vector<string>> sanitizedLimits;
    if(tokenList.size()==1) return "\\lim \\, ";
    else{
        sanitizedLimits = limitExtractor(tokenList[1]);
        finalExpression += "\\lim_{" + expressionParser(sanitizedLimits[0][0]) + " \\to "+ expressionParser(sanitizedLimits[0][1])+"} \\, ";
    }
    return finalExpression;
}

string sumHandler(vector<string>& tokenList){
    string finalExpression = "";
    vector<vector<string>> sanitizedLimits;
    if(tokenList.size()==1) return "\\sum \\, ";
    else{
        sanitizedLimits = limitExtractor(tokenList[1]);
        finalExpression += "\\sum_{" + expressionParser(sanitizedLimits[0][0]) + "}^{"+ expressionParser(sanitizedLimits[0][1])+"} \\, ";
    }
    return finalExpression;
}

string combinationHandler(vector<string>& tokenList, int type){
    string corp = (type) ? "P": "C";
    string finalExpression = "{}^{";
    if(tokenList.size()==1) return tokenList[0];
    else finalExpression+= expressionParser(tokenList[1]) + "}"+corp+"_{" + expressionParser(tokenList[2]) +"} ";
    return finalExpression;
}

string vectorHandler(vector<string>& tokenList){
    string finalExpression = "\\vec{";
    finalExpression+= expressionParser(tokenList[1]) +"} ";
    return finalExpression;
}

string overlineHandler(vector<string>& tokenList){
    string finalExpression = "\\overline{";
    finalExpression+= expressionParser(tokenList[1]) +"} ";
    return finalExpression;
}

string boldmathHandler(vector<string>& tokenList){
    string finalExpression = "\\mathbf{";
    finalExpression+= expressionParser(tokenList[1]) +"} ";
    return finalExpression;
}

string textHandler(vector<string>& tokenList){
    string finalExpression = "\\text{";
    finalExpression+= tokenList[1] +"} ";
    return finalExpression;
}

string scriptHandler(vector<string>& tokenList, int type){
    string finalExpression = (type)? "_{": "^{";
    finalExpression+= expressionParser(tokenList[1]) +"} ";
    return finalExpression;
}

string prodHandler(vector<string>& tokenList){
    string finalExpression = "";
    vector<vector<string>> sanitizedLimits;
    if(tokenList.size()==1) return "\\prod \\, ";
    else{
        sanitizedLimits = limitExtractor(tokenList[1]);
        finalExpression += "\\prod_{" + expressionParser(sanitizedLimits[0][0]) + "}^{"+ expressionParser(sanitizedLimits[0][1])+"} \\, ";
    }
    return finalExpression;
}

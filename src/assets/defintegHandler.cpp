#include "../headers/integHandler.h"
#include "../headers/defintegHandler.h"
#include "../headers/expressionParser.h"
using namespace std;

string defintegHandler(vector<string>& tokenList){
    int degree = -1;
    string innerFunc = "";
    try{
        innerFunc = expressionParser(tokenList[2]);
    }
    catch(const exception&){
        innerFunc = tokenList[2];
        cout<<"encountered an error for innerFunc in defintegHandler"<< endl;
    }
    
    try{
        degree = stoi(tokenList[1]);
    }
    catch(const exception&){
        degree = 1;
        cout<<"Error in defintegHandler. Incorrect degree entered, it must be a number. Degree set to 1 as a fallback."<< endl;
    }

    vector<string> varVector;
    string vars = tokenList[3];
    string currExp ="";
    int openCount = 0;

    for(auto& it : vars){
        if(it=='[' || it=='(') openCount++;
        else if (it==']' || it==')') openCount--;
        if(it== ',' && !openCount){
            varVector.push_back(expressionParser(currExp));
            currExp="";
        }
        else currExp+= it;
    }
    if(currExp != "") varVector.push_back(expressionParser(currExp));
    
    vector<vector<string>> limitVector;
    string current = "";
    vector<string> currentSet;
    string limit = tokenList[tokenList.size()-1];
    openCount = 0;
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
    }//0->1,1->2
    if(current!="") currentSet.push_back(current);
    if(currentSet.size()==2) limitVector.push_back(currentSet);

    string finalExpression = "";
    for(int i = 0; i<degree; i++){
        finalExpression+= "\\int_{" + expressionParser(limitVector[i][0]) + "}^{" + expressionParser(limitVector[i][1]) + "} "; 
    }
    finalExpression+= innerFunc;
    for(auto& it : varVector){
        finalExpression+= "\\, d" + it + " ";
        degree--;
    }
    while(degree--) finalExpression+= "\\, d" + varVector[varVector.size()-1] + " ";



    return finalExpression;
};
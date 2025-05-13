#include "../headers/integHandler.h"
#include "../headers/defintegHandler.h"
#include "../headers/expressionParser.h"
using namespace std;

string integHandler(vector<string>& tokenList){
    if (tokenList.size()>4) return defintegHandler(tokenList);
    int degree = -1;
    string innerFunc = "";
    
    try{
        innerFunc = expressionParser(tokenList[2]);
    }
    catch(const exception&){
        innerFunc = tokenList[2];
        cout<<"encountered an error for innerFunc in integHandler"<< endl;
    }

    try{
        degree = stoi(tokenList[1]);
    }
    catch(const exception&){
        degree = 1;
        cout<<"Error in integHandler. Incorrect degree entered, it must be a number. Degree set to 1 as a fallback."<< endl;
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

    string finalExpression = "\\";
    for(int i = 0; i < degree; i++) finalExpression+= 'i';
    finalExpression+= "nt " + innerFunc; 
    for(auto& it : varVector){
        finalExpression+= "\\, d" + it + " ";
        degree--;
    }
    while(degree--) finalExpression+= "\\, d" + varVector[varVector.size()-1] + " ";
    return finalExpression;

}
#include "../headers/integHandler.h"
#include "../headers/defintegHandler.h"
#include "../headers/expressionParser.h"
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

bool isDefinite(string expression){
    for(int i=0; i<expression.length()-1; i++){
        if(expression[i]=='-' && expression[i+1]=='>') return true;
    }
    return false;
}
//Integ[2][x][x][0->1,0->1]
string integHandler(vector<string>& tokenList){
    if (isDefinite(tokenList[tokenList.size()-1])) return defintegHandler(tokenList);
    int degree = -1;
    string innerFunc = "";
    
    try{
        innerFunc = expressionParser(tokenList[2]);
        if (innerFunc.size()) trim(innerFunc);
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
            string expr = expressionParser(currExp);
            if (expr.size()) trim(expr);
            varVector.push_back(expr);
            currExp="";
        }
        else currExp+= it;
    }
    if(currExp != "") {
        string expr = expressionParser(currExp);
        if (expr.size()) trim(expr);
        varVector.push_back(expr);
    }

    string finalExpression = "\\";
    for(int i = 0; i < degree; i++) finalExpression+= 'i';
    finalExpression+= "nt " + innerFunc; 
    for(auto& it : varVector){
        finalExpression+= " \\, d" + it + " ";
        degree--;
    }
    while(degree--) finalExpression+= " \\, d" + varVector[varVector.size()-1] + " ";
    return finalExpression;

}
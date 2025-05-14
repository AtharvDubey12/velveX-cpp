#include "../headers/pdiffHandler.h"
#include "../headers/expressionParser.h"
#include <unordered_map>
#include <unordered_set>
using namespace std;
//Diff[1][x][x]
string pdiffHandler(vector<string>& tokenList){
    int degree = 1;
    string innerFunc = "";
    if(tokenList.size()==3) innerFunc = expressionParser(tokenList[1]);
    else{
        try{
        degree = stoi(tokenList[1]);
        }
        catch (const exception&){
            cout<<"error encountered in diffHandler, reverting degree to 1.";
        }
        innerFunc = expressionParser(tokenList[2]);
    }
    string varStr = tokenList[tokenList.size()-1];
    vector<string> varList;
    int openCount = 0;
    string currentExp = "";
    for(int i = 0; i<varStr.length(); i++){
        if(varStr[i]=='(' || varStr[i]=='[') openCount++;
        else if (varStr[i]==')' || varStr[i]==']') openCount--;
        if(!openCount && varStr[i]==','){
            try{
                varList.push_back(expressionParser(currentExp));
            }
            catch (const exception&){
                varList.push_back(currentExp);
                cout<<"error encountered while processing dependency variables in diffHandler\n";
            }
            currentExp="";
        }
        else currentExp += varStr[i];
    }
    if(currentExp!=""){
        try{
            varList.push_back(expressionParser(currentExp));
        }
        catch (const exception&){
                varList.push_back(currentExp);
                cout<<"error encountered while processing dependency variables in diffHandler\n";
        }
    }

    string num_sanitized = "";
    if(degree>1) num_sanitized ="\\frac{\\partial^" + to_string(degree) +" "+ innerFunc + "}";
    else num_sanitized ="\\frac{\\partial " + innerFunc + "}";
    string den_sanitized = "{";

    for(int i = 0; i<varList.size(); i++){
        if(i==varList.size()-1 && degree>1)
            den_sanitized += " \\partial " + varList[i]+"^"+ to_string(degree);
        else if (!i)
            den_sanitized += "\\partial " + varList[i];
        else
            den_sanitized += " \\partial " + varList[i];
        degree--;
    }
    den_sanitized+="}";
    string finalExpression = num_sanitized + den_sanitized;
    return finalExpression;
}
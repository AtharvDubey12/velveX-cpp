#include "../headers/sqrtHandler.h"
#include "../headers/expressionParser.h"
#include "sqrtHandler.h"
using namespace std;

string sqrtHandler(vector<string>& tokenList){
    string degree = "";
    string innerFunc = "";
    string finalExpression = "\\sqrt";
    if(tokenList.size()==3){
        degree = expressionParser(tokenList[1]);
        innerFunc = expressionParser(tokenList[2]);
        finalExpression+= "["+degree+"]";
    }
    else{
        innerFunc = expressionParser(tokenList[1]);
    }
    finalExpression+= "{" + innerFunc + "} ";
    return finalExpression;
}
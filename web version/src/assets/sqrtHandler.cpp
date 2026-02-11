#include "../headers/sqrtHandler.h"
#include "../headers/expressionParser.h"
#include "sqrtHandler.h"
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

string sqrtHandler(vector<string>& tokenList){
    string degree = "";
    string innerFunc = "";
    string finalExpression = "\\sqrt";
    if(tokenList.size()==3){
        degree = expressionParser(tokenList[1]);
        if (degree.size()) trim(degree);
        innerFunc = expressionParser(tokenList[2]);
        if (innerFunc.size()) trim(innerFunc);
        finalExpression+= "["+degree+"]";
    }
    else{
        innerFunc = expressionParser(tokenList[1]);
        if (innerFunc.size()) trim(innerFunc);
    }
    finalExpression+= "{" + innerFunc + "} ";
    return finalExpression;
}
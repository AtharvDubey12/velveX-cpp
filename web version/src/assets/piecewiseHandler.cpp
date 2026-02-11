#include "../headers/piecewiseHandler.h"
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
/*
//[]=>[],[]=>[]
// f(x) = \begin{cases}
// 5, & \text{if } x > 2 \\
// 3, & \text{if } x < 1
// \end{cases}
*/
string piecewiseHandler(vector<string>& tokenList){
    int openCount = 0;
    string stream = tokenList[1];
    bool condition = false;
    string current = "";
    cout << stream << endl;
    string finalExpression = "\\begin{cases} ";
    for(int i = 0; i < stream.length(); i++){
        if(stream[i]=='[' || stream[i]=='(') openCount++;
        else if(stream[i]==']' || stream[i]==')') openCount--;
        if(!openCount && stream[i]==',') continue;
        if(openCount==1 && stream[i]=='[') continue;
        if (openCount == 1 && stream[i] == ',') {
                string expr = expressionParser(current);
                if (expr.size()) trim(expr);
                finalExpression += expr;
                current="";
                continue;
        }
        if(!openCount && stream[i]==']'){
            string expr = expressionParser(current);
            if (expr.size()) trim(expr);
                finalExpression += " & " + expr;
                if (i < stream.size() - 1) finalExpression += " \\\\ ";
                current="";
        }
        else current += stream[i];

    }
    finalExpression+= " \\end{cases}";
    return finalExpression;
}
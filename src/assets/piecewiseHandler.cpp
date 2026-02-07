#include "../headers/piecewiseHandler.h"
#include "../headers/expressionParser.h"
using namespace std;
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
                finalExpression += expressionParser(current) ;
                current="";
                continue;
        }
        if(!openCount && stream[i]==']'){
                finalExpression += " & " + expressionParser(current);
                if (i < stream.size() - 1) finalExpression += " \\\\ ";
                current="";
        }
        else current += stream[i];

    }
    finalExpression+= " \\end{cases}";
    return finalExpression;
}
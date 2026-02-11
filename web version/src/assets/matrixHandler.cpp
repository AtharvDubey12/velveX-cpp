#include "../headers/pdiffHandler.h"
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

string matrixHandler(vector<string>& tokenList, int type){
    vector<vector<string>> rowStream;
    vector<string> currentRow;
    string currentEntry = "";
    string stream = tokenList[1];
    int openCount = 0;
    for(int i = 0; i<stream.length(); i++){
        if(stream[i]=='(' || stream[i]=='[') openCount++;
        else if(stream[i]==')' || stream[i]==']') openCount--;
        if(openCount==1 && stream[i]=='[') continue;
        if(openCount==1 && stream[i]==','){
            string expr = expressionParser(currentEntry);
            if (expr.size()) trim(expr);
            currentRow.push_back(expr);
            currentEntry="";
            continue;
        }
        if(!openCount && stream[i]==']'){
            string expr = expressionParser(currentEntry);
            if (expr.size()) trim(expr);
            currentRow.push_back(expr);
            rowStream.push_back(currentRow);
            currentEntry="";
            currentRow.clear();
            i++;
            continue;
        }
        currentEntry+= stream[i];
    }

    string finalExpression = (type) ? "\\begin{vmatrix}":"\\begin{bmatrix} ";
    for(int i = 0; i<rowStream.size(); i++){
        for(int j = 0; j<rowStream[i].size(); j++){
            if(j<rowStream[i].size()-1) finalExpression += rowStream[i][j] + " & "; 
            else finalExpression += rowStream[i][j];
        }
        if(i<rowStream.size()-1){
            finalExpression+= " \\";
            finalExpression+= "\\ ";
        }
    }
    finalExpression+= (type) ? "\\end{vmatrix}":"\\end{bmatrix} ";
    return finalExpression;

}
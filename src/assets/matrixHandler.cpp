#include "../headers/pdiffHandler.h"
#include "../headers/expressionParser.h"

using namespace std;
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
            currentRow.push_back(expressionParser(currentEntry));
            currentEntry="";
            continue;
        }
        if(!openCount && stream[i]==']'){
            currentRow.push_back(expressionParser(currentEntry));
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
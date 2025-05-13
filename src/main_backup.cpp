#include<iostream>
#include<string>
#include<vector>
#include "./headers/parser.h"

using namespace std;

// vector<string> tokenExtractor(string parent);
// string tokenProcessor(vector<string>& tokenList);
// string expressionParser(string expression);
// string defintegHandler(vector<string>& tokenList);
// string integHandler(vector<string>& tokenList);
// // Syntax:      Integ[2][func][var][lim]

// vector<string> tokenExtractor(string parent){
//     vector<string> result;  //should contain 'keyword', 'degree', 'func', 'var' and 'lim' (if applicable)
//     bool isInner = false;  //accounts whether we're inside a '[]' already, to prevent inner expression splitting.
//     bool prevState = false;
//     int openCount = 0;
//     string currentToken = "";
//     for(int i = 0; i < parent.length(); i++){
//                                                 // logic: if openCount flips, change expression
//         if(parent[i]=='[') openCount++;
//         else if(parent[i]==']') openCount--;
//         isInner = (bool) openCount;
//         if(prevState != isInner){
//             if(currentToken!="") result.push_back(currentToken);
//             currentToken = "";
//             prevState = isInner;
//         }
//         else currentToken += parent[i]; 
//     }
//     if(currentToken != "") result.push_back(currentToken);
//     return result;
// }

// string tokenProcessor(vector<string>& tokenList){
//     string output = "";
//     string keyword = tokenList[0];
//     //Integ[2][x][x][0->1]
//     if(keyword == "Integ") return integHandler(tokenList);
//     else return tokenList[0];

//     return "";
// }

// string expressionParser(string expression){
//     // Integ[2][x][x][lim] + x + Diff[2][x][x]
//     vector<string> listOfExp;
//     string currentExp = "";
//     int openCount = 0;
//     bool isInner = false;

//     for(int i = 0; i < expression.length(); i++){
//         if(expression[i]=='[') openCount++;
//         else if(expression[i]==']') openCount--;
//         isInner = (bool) openCount;
//         if(!isInner && expression[i]==' ' && currentExp != ""){
//             listOfExp.push_back(currentExp);
//             currentExp="";
//         }
//         else currentExp += expression[i];
//     }
//     if(currentExp!="") listOfExp.push_back(currentExp);
//     currentExp="";   // will be the final processed output.
//     for(int i=0; i<listOfExp.size(); i++){
//         vector<string> operation = tokenExtractor(listOfExp[i]);
    
//         currentExp += tokenProcessor(operation);
//     }
//     return currentExp;
// }

// string defintegHandler(vector<string>& tokenList){
//     return "";
// }

// string integHandler(vector<string>& tokenList){
//     if (tokenList.size()>4) return defintegHandler(tokenList);
//     int degree = -1;
//     string innerFunc = "";
    
//     try{
//         innerFunc = expressionParser(tokenList[2]);
//     }
//     catch(const exception&){
//         innerFunc = tokenList[2];
//         cout<<"encountered an error for innerFunc in integHandler"<< endl;
//     }

//     try{
//         degree = stoi(tokenList[1]);
//     }
//     catch(const exception&){
//         degree = 1;
//         cout<<"Error in integHandler. Incorrect degree entered, it must be a number. Degree set to 1 as a fallback."<< endl;
//     }
//     vector<string> varVector;
//     string vars = tokenList[3];
//     string currExp ="";
//     int openCount = 0;

//     for(auto& it : vars){
//         if(it=='[' || it=='(') openCount++;
//         else if (it==']' || it==')') openCount--;
//         if(it== ',' && !openCount){
//             varVector.push_back(expressionParser(currExp));
//             currExp="";
//         }
//         else currExp+= it;
//     }
//     if(currExp != "") varVector.push_back(expressionParser(currExp));

//     string finalExpression = "\\";
//     for(int i = 0; i < degree; i++) finalExpression+= 'i';
//     finalExpression+= "nt " + innerFunc; 
//     for(auto& it : varVector){
//         finalExpression+= "\\, d" + it + " ";
//         degree--;
//     }
//     while(degree--) finalExpression+= "\\, d" + varVector[varVector.size()-1];
//     return finalExpression;

// }


int main(){
    vector<string> test = {"Integ", "2", "x", "x"};
    string x = expressionParser("Integ[2][Integ[1][x][x] + p][x,x] + yx");
    cout<<x;
    return 0;
}
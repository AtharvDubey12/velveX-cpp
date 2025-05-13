#include<iostream>
#include<string>
#include<vector>
#include "./headers/parser.h"

using namespace std;

int main(){
    vector<string> test = {"Integ", "2", "y", "y"};
    string x = expressionParser("( Integ[1][x][x] )");
    
    string output = "";  //output with sanitized parenthesis.
    for (int i=0; i<x.length(); i++){
        if(x[i]=='(') output+= "\\left(";
        else if (x[i]==')') output+= "\\right)";
        else output+= x[i];
    }
    cout<<output;
    return 0;
}
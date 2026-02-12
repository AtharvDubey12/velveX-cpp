#include<iostream>
#include<string>
#include<vector>
#include "./headers/parser.h"
#include "./headers/globalVars.h"

std::unordered_map<std::string, std::string> custom_defines;
using namespace std;

int main(int argc, char* argv[]){
   string x = expressionParser(argv[1]);
    string output = "";  // output with sanitized parenthesis.
    for (int i=0; i<x.length(); i++){
        if(x[i]=='(') output+= "\\left(";
        else if (x[i]==')') output+= "\\right)";
        else output+= x[i];
    }
    cout<<output;
    return 0;
}
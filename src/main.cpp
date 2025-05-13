#include<iostream>
#include<string>
#include<vector>
#include "./headers/parser.h"

using namespace std;

int main(){
    vector<string> test = {"Integ", "2", "y", "y"};
    string x = expressionParser("Integ[2][Integ[1][x][x] + p][y] + yx");
    cout<<x;
    return 0;
}
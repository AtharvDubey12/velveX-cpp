#include "../headers/integHandler.h"
#include "../headers/tokenProcessor.h"
#include "../headers/fracHandler.h"
#include "../headers/parser.h"
using namespace std; 

string tokenProcessor(vector<string>& tokenList){
    string output = "";
    string keyword = tokenList[0];
    //Integ[2][x][x][0->1]
    if(keyword == "Integ") return integHandler(tokenList);
    else if(keyword == "Frac") return fracHandler(tokenList);
    else if(keyword == "Diff") return diffHandler(tokenList);
    else return tokenList[0];

    return "";
}
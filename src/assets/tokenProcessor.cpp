#include "../headers/integHandler.h"
#include "../headers/tokenProcessor.h"
#include "../headers/fracHandler.h"
#include "../headers/sqrtHandler.h"
#include "../headers/parser.h"
using namespace std; 

string tokenProcessor(vector<string>& tokenList){
    string output = "";
    string keyword = tokenList[0];
    if(keyword == "Integ") return integHandler(tokenList);
    else if(keyword == "Frac") return fracHandler(tokenList);
    else if(keyword == "Diff") return diffHandler(tokenList);
    else if(keyword == "Pdiff") return pdiffHandler(tokenList);
    else if(keyword == "Sqrt") return sqrtHandler(tokenList);
    else if(keyword == "Lim") return limitHandler(tokenList);
    else if(keyword == "Sum") return sumHandler(tokenList);
    else if(keyword == "C") return combinationHandler(tokenList,0);
    else if(keyword == "P") return combinationHandler(tokenList,1);
    else return tokenList[0];

    return "";
}
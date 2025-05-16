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
    else if(keyword == "Vec") return vectorHandler(tokenList);
    else if(keyword == "Line") return overlineHandler(tokenList);
    else if(keyword == "Mx") return matrixHandler(tokenList, 0);
    else if(keyword == "Dt") return matrixHandler(tokenList, 1);
    else if(keyword == "Bold") return boldmathHandler(tokenList);
    else if(keyword == "<=") return " \\leq ";
    else if(keyword == ">=") return " \\geq ";
    else if(keyword == "!=") return " \\neq ";
    else if(keyword == "All") return " \\forall ";
    else if(keyword == "Del") return " \\delta ";
    else if(keyword == "Delta") return " \\Delta ";
    else if(keyword == "Nabla") return " \\nabla ";
    else if(keyword == "Om") return " \\omega ";
    else if(keyword == "Omega") return " \\Omega ";
    else if(keyword == "Inf") return " \\infty ";
    else if(keyword == "__") return " \\,\\,\\, ";
    else if(keyword == "Theta") return " \\theta ";
    else if(keyword == "Vtheta") return " \\vartheta ";
    else if(keyword == "Epsilon") return " \\epsilon ";
    else if(keyword == "Vepsilon") return " \\varepsilon ";
    else return tokenList[0];

    return "";
}
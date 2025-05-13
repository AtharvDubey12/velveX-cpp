#include "../headers/tokenProcessor.h"
#include "../headers/integHandler.h"
using namespace std; 

string tokenProcessor(vector<string>& tokenList){
    string output = "";
    string keyword = tokenList[0];
    //Integ[2][x][x][0->1]
    if(keyword == "Integ") return integHandler(tokenList);
    else return tokenList[0];

    return "";
}
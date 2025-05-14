#include "../headers/fracHandler.h"
#include "../headers/expressionParser.h"
using namespace std;

string fracHandler(vector<string>& tokenList){
    string result = "\\frac{";
    string numerator = "";
    string denominator = "";
    try{
        numerator = expressionParser(tokenList[1]);
    }
    catch(const exception&){
        numerator = tokenList[1];
        cout<<"an error was encountered in fracHandler, numerator will not be processed.";
    }
    try{
        denominator = expressionParser(tokenList[2]);
    }
    catch(const exception&){
        denominator = tokenList[2];
        cout<<"an error was encountered in fracHandler, denominator will not be processed.";
    }
    result += numerator + "}{" + denominator + "}";
    return result;
}
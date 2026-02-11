#include "../headers/fracHandler.h"
#include "../headers/expressionParser.h"
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

inline void trim(std::string& s) {
    // left trim
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        [](unsigned char ch) { return !std::isspace(ch); }));

    // right trim
    s.erase(std::find_if(s.rbegin(), s.rend(),
        [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

string fracHandler(vector<string>& tokenList){
    string result = "\\frac{";
    string numerator = "";
    string denominator = "";
    try{
        numerator = expressionParser(tokenList[1]);
        if (numerator.size()) trim(numerator);
    }
    catch(const exception&){
        numerator = tokenList[1];
        cout<<"an error was encountered in fracHandler, numerator will not be processed.";
    }
    try{
        denominator = expressionParser(tokenList[2]);
        if (denominator.size()) trim(denominator);
    }
    catch(const exception&){
        denominator = tokenList[2];
        cout<<"an error was encountered in fracHandler, denominator will not be processed.";
    }
    result += numerator + "}{" + denominator + "}";
    return result;
}
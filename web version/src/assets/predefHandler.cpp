#include "../headers/predefHandler.h"
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

string taylorHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(x) = \\sum_{n=0}^{\\infty}\\frac{f^{(n)}(a)}{n!}\\,(x-a)^n ";
    string innerFunc = expressionParser(tokenList[1]);
    if (innerFunc.size()) trim(innerFunc);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string a = expressionParser(tokenList[3]);
    if (a.size()) trim(a);
    string exp = "f(" + innerFunc + ") = \\sum_{n=0}^{" + term + "} \\frac{f^{(n)}("+ a +")}{n!} \\,("+innerFunc+"-"+a+")^n ";
    return exp;
}
string maclaurinHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(x) = \\sum_{n=0}^{\\infty}\\frac{f^{(n)}(0)}{n!}\\,x^n ";
    string innerFunc = expressionParser(tokenList[1]);
    if (innerFunc.size()) trim(innerFunc);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string exp = "f(" + innerFunc + ") = \\sum_{n=0}^{" + term + "} \\frac{f^{(n)}(0)}{n!} \\,("+innerFunc+")^n ";
    return exp;
}
string fourierHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(x) = \\frac{a_0}{2} + \\sum_{n=1}^\\infty ( a_n \\cos(nx) + b_n \\sin(nx)) ";
    string innerFunc = expressionParser(tokenList[1]);
    if (innerFunc.size()) trim(innerFunc);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string a = expressionParser(tokenList[3]);
    if (a.size()) trim(a);
    string b = expressionParser(tokenList[4]);
    if (b.size()) trim(b);
    string exp = "f("+innerFunc+") = \\frac{"+a+"_0}{2} + \\sum_{n=1}^{"+term+"} ( "+a+"_n \\cos(n"+innerFunc+") + "+b+"_n \\sin(n"+innerFunc+")) ";
    return exp;
}
string dirichletHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "\\zeta(s) = \\sum_{n=1}^{\\infty} \\frac{1}{n^s}, \\qquad \\Re(s) > 1 ";
    string innerFunc = expressionParser(tokenList[1]);
    if (innerFunc.size()) trim(innerFunc);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string exp = "\\zeta ("+innerFunc+") = \\sum_{n=1}^{"+term+"} \\frac{1}{n^{"+innerFunc+"}} ";
    return exp;
}
string legendreHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(x) = \\sum_{n=0}^{\\infty} a_n P_n(x) ";
    string innerFunc = expressionParser(tokenList[1]);
    if (innerFunc.size()) trim(innerFunc);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string exp = "f("+innerFunc+") = \\sum_{n=0}^{"+term+"} a_n P_n("+innerFunc+") ";
    return exp;
}
string laurentHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(z) = \\sum_{n=-\\infty}^{\\infty} a_n (z - z_0)^n ";
    string innerFunc = expressionParser(tokenList[1]);
    if (innerFunc.size()) trim(innerFunc);
    string exp = "f("+innerFunc+") = \\sum_{n=-\\infty}^{\\infty} a_n ("+innerFunc+" - "+innerFunc+"_0)^n ";
    return exp;
}
string binomHandler(vector<string>& tokenList){
    string a = expressionParser(tokenList[1]);
    if (a.size()) trim(a);
    string b = expressionParser(tokenList[2]);
    if (b.size()) trim(b);
    string r = expressionParser(tokenList[3]);
    if (r.size()) trim(r);
    string exp = "("+a+"+"+b+")^{"+r+"} = \\sum_{n=0}^{\\infty} \\binom{"+r+"}{n} "+a+"^{\\,"+r+"-n} "+b+"^n ";
    return exp;
}
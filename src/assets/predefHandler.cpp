#include "../headers/predefHandler.h"
#include "../headers/expressionParser.h"
using namespace std;

string taylorHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(x) = \\sum_{n=0}^{\\infty}\\frac{f^{(n)}(a)}{n!}\\,(x-a)^n ";
    string innerFunc = expressionParser(tokenList[1]);
    string term = expressionParser(tokenList[2]);
    string a = expressionParser(tokenList[3]);
    string exp = "f(" + innerFunc + ") = \\sum_{n=0}^{" + term + "} \\frac{f^{(n)}("+ a +")}{n!} \\,("+innerFunc+"-"+a+")^n ";
    return exp;
}
string maclaurinHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(x) = \\sum_{n=0}^{\\infty}\\frac{f^{(n)}(0)}{n!}\\,x^n ";
    string innerFunc = expressionParser(tokenList[1]);
    string term = expressionParser(tokenList[2]);
    string exp = "f(" + innerFunc + ") = \\sum_{n=0}^{" + term + "} \\frac{f^{(n)}(0)}{n!} \\,("+innerFunc+")^n ";
    return exp;
}
string fourierHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(x) = \\frac{a_0}{2} + \\sum_{n=1}^\\infty ( a_n \\cos(nx) + b_n \\sin(nx)) ";
    string innerFunc = expressionParser(tokenList[1]);
    string term = expressionParser(tokenList[2]);
    string a = expressionParser(tokenList[3]);
    string b = expressionParser(tokenList[4]);
    string exp = "f("+innerFunc+") = \\frac{"+a+"_0}{2} + \\sum_{n=1}^{"+term+"} ( "+a+"_n \\cos(n"+innerFunc+") + "+b+"_n \\sin(n"+innerFunc+")) ";
    return exp;
}
string dirichletHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "\\zeta(s) = \\sum_{n=1}^{\\infty} \\frac{1}{n^s}, \\qquad \\Re(s) > 1 ";
    string innerFunc = expressionParser(tokenList[1]);
    string term = expressionParser(tokenList[2]);
    string exp = "\\zeta ("+innerFunc+") = \\sum_{n=1}^{"+term+"} \\frac{1}{n^{"+innerFunc+"}} ";
    return exp;
}
string legendreHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(x) = \\sum_{n=0}^{\\infty} a_n P_n(x) ";
    string innerFunc = expressionParser(tokenList[1]);
    string term = expressionParser(tokenList[2]);
    string exp = "f("+innerFunc+") = \\sum_{n=0}^{"+term+"} a_n P_n("+innerFunc+") ";
    return exp;
}
string laurentHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "f(z) = \\sum_{n=-\\infty}^{\\infty} a_n (z - z_0)^n ";
    string innerFunc = expressionParser(tokenList[1]);
    string exp = "f("+innerFunc+") = \\sum_{n=-\\infty}^{\\infty} a_n ("+innerFunc+" - "+innerFunc+"_0)^n ";
    return exp;
}
string binomHandler(vector<string>& tokenList){
    string a = expressionParser(tokenList[1]);
    string b = expressionParser(tokenList[2]);
    string r = expressionParser(tokenList[3]);
    string exp = "("+a+"+"+b+")^{"+r+"} = \\sum_{n=0}^{\\infty} \\binom{"+r+"}{n} "+a+"^{\\,"+r+"-n} "+b+"^n ";
    return exp;
}
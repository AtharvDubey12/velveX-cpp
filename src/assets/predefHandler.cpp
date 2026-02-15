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



string geometricHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "\\sum_{n=0}^{\\infty} ar^n = \\frac{a}{1-r} ";
    string a = expressionParser(tokenList[1]);
    if (a.size()) trim(a);
    string r = expressionParser(tokenList[2]);
    if (r.size()) trim(r);
    string term = expressionParser(tokenList[3]);
    if (term.size()) trim(term);
    string exp = "\\sum_{n=0}^{"+term+"} "+a+""+r+"^n ";
    return exp;
}

string expSeriesHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "e^x = \\sum_{n=0}^{\\infty} \\frac{x^n}{n!} ";
    string x = expressionParser(tokenList[1]);
    if (x.size()) trim(x);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string exp = "e^{"+x+"} = \\sum_{n=0}^{"+term+"} \\frac{"+x+"^n}{n!} ";
    return exp;
}

string sinSeriesHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "\\sin x = \\sum_{n=0}^{\\infty} (-1)^n \\frac{x^{2n+1}}{(2n+1)!} ";
    string x = expressionParser(tokenList[1]);
    if (x.size()) trim(x);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string exp = "\\sin("+x+") = \\sum_{n=0}^{"+term+"} (-1)^n \\frac{"+x+"^{2n+1}}{(2n+1)!} ";
    return exp;
}

string cosSeriesHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "\\cos x = \\sum_{n=0}^{\\infty} (-1)^n \\frac{x^{2n}}{(2n)!} ";
    string x = expressionParser(tokenList[1]);
    if (x.size()) trim(x);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string exp = "\\cos("+x+") = \\sum_{n=0}^{"+term+"} (-1)^n \\frac{"+x+"^{2n}}{(2n)!} ";
    return exp;
}

string logSeriesHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "\\ln(1+x) = \\sum_{n=1}^{\\infty} (-1)^{n+1} \\frac{x^n}{n} ";
    string x = expressionParser(tokenList[1]);
    if (x.size()) trim(x);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string exp = "\\ln(1+"+x+") = \\sum_{n=1}^{"+term+"} (-1)^{n+1} \\frac{"+x+"^n}{n} ";
    return exp;
}

string powerSeriesHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "\\sum_{n=0}^{\\infty} a_n (x-a)^n ";
    string x = expressionParser(tokenList[1]);
    if (x.size()) trim(x);
    string a = expressionParser(tokenList[2]);
    if (a.size()) trim(a);
    string term = expressionParser(tokenList[3]);
    if (term.size()) trim(term);
    string exp = "\\sum_{n=0}^{"+term+"} a_n ("+x+"-"+a+")^n ";
    return exp;
}

string genFuncHandler(vector<string>& tokenList){
    if(tokenList.size()==1) return "G(x) = \\sum_{n=0}^{\\infty} a_n x^n ";
    string x = expressionParser(tokenList[1]);
    if (x.size()) trim(x);
    string term = expressionParser(tokenList[2]);
    if (term.size()) trim(term);
    string exp = "G("+x+") = \\sum_{n=0}^{"+term+"} a_n "+x+"^n ";
    return exp;
}
#include "../headers/latexHandler.h"
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

string rawHandler(vector<string>& tokenList) {
    if ((int) tokenList.size() == 1) return "";
    string res = tokenList[1];
    if (res.size()) trim(res);
    return res;
}

string importHandler(vector<string>& tokenList) {
    vector<string> packages;
    string pack = tokenList[1];
    
    for (int i = 0; i < pack.size(); i++) {
        string package;
        while (i < pack.size() && pack[i] != ',') package.push_back(pack[i++]);
        if (package.size()) trim(package);
        if (package.size()) packages.push_back(package);
    }

    string res;
    for (int i = 0; i < packages.size(); i++) {
        res += " \\usepackage{" + packages[i] + "}";
    }

    return res;
}
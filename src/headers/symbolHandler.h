#pragma once
#include <vector>
#include <string>
using namespace std;

string limitHandler(vector<string>& tokenList);
string sumHandler(vector<string>& tokenList);
string prodHandler(vector<string>& tokenList);
string combinationHandler(vector<string>& tokenList, int type);
string vectorHandler(vector<string>& tokenList);
string overlineHandler(vector<string>& tokenList);
string boldmathHandler(vector<string>& tokenList);
string textHandler(vector<string>& tokenList);
string scriptHandler(vector<string>& tokenList, int type);
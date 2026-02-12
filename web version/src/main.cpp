#include <emscripten.h>
#include <iostream>
#include <string>
#include "./headers/parser.h"
#include "./headers/globalVars.h"

std::unordered_map<std::string, std::string> custom_defines;
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

EMSCRIPTEN_KEEPALIVE
void compile_velvet(const char* input) {
    // 1. Process the input string
    custom_defines.clear();
    string x = expressionParser(input);
    string output = "";

    // 2. Your existing sanitization logic
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '(') output += "\\left(";
        else if (x[i] == ')') output += "\\right)";
        else output += x[i];
    }

    // 3. Print to stdout
    cout << output << endl;
}

#ifdef __cplusplus
}
#endif
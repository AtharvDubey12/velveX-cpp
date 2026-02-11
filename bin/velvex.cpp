#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: velvex <file.vel> [-o output.tex]\n";
        return 1;
    }

    string inputFile;
    string outputFile;

    // ---- Parse arguments ----
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];

        if (arg == "-o") {
            if (i + 1 >= argc) {
                cerr << "Error: -o requires a filename\n";
                return 1;
            }
            outputFile = argv[++i];
        } else if (inputFile.empty()) {
            inputFile = arg;
        } else {
            cerr << "Error: unknown argument: " << arg << "\n";
            return 1;
        }
    }

    if (inputFile.empty()) {
        cerr << "Error: no input file provided\n";
        return 1;
    }

    // Default output: file.vel -> file.tex
    if (outputFile.empty()) {
        outputFile = inputFile.substr(0, inputFile.find_last_of('.')) + ".tex";
    }

    // ---- Read input file ----
    ifstream file(inputFile);
    if (!file.is_open()) {
        cerr << "Error: could not open " << inputFile << "\n";
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string source = buffer.str();

    // ---- Escape source for parser.exe ----
    string escaped;
for (size_t i = 0; i < source.length(); ++i) {
    char c = source[i];
    char next = (i + 1 < source.length()) ? source[i + 1] : '\0';
    char next2 = (i + 2 < source.length()) ? source[i + 2] : '\0';
    char prev = (i > 0) ? source[i - 1] : '\0';

    // 1. Handle Carriage Returns
    if (c == '\r') continue;

    // 2. Handle Newlines
    if (c == '\n') {
        escaped += " \\n ";
        continue;
    }

    // 3. Handle Double Quotes
    if (c == '"') {
        escaped += "\\\"";
        continue;
    }

    // 4. Handle "__"
    if (c == '_' && next == '_') {
        escaped += "__";
        i += 1;
        continue;
    }

    // 5. Handle Caret
    if (c == '^') {
        escaped += " ^";
        continue;
    }

    // 6. Handle single "_"
    if (c == '_') {
        escaped += " _";
        continue;
    }

    // ===============================
    //  ATOMIC MULTI-CHAR OPERATORS
    // ===============================

    // 3-character operators FIRST
    if (c == '!' && next == '~' && next2 == '=') {
        escaped += " !~= ";
        i += 2;
    }
    else if (c == '<' && next == '=' && next2 == '>') {
        escaped += " <=> ";
        i += 2;
    }

    // 2-character operators
    else if (c == '=' && next == '=') {
        escaped += " == ";
        i += 1;
    }
    else if (c == '~' && next == '=') {
        escaped += " ~= ";
        i += 1;
    }
    else if (c == '<' && next == '=') {
        escaped += " <= ";
        i += 1;
    }
    else if (c == '>' && next == '=') {
        escaped += " >= ";
        i += 1;
    }
    else if (c == '-' && next == '>') {
        escaped += " -> ";
        i += 1;
    }
    else if (c == '=' && next == '>') {
        escaped += " => ";
        i += 1;
    }
    else if (c == '!' && next == '=') {
        escaped += " != ";
        i += 1;
    }

    // ===============================
    // Single Operator Isolation
    // ===============================
    else if (c == '+' || c == '*' || c == '/' || c == '(' || c == ')' ||
            (c == '-' && next != '>') || 
            (c == '=' && next != '>' && next != '=' && prev != '!' && prev != '=')) {
        escaped += " ";
        escaped += c;
        escaped += " ";
    }

    // 7. Default
    else {
        escaped += c;
    }
}





    // ---- Build command ----
    string command =
        "parser.exe \"" + escaped + "\" > \"" + outputFile + "\"";

    int status = system(command.c_str());

    if (status == 0) {
        cout << "Compiled successfully to: " << outputFile << "\n";
    } else {
        cerr << "Compilation failed\n";
    }

    return status;
}

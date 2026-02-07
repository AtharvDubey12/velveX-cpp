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
    for (char c : source) {
        if (c == '\r') continue;
        if (c == '\n') escaped += " \\n ";
        else if (c == '"') escaped += "\\\"";
        else escaped += c;
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

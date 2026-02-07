#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: velrun <file.vel>\n";
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cerr << "Error: could not open " << argv[1] << "\n";
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string source = buffer.str();

    // Convert file content into a single CLI-safe string
    string escaped;
for (size_t i = 0; i < source.size(); i++) {
    if (source[i] == '\r') {
        // skip CR entirely
        continue;
    }
    if (source[i] == '\n') {
        escaped += " \\n ";   // EXACT token
    }
    else if (source[i] == '"') {
        escaped += "\\\"";
    }
    else {
        escaped += source[i];
    }
}

    cout << escaped << endl;
    // Build the exact command your transpiler expects
    string command = "parser.exe \"" + escaped + "\"";

    return system(command.c_str());
}

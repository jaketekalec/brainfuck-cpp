#include <vector>
#include <iostream>
#include <iterator>
#include <stack>
#include <fstream>
#include <string>

#include "program.h"

using namespace std;


int main(int argc, char *argv[]) {
    if(argc < 2) {
        cerr << "Usage: ./brainfuck.exe src";
        return 1;
    }

    ifstream progfile(argv[1]);
    ofstream dumpfile("dumps\\finaldump.txt");
    string programStr;
    string input;
    string output;
    string line;

    cout << "Input:" << endl;

    while(getline(progfile,line)) {
        programStr += line;
    }
    getline(cin,input);
    dumpfile << input << endl;
    Program prog(programStr,input);

    output = prog.execute();
    dumpfile << prog.memDump();
    cout << output;
    progfile.close();
    dumpfile.close();
    return 0;
}
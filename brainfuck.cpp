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
    ofstream dumpfile;
    string programStr;
    string input;
    string output;
    string line;
    vector<string> dumps;

    cout << "Input:" << endl;

    //Why is this the most straight-forward way to read a whole file in c++??
    while(getline(progfile,line)) {
        programStr += line;
    }
    getline(cin,input);
    Program prog(programStr,input);

    output = prog.execute();
    prog.addMemDump();
    dumps = prog.getMemDumps();
    int i = 0;
    for (string dump : dumps) {
        dumpfile.open("dumps\\dump"+to_string(i)+".txt",ofstream::out);
        dumpfile.write(dump.c_str(),dump.size());
        dumpfile.close();
        i++;
    }
    cout << output;
    progfile.close();
    return 0;
}
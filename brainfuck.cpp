#include <vector>
#include <iostream>
#include <iterator>
#include <stack>
#include <fstream>

#include "program.h"

using namespace std;


//TODO: Make Program constructor accept streams
int main(int argc, char *argv[]) {
    ifstream progfile(argv[1]);
    ofstream dumpfile("dumps\\finaldump.txt");
    string programStr;
    string input;
    string line;

    while(getline(progfile,line)) {
        programStr += line;
    }
    getline(cin,input);
    dumpfile << input << endl;
    Program prog(programStr,input);

    prog.execute();
    dumpfile << prog.memDump();
    progfile.close();
    dumpfile.close();
    return 0;
}
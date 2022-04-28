#ifndef _PROGRAM_H
#define _PROGRAM_H
#include <iostream>
#include <stack>
#include <iterator>
#include <map>
#include "memory.h"

using namespace std;

class Program {
    public:
        Program();
        Program(string);
        Program(string,string);
        void execute();
        void setProgram(string pstr) {program=pstr;}
        string memDump();
    private:
        string program;
        string input;
        int pointer;
        int inputPtr;
        Memory mem;
        map<int,int> loops;
};
#endif
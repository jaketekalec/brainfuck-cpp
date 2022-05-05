#ifndef _PROGRAM_H
#define _PROGRAM_H
#include <iostream>
#include <stack>
#include <iterator>
#include <map>
#include <vector>
#include "memory.h"

using namespace std;

class Program {
    public:
        Program();
        Program(string);
        Program(string,string);
        string execute();
        void setProgram(string pstr) {program=pstr;}
        void addMemDump() {memDumps.push_back(mem.dump());}
        vector<string> getMemDumps() {return memDumps;};
    private:
        string program = "";
        string input = "";
        string output = "";
        int pointer;
        int inputPtr;
        Memory mem;
        vector<string> memDumps;
        map<int,int> loops;
};
#endif
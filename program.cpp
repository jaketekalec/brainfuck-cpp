#include <iostream>
#include <fstream>
#include <stack>
#include <utility>

#include "program.h"

//Add a constructor that takes an ostream for
//normal output and an ostream for memdumps
Program::Program(string prog) {
    program = prog;
    input = "";
    pointer = 0;
    inputPtr = 0;
}

Program::Program(string prog, string in) {
    program = prog;
    input = in;
    pointer = 0;
    inputPtr = 0;
}

void Program::execute() {
    char ch;
    int loop;
    ofstream dumpfile("dumps\\middump.txt");
    stack<int> loopStack;
    pair<int,int> currLoop;//*loops.begin();

    //Get all loop brackets and find pairs
    //Here, loopStack serves the purpose of storing '[' positions
    //They are popped off of loop stack when their pair ']' is found
    //and inserted into the loops map
    for(int i=0;i<program.size();i++) {
        ch = program[i];

        //Add try/catch block to account for unmatched brackets
        if(ch=='[') {
            loopStack.push(i);
        }
        else if(ch==']') {
            loops.insert(pair<int,int>(loopStack.top(),i));
            loopStack.pop();
        }
    }

    //Iterate through program to execute
    //loopStack is repurposed
    for(;pointer<program.size();pointer++) {
        ch = program[pointer];
        if(ch=='<') mem.movePtrLeft();
        else if(ch=='>') mem.movePtrRight();
        else if(ch=='+') mem.incr();
        else if(ch=='-') mem.decr();
        else if(ch=='.') {
            //Don't print problematic control characters if you're using cout (files are OK though)
            //if(mem.atPtr()>=0x20) 
                dumpfile << mem.atPtr();
        } 
        else if(ch==',') {
            if(input[inputPtr]!=0x00 && inputPtr<=input.length()) {
                mem.input(input[inputPtr]);
                inputPtr++;
            }
        }
        else if(ch=='[') {
            if(mem.atPtr()==0) {
                pointer = loops.at(pointer);
            }
            else {
                loopStack.push(pointer);
            }
        }
        else if(ch==']') {
            if(mem.atPtr()==0) {
                loopStack.pop();
            }
            else {
                pointer = loopStack.top();
            }
        }
        else if(ch=='#') {
            memDump(); //Get this working properly
        }
    }
}

string Program::memDump() {
    return mem.dump();
}
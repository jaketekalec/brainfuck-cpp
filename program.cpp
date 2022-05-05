#include <iostream>
#include <fstream>
#include <stack>
#include <utility>

#include "program.h"

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

string Program::execute() {
    char ch;
    int loop;
    stack<int> loopStack;
    pair<int,int> currLoop;//*loops.begin();

    //Get all loop brackets and find pairs
    //Here, loopStack serves the purpose of storing '[' positions
    //They are popped off of loop stack when their pair ']' is found
    //and inserted into the loops map
    for(int i=0;i<program.size();i++) {
        ch = program[i];

        if(ch=='[') {
            loopStack.push(i);
        }
        else if(ch==']' && !loopStack.empty()) {
            loops.insert(pair<int,int>(loopStack.top(),i));
            loopStack.pop();
        }
        else if(ch==']' && loopStack.empty()) {
            cerr << "Error: Unmatched ']' at " << i << endl;
            exit(1);
        }
    }

    if(!loopStack.empty()) {
        cerr << "Error: Unmatched '[' at " << loopStack.top() << endl;
        exit(1);
    }

    //Iterate through program to execute
    //loopStack is repurposed to store the
    //previous '[' position
    ////I've heard of polymorphism, but this is ridiculous!
    for(;pointer<program.size();pointer++) {
        ch = program[pointer];
        if(ch=='<') mem.movePtrLeft();
        else if(ch=='>') mem.movePtrRight();
        else if(ch=='+') mem.incr();
        else if(ch=='-') mem.decr();
        else if(ch=='.') {
            output += mem.atPtr();
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
            addMemDump();
        }
    }
    return output;
}
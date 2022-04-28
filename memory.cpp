#include <vector>
#include <iostream>
#include <iterator>

#include "memory.h"

using namespace std;

Memory::Memory() {
    dataVec = vector<uint8_t>(1000,0);
    pointer = dataVec.begin();
}

void Memory::movePtrLeft() {
    --pointer;
}

void Memory::movePtrRight() {
    ++pointer;
}

void Memory::incr() {
    ++(*pointer);
}

void Memory::decr() {
    --(*pointer);
}

void Memory::input(char in) {
    *pointer = in;
}

void Memory::output() {
    cout << *pointer;
}

uint8_t Memory::atPtr() {
    return *pointer;
}

string Memory::dump() {
    string fulldump;
    int cellCount = 0;
    fulldump += to_string(pointer-dataVec.begin()) + '\n';
    for(uint8_t b : dataVec) {
        if(cellCount%16==0)
            fulldump += '\n';
        fulldump += to_string((int)b*0.000001).substr(5) + ' ';
        cellCount++;
    }
    return fulldump;
}
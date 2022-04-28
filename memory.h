#ifndef _MEMORY_H
#define _MEMORY_H
#include <vector>
#include <iterator>
#include <cstdint>

using namespace std;

class Memory {
    public:
        Memory();
        void movePtrLeft();
        void movePtrRight();
        void incr();
        void decr();
        void input(char in);
        void output();
        uint8_t atPtr();
        string dump();
    private:
        vector<uint8_t> dataVec;
        vector<uint8_t>::iterator pointer;
};

#endif
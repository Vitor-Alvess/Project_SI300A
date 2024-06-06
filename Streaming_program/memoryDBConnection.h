#ifndef MEMORYDBCONNECTION_H_
#define MEMORYDBCONNECTION_H_

#include <vector>

#include "register.h"

using namespace std;

class MemoryDBConnection{
    private:
        vector<Register*> registersDB;
    public:
        MemoryDBConnection();
        virtual ~MemoryDBConnection();

        vector<Register*>& getRegisterList();
        void close();
};

#endif
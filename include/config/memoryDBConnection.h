#ifndef MEMORYDBCONNECTION_H_
#define MEMORYDBCONNECTION_H_

#include <vector>

#include "../model/register.h"

class MemoryDBConnection{
    private:
        std::vector<Register*> registersDB;
    public:
        MemoryDBConnection();
        virtual ~MemoryDBConnection();

        std::vector<Register*>& getRegisterList();
        void close();
};

#endif
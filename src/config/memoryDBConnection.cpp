#include "../../include/config/memoryDBConnection.h"

using namespace std;

MemoryDBConnection::MemoryDBConnection(){
    registersDB = vector<Register*>();
}

MemoryDBConnection::~MemoryDBConnection(){
    close();
}

vector<Register*>& MemoryDBConnection::getRegisterList(){
    return registersDB;
}

void MemoryDBConnection::close(){
    for (Register *buffer : registersDB){
        delete buffer;
        buffer = NULL;
    }
    registersDB.clear();
}

#include "registerMemDAO.h"

registerMemDAO::registerMemDAO(MemoryDBConnection *memoryDBConnection):
        memoryDBConnection(memoryDBConnection){}

registerMemDAO::~registerMemDAO(){}

vector<Register*>& registerMemDAO::getAllRegisters(){
    return (memoryDBConnection->getRegisterList());
}

void registerMemDAO::addRegister(Register *Register){
    (memoryDBConnection->getRegisterList()).push_back(Register);
}

void registerMemDAO::deleteRegister(int registerID){
    vector<Register*> &registers = memoryDBConnection->getRegisterList();
    vector<Register*>::iterator registerIterator = registers.begin();
    bool found = false;

    while((!found) && (registerIterator != registers.end())){

        if ((*registerIterator)->getRegisterId() == registerID){
            found = true;
            delete *registerIterator;
            registers.erase(registerIterator);
        }
        
        registerIterator++;
    }
}
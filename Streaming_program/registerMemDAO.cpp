#include "registerMemDAO.h"

registerMemDAO::registerMemDAO(MemoryDBConnection *memoryDBConnection):
        memoryDBConnection(memoryDBConnection){}

registerMemDAO::~registerMemDAO(){}

vector<Register*>& registerMemDAO::getAllRegisters(){
    return (memoryDBConnection->getRegisterList());
}

Register* registerMemDAO::getRegisterById(int registerId){
    vector<Register*> &registers = memoryDBConnection->getRegisterList();
    vector<Register*>::iterator registersIterator = registers.begin();
    Register *buffer = NULL;
    bool found = false;

    while ((!found) && (registersIterator != registers.end())){
        
        if ((*registersIterator)->getRegisterId() == registerId){
            found = true;
            buffer = *registersIterator;
        }

        registersIterator++;
    }

    return (buffer);
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
            lastDeleted = new Register(*registerIterator);

            found = true;

            delete *registerIterator;
            registers.erase(registerIterator);
        }

        registerIterator++;
    }
}

void registerMemDAO::editRegister(Register *Register){
    deleteRegister(Register->getRegisterId());
    addRegister(Register);
}

void registerMemDAO::recoverRegister(){
    addRegister(lastDeleted);
    lastDeleted = NULL;
}

Register* registerMemDAO::getLastDeleted(){
    return lastDeleted;
}
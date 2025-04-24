#include "../../include/view/registerMemDAO.h"

registerMemDAO::registerMemDAO(MemoryDBConnection *memoryDBConnection):
        memoryDBConnection(memoryDBConnection){}

registerMemDAO::~registerMemDAO(){}

vector<Register*> registerMemDAO::getAllRegisters(){
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

void registerMemDAO::editRegister(Register *oldRegister, string registerName, int releaseYear, int NumOfSeasons, int EpisodesTotal,
                                string mainPlot, string mainCharacters, string streaming, float score){
            
            oldRegister->setRegisterName((registerName.empty()) ? oldRegister->getRegisterName() : registerName);
            oldRegister->setRegisterReleaseYear((!releaseYear) ? oldRegister->getRegisterReleaseYear() : releaseYear);
            oldRegister->setRegisterNumOfSeasons((!NumOfSeasons) ? oldRegister->getRegisterNumOfSeasons() : NumOfSeasons);
            oldRegister->setRegisterEpisodesTotal ((!EpisodesTotal) ? oldRegister->getRegisterEpisodesTotal() : EpisodesTotal);
            oldRegister->setRegisterMainPlot ((mainPlot.empty()) ? oldRegister->getRegisterMainPlot() : mainPlot);
            oldRegister->setRegisterMainCharacters ((mainCharacters.empty()) ? oldRegister->getRegisterMainCharacters() : mainCharacters);
            oldRegister->setRegisterStreaming ((streaming.empty()) ? oldRegister->getRegisterStreaming() : streaming);
            oldRegister->setRegisterScore ((!score) ? oldRegister->getRegisterScore() : score);
}

void registerMemDAO::recoverRegister(){
    addRegister(lastDeleted);
    lastDeleted = NULL;
}

Register* registerMemDAO::getLastDeleted(){
    return lastDeleted;
}
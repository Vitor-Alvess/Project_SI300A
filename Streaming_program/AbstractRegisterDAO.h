#include <vector>
#include "register.h"

#ifndef ABSTRACTREGISTERDAO_H_
#define ABSTRACTREGISTERDAO_H_

class AbstractRegisterDAO{
    public:
        virtual vector<Register*> getAllRegisters() = 0;
        virtual Register* getRegisterById(int registerId) = 0;
        virtual void addRegister(Register *Register) = 0;
        virtual void deleteRegister(int registerID) = 0;
        virtual void editRegister(Register *oldRegister, string RegisterName, int releaseYear, int NumOfSeasons, int EpisodesTotal,
                                string mainPlot, string mainCharacters, string streaming, float score) = 0;
        virtual void recoverRegister() = 0;
        virtual Register* getLastDeleted() = 0;
};

#endif
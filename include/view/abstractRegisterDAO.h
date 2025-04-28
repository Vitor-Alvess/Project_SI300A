#include <vector>
#include "../model/register.h"
#include "../config/databaseType.h"

#ifndef ABSTRACTREGISTERDAO_H_
#define ABSTRACTREGISTERDAO_H_

class AbstractRegisterDAO{
    public:
        virtual ~AbstractRegisterDAO();
        virtual std::vector<Register*> getAllRegisters() = 0;
        virtual Register* getRegisterById(int registerId) = 0;
        virtual void addRegister(Register *Register) = 0;
        virtual void deleteRegister(int registerID) = 0;
        virtual void editRegister(Register *oldRegister, std::string RegisterName, int releaseYear, int NumOfSeasons, int EpisodesTotal,
                                std::string mainPlot, std::string mainCharacters, std::string streaming, float score) = 0;
        virtual void recoverRegister() = 0;
        virtual Register* getLastDeleted() = 0;
        virtual DatabaseType getDatabaseType() = 0;
};

#endif
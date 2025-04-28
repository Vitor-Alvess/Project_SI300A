#ifndef REGISTERMEMDAO_H_
#define REGISTERMEMDAO_H_

#include "../config/memoryDBConnection.h"
#include "abstractRegisterDAO.h"

class registerMemDAO final: public AbstractRegisterDAO{
    private:
        MemoryDBConnection* memoryDBConnection;
        Register* lastDeleted = NULL;
    public:
        registerMemDAO(MemoryDBConnection* memoryDBConnection);
        virtual ~registerMemDAO();

        virtual std::vector<Register*> getAllRegisters();
        virtual Register* getRegisterById(int registerId);
        virtual void addRegister(Register *Register);
        virtual void deleteRegister(int registerID);
        virtual void editRegister(Register *oldRegister, std::string RegisterName, int releaseYear, int NumOfSeasons, int EpisodesTotal,
                                std::string mainPlot, std::string mainCharacters, std::string streaming, float score);
        virtual void recoverRegister();
        virtual Register* getLastDeleted();
        virtual DatabaseType getDatabaseType();
};

#endif
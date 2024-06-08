#ifndef REGISTERMEMDAO_H_
#define REGISTERMEMDAO_H_

#include "memoryDBConnection.h"
using namespace std;

class registerMemDAO{
    private:
        MemoryDBConnection* memoryDBConnection;
        Register* lastDeleted = NULL;
    public:
        registerMemDAO(MemoryDBConnection* memoryDBConnection);
        virtual ~registerMemDAO();

        virtual vector<Register*> &getAllRegisters();
        virtual Register* getRegisterById(int registerId);
        virtual void addRegister(Register *Register);
        virtual void deleteRegister(int registerID);
        virtual void editRegister(Register *Register);
        virtual void recoverRegister();
        virtual Register* getLastDeleted();
};

#endif
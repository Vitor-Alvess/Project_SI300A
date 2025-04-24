#include "../config/serverDBConnection.h"
#include "../model/register.h"
#include "abstractRegisterDAO.h"

class registerServerDAO final : public AbstractRegisterDAO{
    private:
		static const string SQL_getAllRegisters;
		static const string SQL_getRegisterById;
		static const string SQL_addRegister;
		static const string SQL_editRegister;
		static const string SQL_deleteRegister;

		ServerDBConnection *serverDBConnection;

        Register* lastDeleted = NULL;

    public:
        registerServerDAO(ServerDBConnection *serverDBConnection);
        ~registerServerDAO();

        virtual vector<Register*> getAllRegisters();
        virtual Register* getRegisterById(int registerId);
        virtual void addRegister(Register *Register);
        virtual void deleteRegister(int registerID);
        virtual void editRegister(Register *oldRegister, string RegisterName, int releaseYear, int NumOfSeasons, int EpisodesTotal,
                                string mainPlot, string mainCharacters, string streaming, float score);
        virtual void recoverRegister();
        virtual Register* getLastDeleted();
};
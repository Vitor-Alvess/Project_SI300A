#include "../config/serverDBConnection.h"
#include "../model/register.h"
#include "abstractRegisterDAO.h"

class registerServerDAO final : public AbstractRegisterDAO{
    private:
		static const std::string SQL_getAllRegisters;
		static const std::string SQL_getRegisterById;
		static const std::string SQL_addRegister;
		static const std::string SQL_editRegister;
		static const std::string SQL_deleteRegister;

		ServerDBConnection *serverDBConnection;

        Register* lastDeleted = NULL;

    public:
        registerServerDAO(ServerDBConnection *serverDBConnection);
        ~registerServerDAO();

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
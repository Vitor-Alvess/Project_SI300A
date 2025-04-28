#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../config/serverDBConnection.h"
#include "../config/utils.h"

#include "../view/registerServerDAO.h"

#include "../model/creditsAndHelp.h"
#include "../model/menu.h"
#include "../model/register.h"
#include "../view/registerMemDAO.h"
#include "../config/memoryDBConnection.h"
#include "../config/databaseType.h"
#include "../view/abstractRegisterDAO.h"

class Controller{
    private:
        MemoryDBConnection *memoryDBConnection;
        ServerDBConnection *serverDBConnection;
        AbstractRegisterDAO *registerDAO;

        void actionHelp();
        void actionCredits();
        void actionRegisters();
        void actionReports();
        void launchActions(std::string title, std::vector<std::string> menuOptions, std::vector<void (Controller::*)()> functions);
        void launchActions(std::string title, std::vector<std::string> menuOptions, std::vector<void (Controller::*)()> functions, bool isRegisterMenu);

        void addRegister();
        void editRegister();
        void deleteRegister();
        void recoverRegister();

        void OrderByName();
        void OrderByReleaseYear();
        void OrderByStreaming();
        void OrderByScore();
        void printRegistersList();

    public:
        Controller(DatabaseType dataBaseType);
        virtual ~Controller();
        void start();
};


#endif
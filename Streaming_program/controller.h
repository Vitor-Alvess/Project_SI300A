#ifndef CONTROLLER_H_
#define CONTROLLER_H_


#include "creditsAndHelp.h"
#include "menu.h"
#include "register.h"
#include "registerMemDAO.h"
#include "memoryDBConnection.h"

using namespace std;

class controller{
    private:
        MemoryDBConnection *memoryDBConnection;
        registerMemDAO *registerDAO;
        Register *lastRegisterDeleted;

        void actionHelp();
        void actionCredits();
        void actionRegisters();
        void actionReports();
        void launchActions(string title, vector<string> menuOptions, vector<void (controller::*)()> functions);

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
        controller();
        virtual ~controller();
        void start();
};


#endif
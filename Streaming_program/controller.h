#ifndef CONTROLLER_H_
#define CONTROLLER_H_


#include "creditsAndHelp.h"
#include "menu.h"

using namespace std;

class controller{
    private:
        void actionHelp();
        void actionCredits();
        void actionReports();
        void launchActions(string title, vector<string> menuOptions, vector<void (controller::*)()> functions);

        void addRegister();
        void editRegister();
        void deleteRegister();
        void recoverRegister();
        void registersList();

    public:
        controller();
        virtual ~controller();
        void start();
};


#endif
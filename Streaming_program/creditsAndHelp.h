#ifndef CREDITSANDHELP_H_
#define CREDITSANDHELP_H_

#include "menu.h"
#include <vector>

using namespace std;

class creditsAndHelp: public Menu{
    private:
        string message;
        void setMessage(string message);
    public:
        creditsAndHelp(string message, vector<string> &options, string title, string choice_msg = "Pressione qualquer tecla...");
        string getMessage();
        void printMessage(string message);
        virtual ~creditsAndHelp();
};

#endif
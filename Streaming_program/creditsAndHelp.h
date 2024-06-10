#ifndef CREDITSANDHELP_H_
#define CREDITSANDHELP_H_

#include<iostream>

#include "utils.h"

using namespace std;

class creditsAndHelp{
    private:
        string title;
        string message;
        string end_msg;
        void setMessage(string message);
        void readTextFromFile();
        
    public:
        creditsAndHelp(string message, string title);
        string getMessage();
        const string &getTitle() const;
        void printMessage(string message);
        virtual ~creditsAndHelp();
};

#endif
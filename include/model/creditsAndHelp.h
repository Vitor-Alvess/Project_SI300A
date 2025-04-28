#ifndef CREDITSANDHELP_H_
#define CREDITSANDHELP_H_

#include<iostream>

#include "../config/utils.h"

class creditsAndHelp{
    private:
        std::string title;
        std::string message;
        std::string end_msg;
        void setMessage(std::string message);
        void readTextFromFile();
        
    public:
        creditsAndHelp(std::string message, std::string title);
        std::string getMessage();
        const std::string &getTitle() const;
        void printMessage(std::string message);
        virtual ~creditsAndHelp();
};

#endif
#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
#include "../config/utils.h"

class Menu{
    private:
        std::string symbol;
        std::string welcomeMessage;
        bool firstTry;
        int width;
        const bool isNotValidOption(unsigned int opt) const;
    protected:
        std::string title;
        std::string choiceMsg;
        std::vector<std::string> &options;
        const std::string makeDecorator();
    public:
        bool isRegisterMenu;

        Menu(std::vector<std::string> &options, std::string title, bool isRegisterMenu, std::string choiceMsg = "Opcao: ");

        const std::string &getTitle() const;
        const int getOption();

        void setDecorator(const std::string &decorator, int width);

        int getWidth() const;
		void setWidth(int width = 0);

        const std::string getSymbol() const;
		void setSymbol(const std::string &symbol = "=");

        std::string getWelcomeMessage();
        void printWelcome();

        virtual ~Menu();
};


#endif 
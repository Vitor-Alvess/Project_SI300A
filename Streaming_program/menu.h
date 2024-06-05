#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
#include"utils.cpp"

using namespace std;

class Menu{
    protected:
        string title;
        string choice_msg;
        string symbol;
        string WelcomeMessage;
        bool firstWelcome;
        bool firstTry;
        int width;
        vector<string> &options;
        const string makeDecorator();
        const bool isNotValidOption(unsigned int opt) const;
        void setWelcomeMessage(string WelcomeMessage);

    public:
        Menu(vector<string> &options, string title, string choice_msg = "Opcao: ");
        const string &getTitle() const;
        const int getOption();

        void setDecorator(const string &decorator, int width);
        

        int getWidth() const;
		void setWidth(int width = 0);

        const string getSymbol() const;
		void setSymbol(const string &symbol = "=");

        string getWelcomeMessage();
        void printWelcome(bool firstWelcome);

        virtual ~Menu();
};


#endif 
#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
using namespace std;

class Menu{
    private:
        string title;
        string choice_msg;
        string symbol;
        int width;
        vector<string> &options;
        void makeDecorator();

    public:
        Menu(vector<string> &itens, string title, string choice_msg = "Option: ");
        const string &getTitle() const;
        const int getOption();

        void setDecorator(const string &decorator, int width);

        int getWidth() const;
		void setWidth(int width = 0);

        const string getSymbol() const;
		void setSymbol(const string &symbol = "=");

        virtual ~Menu();
};


#endif 
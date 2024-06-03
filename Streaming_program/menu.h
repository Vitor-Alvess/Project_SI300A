#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
using namespace std;

class Menu{
    private:
        string title;
        string choice;
    protected:
        vector<string> &options;
    public:
        Menu(vector<string> &itens, string title, string choice = "Option: ");
        const string &setTitle() const;
        void getTitle(const string &title);
        const int getOption();
        virtual ~Menu();
};


#endif 
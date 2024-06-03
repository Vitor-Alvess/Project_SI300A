#include "menu.h"
#include<iostream>
#include <vector>

using namespace std;

Menu::Menu(vector<string> &options, string title, string choice_msg):
        options(options), title(title), choice_msg(choice_msg){
            this->setWidth();
            this->setSymbol();
        }

void Menu::setDecorator(const string &symbol, int width){
    this->symbol = symbol;
    this->width = width;
}

const string &Menu::getTitle() const{
    return title;
}

const int Menu::getOption(){

}
Menu::~Menu(){}
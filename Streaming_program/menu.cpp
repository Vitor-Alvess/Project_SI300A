#include<iostream>
#include "menu.h"
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

const int Menu::getOption(){}

void Menu::setWidth(int width){
    this->width = width;
}

int Menu::getWidth() const{
    return width;
}

void Menu::setSymbol(const string &symbol){
    this->symbol = symbol;
}

const string Menu::getSymbol() const{
	return symbol;
}

Menu::~Menu(){}
#include <math.h>
#include "../../include/model/menu.h"

using namespace std;

Menu::Menu(vector<string> &options, string title, string choice_msg):
        options(options), title(title), choice_msg(choice_msg){
            this->setWidth(WIDTH);
            this->setSymbol(SYMBOL);
            this->setWelcomeMessage("SISTEMA DE CATÁLOGO DE SÉRIES\nBem Vindo!");
        }

const string &Menu::getTitle() const{
    return title;
}

const int Menu::getOption(){
    unsigned int selected_option;
    firstTry = true;
    string decorator = makeDecorator();
    printWelcome();
    do{
        if (firstTry){
            unsigned int index;
            cout << decorator << endl;
            cout << getTitle() << endl;

            for (index = 0; index < options.size(); index++){
                cout << index + 1 << " - " << options.at(index) << endl;
            }

            cout << decorator << endl;
            firstTry = false;
        }
        cout << choice_msg << endl;
        cin >> selected_option;
    }while(isNotValidOption(selected_option));
    cin.ignore();
    return selected_option;
}

void Menu::setDecorator(const string &symbol, int width){
    this->symbol = symbol;
    this->width = width;
}

int Menu::getWidth() const{
    return width;
}

void Menu::setWidth(int width){
    this->width = width;
}

const string Menu::getSymbol() const{
	return symbol;
}

void Menu::setSymbol(const string &symbol){
    this->symbol = symbol;
}

string Menu::getWelcomeMessage(){
    return WelcomeMessage;
}

void Menu::printWelcome(){
        cout << WelcomeMessage << endl;
}

Menu::~Menu(){}

const bool Menu::isNotValidOption(unsigned int opt) const{
    if ((opt < 1) || (opt > options.size())){
        cout << "Opcao invalida!" << endl;
        return true;
    }
    else
        return false;
}

const string Menu::makeDecorator(){
    string sym = getSymbol();
    if (!width){
        for (string option : options){
            width = ((unsigned long int) width >= option.length()) ? width : option.length();
        }
        width += (log10(options.size()));
    }

    int aux;
    string buffer;
    for (aux = 0; aux <= width; aux++){
        buffer += symbol;
    }

    return buffer;
}

void Menu::setWelcomeMessage(string WelcomeMessage){
    (this->title == "MENU PRINCIPAL") ? this->WelcomeMessage = WelcomeMessage : "";
}
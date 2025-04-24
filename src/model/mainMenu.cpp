#include "../../include/model/mainMenu.h"

mainMenu::mainMenu( vector<string> &options, string title, string choice_msg):
        Menu(options, title, choice_msg){
            this->message = message;
            setMessage("SISTEMA DE CATÁLOGO DE SÉRIES\nBem Vindo!");
            printMessage(getMessage(), firstWelcome = true);
        }

string mainMenu::getMessage(){
    return message;
}

void mainMenu::printMessage(string message, bool firstWelcome){
    if(firstWelcome){
        cout << message << endl;
        firstWelcome = false;
    }
    else
        return;
}

void mainMenu::setMessage(string message){
    this->message = message;
}

mainMenu::~mainMenu(){};


#include "creditsAndHelp.h"

creditsAndHelp::creditsAndHelp(string message, vector<string> &options, string title, string choice_msg):
        Menu(options, title, choice_msg){
    this->setWidth(10);
    this->setSymbol("*");
    setMessage(message);
};

string creditsAndHelp::getMessage(){
    return this->message;
};


void creditsAndHelp::printMessage(string message){
    string decorator = makeDecorator();
    cout << title << endl;
    cout << decorator << endl;
    cout << message << endl;
    cout << choice_msg << endl;
    this->~creditsAndHelp();
};

void creditsAndHelp::setMessage(string message){
    this->message = message;
}

creditsAndHelp::~creditsAndHelp(){
   getchar();
}
#include "creditsAndHelp.h"

creditsAndHelp::creditsAndHelp(string message, string title){
    this->end_msg = end_msg;
    this->title = title;
    (IS_WINDOWS) ? this->end_msg = "Pressione a tecla enter para voltar..." : this->end_msg = "";
    setMessage(message);
};

string creditsAndHelp::getMessage(){
    return this->message;
};

const string &creditsAndHelp::getTitle() const{
    return this->title;
}
void creditsAndHelp::printMessage(string message){
    cout << getTitle() << "\n" << endl;
    cout << message << endl;
    cout << this->end_msg << endl;
    this->~creditsAndHelp();
};

void creditsAndHelp::setMessage(string message){
    this->message = message;
}

creditsAndHelp::~creditsAndHelp(){
   utils::pause();
}
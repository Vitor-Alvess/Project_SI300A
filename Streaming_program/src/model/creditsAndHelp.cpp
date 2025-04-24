#include "../../include/model/creditsAndHelp.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

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
    if (title == "CRÉDITOS"){
        this->message = message;
    }
    else
        readTextFromFile();
}

creditsAndHelp::~creditsAndHelp(){
   Utils::pause();
}

void creditsAndHelp::readTextFromFile(){
    string fileContent = "";
    try{
        ifstream inputFile("helpText.txt");
        stringstream buffer;

        if (!inputFile.is_open()){
			throw runtime_error("Falha ao abrir o arquivo de ajuda: helpText.txt");
		}

            buffer << inputFile.rdbuf();
            inputFile.close();
            fileContent = buffer.str();
            cout << fileContent << endl;
    }
    catch(const exception &myError){
        cout << "Erro inesperado: " << myError.what() << endl;
    }
}
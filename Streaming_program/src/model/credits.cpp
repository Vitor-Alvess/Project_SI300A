#include "../../include/model/credits.h"

credits::credits(vector<string> &options, string title, string choice_msg):
        Menu(options, title, choice_msg){
    setMessage("Desenvolvido em 2024 por:\n"
            "- Laura Gouveia Nunes\n"
            "- Matheus Cirillo\n"
            "- Marcos Vinicius Balestero\n"
            "- Ori Kao Minohara\n"
            "- Vitor Alves\n");
};

string credits::getMessage(){
    return options.at(0);
};


void credits::printMessage(string message){
    string decorator = makeDecorator();
    cout << title << endl;
    cout << decorator << endl;
    cout << message << endl;
    cout << choice_msg << endl;
    this->~credits();
};

void credits::setMessage(string message){
    options.at(0) = message;
}

credits::~credits(){
   getchar();
}
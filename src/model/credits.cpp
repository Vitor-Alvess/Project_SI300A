#include "../../include/model/credits.h"

using namespace std;

credits::credits(vector<string> &options, string title, string choiceMsg):
        Menu(options, title, false, choiceMsg){
            setMessage("Desenvolvido em 2024 por:\n"
                    "- Laura Gouveia Nunes\n"
                    "- Matheus Cirillo\n"
                    "- Marcos Vinicius Balestero\n"
                    "- Ori Kao Minohara\n"
                    "- Vitor Alves");
        };

string credits::getMessage(){
    return options.at(0);
};

void credits::printMessage(string message){
    string decorator = makeDecorator();
    cout << getTitle() << endl;
    cout << decorator << endl;
    cout << message << endl;
    cout << choiceMsg << endl;
    this->~credits();
};

void credits::setMessage(string message){
    options.at(0) = message;
}

credits::~credits(){
   getchar();
}
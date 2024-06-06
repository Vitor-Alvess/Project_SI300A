#include "controller.h"
#include "utils.cpp"
#include "menu.h"

controller::controller(){};

controller::~controller(){};

void controller::start(){
    vector<string> MainMenu_Options
        {"Relatórios", "Creditos", "Ajuda", "Sair"};
    vector<void (controller::*)()> functions
        {&controller::actionReports, &controller::actionHelp, &controller::actionCredits};
    launchActions("MENU PRINCIPAL", MainMenu_Options, functions);
}

void controller::actionReports(){
    vector<string> reportsOptions
        {"Listar registros", "Adicionar registro", "Editar registro", "Deletar registro", "Recuperar registro", "Voltar"};
    vector<void (controller::*)()> functions
        {&controller::registersList, &controller::addRegister, &controller::editRegister, &controller::deleteRegister, &controller::recoverRegister};
    launchActions("RELATÓRIO", reportsOptions, functions); 
}

void controller::actionHelp(){
    string helpMessage = "texto de ajuda\n";
    creditsAndHelp *help = new creditsAndHelp(helpMessage, "AJUDA");
    help->printMessage(help->getMessage());
}

void controller::actionCredits(){
    string creditsMessage = "Desenvolvido em 2024 por:\n"
                        "- Laura Gouveia Nunes\n"
                        "- Matheus Cirillo\n"
                        "- Marcos Vinicius Balestero\n"
                        "- Ori Kao Minohara\n"
                        "- Vitor Alves\n";
    creditsAndHelp *credits = new creditsAndHelp(creditsMessage, "CRÉDITOS");
    credits->printMessage(credits->getMessage());
}

void controller::launchActions(string title, vector<string> options, vector<void (controller::*)()> functions){
    try{
        Menu menu(options, title);
        while(int choice = menu.getOption()){
            (this->*functions.at(choice - 1))();
        }
    }
    catch (exception &myError){
        cout << "unexpected problem ocurred when trying to launch actions..." << string(myError.what()); 
    }
}




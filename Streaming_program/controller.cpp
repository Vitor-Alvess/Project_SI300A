#include "controller.h"
#include <iostream>
#include <string>

using namespace std;

controller::controller(){
    memoryDBConnection = NULL;

    registerDAO = new registerMemDAO(new MemoryDBConnection());

    registerDAO->addRegister(new Register("The Flash", 2014, 9, 184, "Grant Gustin, Danielle Panabaker, Stephen Amell", "Barry Allen, Iris West, Wally West, Vibro, Caitlin Snow", "Netflix", 7.5));
    registerDAO->addRegister(new Register("The Office", 2005, 9, 201, "Steve Carell, John Krasinski, Jenna Fischer", "Michael Scott, Dwigth Schrute, Pamela Weesly, Jim Halpert", "Netflix", 9));
    registerDAO->addRegister(new Register("Stranger Things", 2016, 4, 34, "Finn Wolfhard, Millie Bobby Brown, David Harbour", "Mike Weeler, Eleven, Dustin Henderson, Lucas Sinclair, Will Byers, Max Mayfield", "Netflix", 8.7));

};

controller::~controller(){};

void controller::start(){
    vector<string> MainMenu_Options
        {"Relatórios", "Creditos", "Ajuda", "Sair"};
    vector<void (controller::*)()> functions
        {&controller::actionRegisters, &controller::actionHelp, &controller::actionCredits};
    launchActions("MENU PRINCIPAL", MainMenu_Options, functions);
}

void controller::actionRegisters(){
    vector<string> registers_Options
        {"Relatórios", "Adicionar registro", "Editar registro", "Deletar registro", "Recuperar registro", "Voltar"};
    vector<void (controller::*)()> functions
        {&controller::actionReports, &controller::addRegister, &controller::editRegister, &controller::deleteRegister, &controller::recoverRegister};
    launchActions("REGISTROS", registers_Options, functions); 
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

void controller::actionReports(){
    vector<string> reports_Options
        {"Ordenar por nome", "Ordenar por ano", "Ordenar por serviço de streaming", "Ordenar por nota"};
    vector<void (controller::*)()> functions
        {&controller::OrderByName, &controller::OrderByReleaseYear, &controller::OrderByStreaming, &controller::OrderByScore};
    launchActions("RELATÓRIOS", reports_Options, functions);
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

void controller::addRegister(){
    string registerName;
    string registerMainCharacters;
    string registerMainPlot;
    string registerStreaming;
    int registerNumOfSeasons = 0;
    int registerEpisodesTotal;
    int registerReleaseYear = 0;
    float registerScore = 0;

    cout << "Adicionar um novo registro" << endl;

    cout << "Nome: ";
    getline(cin, registerName);

    cout << "Ano de lançamento: ";
    cin >> registerReleaseYear;
    cin.ignore();

    cout << "Temporadas: ";
    cin >> registerNumOfSeasons;
    cin.ignore();

    cout << "Episódios: ";
    cin >> registerEpisodesTotal;
    cin.ignore();

    cout << "Elenco principal: ";
    getline(cin, registerMainPlot);

    cout << "Personagens principais: ";
    getline(cin, registerMainCharacters);

    cout << "Nota: ";
    cin >> registerScore;
    cin.ignore();

    if (registerName.empty())
        cout << "Campo \"Nome\" está vazio. Abortando..." << endl;

    else if(!registerReleaseYear)
        cout << "Campo \"Ano de lançamento\" está vazio. Abortando..." << endl;

    else if (!registerNumOfSeasons)
        cout << "Campo \"Temporadas\" está vazio. Abortando..." << endl;

    else if (!registerEpisodesTotal)
        cout << "Campo \"Epidódios\" está vazio. Abortando..." << endl;

    else if (registerMainPlot.empty())
        cout << "Campo \"Elenco principal\" está vazio. Abortando..." << endl;

    else if (registerMainCharacters.empty())
        cout << "Campo \"Personagens principais\" está vazio. Abortando..." << endl;
    
    else if(!registerScore)
        cout << "Campo \"Nota\" está vazio. Abortando..." << endl;

    else
        registerDAO->addRegister(new Register(registerName, registerReleaseYear, registerNumOfSeasons, registerEpisodesTotal, 
                                registerMainPlot, registerMainCharacters, registerStreaming, registerScore));
}


void controller::editRegister(){
    int registerId = 0;
    cout << "Editar registro" << endl;

    cout << "Id do registro: ";
    cin >> registerId;
    cin.ignore();

    if (registerId > 0){
        Register *oldRegister = registerDAO->getRegisterById(registerId);
        
        if(oldRegister != NULL){
            string registerName;
            string registerMainCharacters;
            string registerMainPlot;
            string registerStreaming;
            int registerNumOfSeasons = 0;
            int registerEpisodesTotal;
            int registerReleaseYear = 0;
            float registerScore = 0;

            cout << "Dados atuais do registro:" << endl;
            cout << "Nome: " << oldRegister->getRegisterName() << endl;
            cout << "Ano de lançamento: " << oldRegister->getRegisterReleaseYear() << endl;
            cout << "Temporadas: " << oldRegister->getRegisterNumOfSeasons() << endl;
            cout << "Episódios: " << oldRegister->getRegisterEpisodesTotal() << endl;
            cout << "Elenco principal: " << oldRegister->getRegisterMainPlot() << endl;
            cout << "Personagens principais: " << oldRegister->getRegisterMainCharacters() << endl;
            cout << "Streaming: " << oldRegister->getRegisterStreaming() << endl;
            cout << "Nota: " << oldRegister->getRegisterScore() << endl;

            cout << "\nNovos dados (<Enter> para manter os dados):" << endl;
            cout << "Nome: ";
            getline(cin, registerName);

            cout << "Ano de lançamento: ";
            cin >> registerReleaseYear;
            cin.ignore();

            cout << "Temporadas: ";
            cin >> registerNumOfSeasons;
            cin.ignore();

            cout << "Episódios: ";
            cin >> registerEpisodesTotal;
            cin.ignore();

            cout << "Elenco principal: ";
            getline(cin, registerMainPlot);

            cout << "Personagens principais: ";
            getline(cin, registerMainCharacters);

            cout << "Nota: ";
            cin >> registerScore;
            cin.ignore();
            
            registerName = (registerName.empty()) ? oldRegister->getRegisterName() : registerName;
            registerReleaseYear = (!registerReleaseYear) ? oldRegister->getRegisterReleaseYear() : registerReleaseYear;
            registerNumOfSeasons = (!registerNumOfSeasons) ? oldRegister->getRegisterNumOfSeasons() : registerNumOfSeasons;
            registerEpisodesTotal = (!registerEpisodesTotal) ? oldRegister->getRegisterEpisodesTotal() : registerEpisodesTotal;
            registerMainPlot = (registerMainPlot.empty()) ? oldRegister->getRegisterMainPlot() : registerMainPlot;
            registerMainCharacters = (registerMainCharacters.empty()) ? oldRegister->getRegisterMainCharacters() : registerMainCharacters;
            registerStreaming = (registerStreaming.empty()) ? oldRegister->getRegisterStreaming() : registerStreaming;
            registerScore = (!registerScore) ? oldRegister->getRegisterScore() : registerScore;
        }
        else{
            cout << "Registro não encontrado. Operação cancelada." << endl;
        }
    }
    else{
        cout << "Id inválido. Operação cancelada." << endl;
    }
}

void controller::deleteRegister(){
    int registerId = 0;
    cout << "Deletar registro" << endl;
    cout << "Id do registro: " << endl;
    cin >> registerId;
    cin.ignore();

    if(registerId > 0){
        Register *oldRegister = registerDAO->getRegisterById(registerId);
        if (oldRegister != NULL){
            string choice;
            cout << "Dados do registro:" << endl;
            cout << "Nome: " << oldRegister->getRegisterName() << endl;
            cout << "Ano de lançamento: " << oldRegister->getRegisterReleaseYear() << endl;
            cout << "Temporadas: " << oldRegister->getRegisterNumOfSeasons() << endl;
            cout << "Episódios: " << oldRegister->getRegisterEpisodesTotal() << endl;
            cout << "Elenco principal: " << oldRegister->getRegisterMainPlot() << endl;
            cout << "Personagens principais: " << oldRegister->getRegisterMainCharacters() << endl;
            cout << "Streaming: " << oldRegister->getRegisterStreaming() << endl;
            cout << "Nota: " << oldRegister->getRegisterScore() << endl;

            cout << "(S) para deletar o registro\n"
                    "(N) para cancelar:" << endl;
            getline(cin, choice);

            if(toupper(choice.at(0)) == 'S'){
                registerDAO->deleteRegister(registerId);
            }

            lastRegisterDeleted = oldRegister;
        }
        else{
            cout << "Registro não encontrado. Operação cancelada." << endl;
        }
    }
    else{
        cout << "Id inválido. Operação cancelada." << endl;
    }
}

void controller::recoverRegister(){
    if (lastRegisterDeleted != NULL){
        cout << "Recuperando último registro apagado..." << endl;
        registerDAO->addRegister(lastRegisterDeleted);
    }
    else{
        cout << "Não há registros para se recuperar" << endl;
    }
}
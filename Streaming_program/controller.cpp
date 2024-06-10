#include "controller.h"
#include "utils.h"

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

controller::controller(DatabaseType dataBaseType){
    memoryDBConnection = NULL;
    serverDBConnection = NULL;

    switch(dataBaseType){
        case DatabaseType::MEMORY:
            {
            registerDAO = new registerMemDAO(new MemoryDBConnection());
            }

            break;

        case DatabaseType::MARIADB:
            {
            registerDAO = new registerServerDAO(new ServerDBConnection());
            }

            break;
    
    }

    registerDAO->addRegister(new Register("The Flash", 2014, 9, 184, "Grant Gustin, Danielle Panabaker, Stephen Amell", "Barry Allen, Iris West, Wally West, Vibro, Caitlin Snow", "Netflix", 7.5));
    registerDAO->addRegister(new Register("The Office", 2005, 9, 201, "Steve Carell, John Krasinski, Jenna Fischer", "Michael Scott, Dwigth Schrute, Pamela Weesly, Jim Halpert", "Netflix", 9));
    registerDAO->addRegister(new Register("Stranger Things", 2016, 4, 34, "Finn Wolfhard, Millie Bobby Brown, David Harbour", "Mike, Eleven, Dustin, Lucas, Will, Max", "Netflix", 8.7));
    registerDAO->addRegister(new Register("The Mandalorian", 2019, 3, 24, "Pedro Pascal, Giancarlo Exposito", "Mandalorian, Baby Yoda", "Disney+", 8.6));
    registerDAO->addRegister(new Register("The Boys", 2019, 4, 32, "Antony Starr, Karl Urban, Jack Quaid", "Billy Butcher, Homelander, Soldier Boy, Erin Moriarty", "Prime Video", 8.7));
};

controller::~controller(){
    delete registerDAO;
    registerDAO = NULL;
    delete memoryDBConnection;
    memoryDBConnection = NULL;
    delete serverDBConnection;
    serverDBConnection = NULL;
};

void controller::start(){
    vector<string> MainMenu_Options
        {"Registros", "Ajuda", "Créditos ", "Sair"};
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
    utils::clear();
    string helpMessage = "texto de ajuda\n";
    creditsAndHelp *help = new creditsAndHelp(helpMessage, "AJUDA");
    help->printMessage(help->getMessage());
    utils::clear();
}

void controller::actionCredits(){
    utils::clear();
    string creditsMessage = "Desenvolvido em 2024 por:\n"
                        "- Laura Gouveia Nunes\n"
                        "- Matheus Cirillo\n"
                        "- Marcos Vinicius Balestero\n"
                        "- Ori Kao Minohara\n"
                        "- Vitor Alves\n";
    creditsAndHelp *credits = new creditsAndHelp(creditsMessage, "CRÉDITOS");
    credits->printMessage(credits->getMessage());
    utils::clear();
}

void controller::actionReports(){
    vector<string> reports_Options
        {"Ordenar por nome", "Ordenar por ano", "Ordenar por serviço de streaming", "Ordenar por nota", "Voltar"};
    vector<void (controller::*)()> functions
        {&controller::OrderByName, &controller::OrderByReleaseYear, &controller::OrderByStreaming, &controller::OrderByScore};
    launchActions("RELATÓRIOS", reports_Options, functions);
}

void controller::launchActions(string title, vector<string> options, vector<void (controller::*)()> functions){
    try{
        utils::clear();
        Menu menu(options, title);
        while(int choice = menu.getOption()){
            if (choice == functions.size()+1){    
                if (menu.getTitle() == "REGISTROS") 
                    utils::clear();
                return;
            }   

            (this->*functions.at(choice - 1))();
        }
    }
    catch (const exception &myError){
        cout << "Um problema inesperado ocorreu. " << string(myError.what()); 
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

    cout << "Serviço de streaming: ";
    getline(cin, registerStreaming);

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

    else if (registerStreaming.empty())
        cout << "Campo \"Serviço de streaming\" está vazio. Abortando..." << endl;
    
    else if(!registerScore)
        cout << "Campo \"Nota\" está vazio. Abortando..." << endl;

    else{
        try{

            registerDAO->addRegister(new Register(registerName, registerReleaseYear, registerNumOfSeasons, registerEpisodesTotal, 
                                    registerMainPlot, registerMainCharacters, registerStreaming, registerScore));
            cout << "Registro adicionado com sucesso!" << endl;

        } catch(const exception &myError){
            cout << "Erro inesperado ao adicionar registro. " << myError.what() << endl;
        }
    }
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

            cout << "\nNovos dados (Pressione Enter para manter os dados de nomes ou digite 0 para manter os dados de referentes a números):" << endl;
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

            cout << "Serviço de streaming: ";
            getline(cin, registerStreaming);

            cout << "Nota: ";
            cin >> registerScore;
            cin.ignore();
            
        try{
            registerDAO->editRegister(oldRegister, registerName, registerReleaseYear, registerNumOfSeasons, registerEpisodesTotal,
                                    registerMainPlot, registerMainCharacters, registerStreaming, registerScore);

            cout << "Registro alterado com sucesso!" << endl;
        } 
        catch(const exception &myError){
            cout << "Error inesperado ao editar um registro. " << myError.what();
        }
        
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

        try{
            if(toupper(choice.at(0)) == 'S'){
            
                registerDAO->deleteRegister(registerId);
            }

            cout << "Registro deletado." << endl;
        }
        catch(const exception &myError){

            cout << "Erro inesperado ao deletar registro. " << endl;

        }

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
    if (registerDAO->getLastDeleted() != NULL) {
        cout << "Recuperando último registro deletado..." << endl;
        utils::sleepFunc(1);

        try{

            registerDAO->recoverRegister();
            cout << "Registro recuperado!" << endl;

        }
        catch(const exception &myError){

            cout << "Erro inesperado ao recuperar registro. " << myError.what() << endl; 
        
        }


    }
    else{

        cout << "Não há registros para se recuperar" << endl;

    } 

}

void controller::OrderByName(){
    vector<Register*> registersList = registerDAO->getAllRegisters();

    if (!registersList.empty()){

        sort(registersList.begin(), registersList.end(), [](Register* previousRegister, Register* nextRegister){
                                                              return ((previousRegister->getRegisterName()) < (nextRegister->getRegisterName())); 
                                                            }
                                                        ); 

            utils::printList(registersList);

    }
    else
        cout << "Não existem registros para serem listados." << endl;
}

void controller::OrderByReleaseYear(){
    vector<Register*> registersList = registerDAO->getAllRegisters();

    if (!registersList.empty()){ 
    
        int i, j;

        for (j = registersList.size()-1; j > 0; j--){

            for(i = 0; i < j; i++){

                if ((registersList.at(i)->getRegisterReleaseYear()) > registersList.at(i+1)->getRegisterReleaseYear()){
                    utils::functionToSwap(i, registersList);
                }

            }

        }

        utils::printList(registersList);

    }
    else
        cout << "Não existem registros para serem listados." << endl;
}

void controller::OrderByStreaming(){
    vector<Register*> registersList = registerDAO->getAllRegisters();

    if (!registersList.empty()){

        sort(registersList.begin(), registersList.end(), [](Register* previousRegister, Register* nextRegister){
                                                            return ((previousRegister->getRegisterStreaming()) < (nextRegister->getRegisterStreaming()));
                                                            }
                                                        );
        
        utils::printList(registersList);

    }
    else
        cout << "Não existem registros para serem listados." << endl;    
}

void controller::OrderByScore(){
    vector<Register*> registersList = registerDAO->getAllRegisters();
    if(!registersList.empty()){

        int i, j;

        for (j = registersList.size()-1; j > 0; j--){

            for(i = 0; i < j; i++){
                
                if ((registersList.at(i)->getRegisterScore()) < registersList.at(i+1)->getRegisterScore()){
                    utils::functionToSwap(i, registersList);
                }
            }

        }
        
        utils::printList(registersList);

    }
    else
        cout << "Não existem registros para serem listados." << endl;
}


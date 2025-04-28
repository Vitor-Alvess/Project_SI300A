#include "../include/controller/controller.h"
#include "../include/core/HttpServer.h"
#include <memory>

using namespace std;

int main(){
    Utils::init();
    Utils::sleepFunc(2);
    Utils::clear();

    int dbOption;

    cout << "Selecione o tipo de banco:\n[0] Memory | [1] Memory" << endl;
    cout << "Opcao: ";
    cin >> dbOption;
    cin.ignore();

    if (dbOption != 0 && dbOption != 1){
        cout << "Opcao invalida. Saindo..." << endl;
        exit(1);
    }

    vector<DatabaseType> databaseTypeMapping = {DatabaseType::MEMORY, DatabaseType::MARIADB};
    
    try{

        (make_unique<Controller>(databaseTypeMapping[dbOption])) -> start();

    }   
    catch (const exception &myError){

        cout << "Um erro inesperado ocorreu. Execução do programa cancelada." << myError.what();
        exit(1);

    }

    Utils::bye();
    Utils::sleepFunc(2);

    // HttpServer* server = new HttpServer();
    // server->startServer();

    return 0;
}
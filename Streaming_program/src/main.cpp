// para compilar: 
// g++ controller.cpp creditsAndHelp.cpp menu.cpp memoryDBConnection.cpp register.cpp registerMemDAO.cpp 
// serverDBConnection.cpp registerServerDAO.cpp utils.cpp main.cpp -o main.exe -lmariadbcpp

#include "../include/controller/controller.h"
#include <memory>

using namespace std;

int main(){
    Utils::init();
    Utils::sleepFunc(2);

    try{

        (make_unique<Controller>(DatabaseType::MEMORY)) -> start();

    }   
    catch (const exception &myError){

        cout << "Um erro inesperado ocorreu. Execução do programa cancelada." << myError.what();
        exit(1);

    }

    Utils::bye();
    Utils::sleepFunc(2);
    return 0;
}
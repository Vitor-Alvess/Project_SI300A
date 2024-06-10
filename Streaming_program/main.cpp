// para compilar: 
// g++ controller.cpp creditsAndHelp.cpp menu.cpp memoryDBConnection.cpp register.cpp registerMemDAO.cpp 
// serverDBConnection.cpp registerServerDAO.cpp utils.cpp main.cpp -o main.exe -lmariadbcpp

#include "controller.h"
#include<memory>

using namespace std;

int main(){
    utils::init();
    utils::sleepFunc(2);

    try{

        (make_unique<controller>(DatabaseType::MEMORY)) -> start();

    }   
    catch (const exception &myError){

        cout << "Um erro inesperado ocorreu. Execução do programa cancelada." << myError.what();
        exit(1);

    }

    utils::bye();
    utils::sleepFunc(2);
    return 0;
}
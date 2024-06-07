// para compilar: g++ controller.cpp creditsAndHelp.cpp menu.cpp memoryDBConnection.cpp register.cpp registerMemDAO.cpp utils.cpp main.cpp -o main.exe

#include "controller.h"


using namespace std;

int main(){
    utils::init();
    
    try{

        make_unique<controller>() -> start();

    }   
    catch (const exception &myError){

        cout << "Um erro inesperado ocorreu. Execução cancelada." << myError.what();
        exit(1);

    }

    utils::bye();
    return 0;
}
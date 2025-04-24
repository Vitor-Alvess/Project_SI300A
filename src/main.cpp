#include "../include/controller/controller.h"
#include <memory>

using namespace std;

int main(){
    Utils::init();
    Utils::sleepFunc(2);

    try{

        (make_unique<Controller>(DatabaseType::MARIADB)) -> start();

    }   
    catch (const exception &myError){

        cout << "Um erro inesperado ocorreu. Execução do programa cancelada." << myError.what();
        exit(1);

    }

    Utils::bye();
    Utils::sleepFunc(2);
    return 0;
}
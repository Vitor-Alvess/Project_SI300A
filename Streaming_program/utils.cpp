#include "utils.h"

void utils::functionToSwap(int i, vector<Register*> &list){
    string auxStr;
    int auxInt;
    float auxFloat;

    auxInt = list.at(i)->getRegisterId();
    list.at(i)->setRegisterId(list.at(i+1)->getRegisterId());
    list.at(i+1)->setRegisterId(auxInt);

    auxStr = list.at(i)->getRegisterName();
    list.at(i)->setRegisterName(list.at(i+1)->getRegisterName());
    list.at(i+1)->setRegisterName(auxStr);

    auxInt = list.at(i)->getRegisterReleaseYear();
    list.at(i)->setRegisterReleaseYear(list.at(i+1)->getRegisterReleaseYear());
    list.at(i+1)->setRegisterReleaseYear(auxInt);

    auxInt = list.at(i)->getRegisterNumOfSeasons();
    list.at(i)->setRegisterNumOfSeasons(list.at(i+1)->getRegisterNumOfSeasons());
    list.at(i+1)->setRegisterNumOfSeasons(auxInt);

    auxInt = list.at(i)->getRegisterEpisodesTotal();
    list.at(i)->setRegisterEpisodesTotal(list.at(i+1)->getRegisterEpisodesTotal());
    list.at(i+1)->setRegisterEpisodesTotal(auxInt);

    auxStr = list.at(i)->getRegisterMainPlot();
    list.at(i)->setRegisterMainPlot(list.at(i+1)->getRegisterMainPlot());
    list.at(i+1)->setRegisterMainPlot(auxStr);

    auxStr = list.at(i)->getRegisterMainCharacters();
    list.at(i)->setRegisterMainCharacters(list.at(i+1)->getRegisterMainCharacters());
    list.at(i+1)->setRegisterMainCharacters(auxStr);

    auxStr = list.at(i)->getRegisterStreaming();
    list.at(i)->setRegisterStreaming(list.at(i+1)->getRegisterStreaming());
    list.at(i+1)->setRegisterStreaming(auxStr);

    auxFloat = list.at(i)->getRegisterScore();
    list.at(i)->setRegisterScore(list.at(i+1)->getRegisterScore());
    list.at(i+1)->setRegisterScore(auxFloat);
}

void utils::printList(vector<Register*> &list){
    for (Register *buffer : list){
        cout << right << setfill('0') << setw(6) << buffer->getRegisterId() << " | ";
        cout << left << setfill('.') << setw(50) << buffer->getRegisterName() << " | "<< endl;
    }
}

void utils::bye(){
    cout << "Encerrando..." << endl;
}

void utils::init(){
    cout << "Iniciando..." << endl;
}

void utils::clear(){
    if (IS_WINDOWS)
        system("cls");
    else
        system("clear");
}

void utils::pause(){
    if (IS_WINDOWS) {
        system("pause");
    } else {
        system("read -p \"\nPressione a tecla enter para continuar...\" saindo");
    }
}
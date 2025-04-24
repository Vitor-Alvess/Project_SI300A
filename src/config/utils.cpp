#include "../../include/config/utils.h"

void Utils::functionToSwap(int i, vector<Register*> &list){
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

void Utils::listHeader(){
    cout << left << setfill(' ') << setw(6) << "ID" << " | ";
    cout << left << setfill(' ') << setw(20) << "NOME" << " | ";
    cout << left << setfill(' ') << setw(4) << "ANO" << " | ";
    cout << left << setfill(' ') << setw(4) << "TEMP" << " | ";
    cout << left << setfill(' ') << setw(3) << "EP" << " | ";
    cout << left << setfill(' ') << setw(60) << "ELENCO PRNCIPAL" << " | ";
    cout << left << setfill(' ') << setw(60) << "PERSONAGENS PRINCIPAIS" << " | ";
    cout << left << setfill(' ') << setw(15) << "STREAMING" << " | ";
    cout << left << setfill(' ') << setw(4) << "NOTA" << " | " << endl;
    
}

void Utils::printList(vector<Register*> &list){
    cout << endl;
    listHeader();
    for (Register *buffer : list){
        cout << right << setfill('0') << setw(6) << buffer->getRegisterId() << " | ";
        cout << left << setfill('.') << setw(20) << buffer->getRegisterName() << " | ";
        cout << buffer->getRegisterReleaseYear() << " | ";
        cout << setfill(' ') << setw(4) << buffer->getRegisterNumOfSeasons() << " | ";
        cout << setfill(' ') << setw(3) << buffer->getRegisterEpisodesTotal() << " | ";
        cout << setfill('.') << setw(60) << buffer->getRegisterMainPlot() << " | ";
        cout << setfill('.') << setw(60) << buffer->getRegisterMainCharacters() << " | ";
        cout << setfill('.') << setw(15) << buffer->getRegisterStreaming() << " | ";
        cout << setfill(' ') << setw(4) << setprecision(1) << fixed << buffer->getRegisterScore() << " | " << endl;
    }
}

void Utils::sleepFunc(unsigned int seconds){
    (IS_WINDOWS) ? sleep(seconds) : usleep(seconds*1000000);
}

void Utils::bye(){
    cout << "Encerrando..." << endl;
}

void Utils::init(){
    cout << "Iniciando..." << endl;
}

void Utils::clear(){
    if (IS_WINDOWS)
        system("cls");
    else
        system("clear");
}

void Utils::pause(){
    if (IS_WINDOWS) {
        system("pause");
    } else {
        system("read -p \"\nPressione a tecla enter para voltar...\" saindo");
    }
}
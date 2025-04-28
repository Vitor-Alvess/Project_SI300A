#include "../../include/model/register.h"

using namespace std;

int Register::lastId = 0;

Register::Register(int id, string name, int releaseYear, int NumOfSeasons, int episodesTotal,
                string mainPlot, string mainCharacters, string streaming, float score):
                id(id), name(name), releaseYear(releaseYear), NumOfSeasons(NumOfSeasons), episodesTotal(episodesTotal), mainPlot(mainPlot),
                mainCharacters(mainCharacters), streaming(streaming), score(score){}

Register::Register(string name, int releaseYear, int NumOfSeasons, int episodesTotal,
                string mainPlot, string mainCharacters, string streaming, float score):
                name(name), releaseYear(releaseYear), NumOfSeasons(NumOfSeasons), episodesTotal(episodesTotal), mainPlot(mainPlot),
                mainCharacters(mainCharacters), streaming(streaming), score(score){
                    this->id = ++lastId;
                }
                
Register::Register(Register* r){
    setRegisterName(r->getRegisterName());
    setRegisterReleaseYear(r->getRegisterReleaseYear());
    setRegisterNumOfSeasons(r->getRegisterNumOfSeasons());
    setRegisterEpisodesTotal(r->getRegisterEpisodesTotal());
    setRegisterMainPlot(r->getRegisterMainPlot());
    setRegisterMainCharacters(r->getRegisterMainCharacters());
    setRegisterStreaming(r->getRegisterStreaming());
    setRegisterScore(r->getRegisterScore());
    this->id = ++lastId;
}

Register::Register(int id, Register* r){
    setRegisterName(r->getRegisterName());
    setRegisterReleaseYear(r->getRegisterReleaseYear());
    setRegisterNumOfSeasons(r->getRegisterNumOfSeasons());
    setRegisterEpisodesTotal(r->getRegisterEpisodesTotal());
    setRegisterMainPlot(r->getRegisterMainPlot());
    setRegisterMainCharacters(r->getRegisterMainCharacters());
    setRegisterStreaming(r->getRegisterStreaming());
    setRegisterScore(r->getRegisterScore());
    this->id = id;
}

Register::~Register(){}

int Register::getRegisterId() const{
    return id;
}

string Register::getRegisterName() const{
    return name;
}

int Register::getRegisterReleaseYear() const{
    return releaseYear;
}

int Register::getRegisterNumOfSeasons() const{
    return NumOfSeasons;
}

int Register::getRegisterEpisodesTotal() const{
    return episodesTotal;
}

string Register::getRegisterMainPlot() const{
    return mainPlot;
}

string Register::getRegisterMainCharacters() const{
    return mainCharacters;
}

string Register::getRegisterStreaming() const{
    return streaming;
}

float Register::getRegisterScore() const{
    return score;
}

void Register::setRegisterId(int id){
    this->id = id;
}

void Register::setRegisterName(string name){
    this->name = name;
}

void Register::setRegisterReleaseYear(int releaseYear){
    this->releaseYear = releaseYear;
}

void Register::setRegisterNumOfSeasons(int NumOfSeasons){
    this->NumOfSeasons = NumOfSeasons;
}

void Register::setRegisterEpisodesTotal(int episodesTotal){
    this->episodesTotal = episodesTotal;
}

void Register::setRegisterMainPlot(string mainPlot){
    this->mainPlot = mainPlot;
}

void Register::setRegisterMainCharacters(string mainCharacters){
    this->mainCharacters = mainCharacters;
}

void Register::setRegisterStreaming(string streaming){
    this->streaming = streaming;
}

void Register::setRegisterScore(float score){
    this->score = score;
}

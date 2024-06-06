#include "register.h"
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
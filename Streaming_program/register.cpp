#include "register.h"

Register::Register(int id, string name, int releaseYear, int NumOfSeasons, int episodesTotal,
                string mainPlot, string mainCharacters, string streaming, float score):
                id(id), name(name), releaseYear(releaseYear), NumOfSeasons(NumOfSeasons), episodesTotal(episodesTotal), mainPlot(mainPlot),
                mainCharacters(mainCharacters), streaming(streaming), score(score){}

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

string Register::getRegisterMainPlot() const{
    return mainPlot;
}

string Register::getRegisterStreaming() const{
    return streaming;
}
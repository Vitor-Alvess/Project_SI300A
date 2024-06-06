#ifndef REGISTER_H_
#define REGISTER_H_


#include <iostream>

using namespace std;

class Register{
    private:
        int id;       
        int NumOfSeasons;
        int episodesTotal;
        string mainCharacters;
    public:
        string name;
        int releaseYear;
        string mainPlot;
        string streaming;
        float score;
        Register(int id, string name, int releaseYear, int NumOfSeasons, int episodesTotal,
                string mainPlot, string mainCharacters, string streaming, float score);

        int getRegisterId() const;
        string getRegisterName() const;
        int getRegisterReleaseYear() const;
        string getRegisterMainPlot() const;
        string getRegisterStreaming() const;

        virtual ~Register();
};

#endif
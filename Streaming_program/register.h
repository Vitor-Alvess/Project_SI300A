#ifndef REGISTER_H_
#define REGISTER_H_


#include <iostream>

using namespace std;

class Register{
    private:
        static int lastId;
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

        Register(string name, int releaseYear, int NumOfSeasons, int episodesTotal,
                string mainPlot, string mainCharacters, string streaming, float score);

        int getRegisterId() const;
        string getRegisterName() const;
        int getRegisterReleaseYear() const;
        int getRegisterNumOfSeasons() const;
        int getRegisterEpisodesTotal() const;
        string getRegisterMainPlot() const;
        string getRegisterMainCharacters() const;
        string getRegisterStreaming() const;
        float getRegisterScore() const;

        void setRegisterId(int id);
        void setRegisterName(string name);
        void setRegisterReleaseYear(int releaseYear);
        void setRegisterNumOfSeasons(int numOfSeasons);
        void setRegisterEpisodesTotal(int episodesTotal);
        void setRegisterMainPlot(string mainPlot);
        void setRegisterMainCharacters(string mainCharacters);
        void setRegisterStreaming(string streaming);
        void setRegisterScore(float score);

        virtual ~Register();
};

#endif
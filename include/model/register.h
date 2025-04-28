#ifndef REGISTER_H_
#define REGISTER_H_


#include <iostream>

class Register{
    private:
        static int lastId;
        int id;       
        int NumOfSeasons;
        int episodesTotal;
        std::string mainCharacters;
        std::string name;
        int releaseYear;
        std::string mainPlot;
        std::string streaming;
        float score;
        
    public:

        Register(int id, std::string name, int releaseYear, int NumOfSeasons, int episodesTotal,
                std::string mainPlot, std::string mainCharacters, std::string streaming, float score);

        Register(std::string name, int releaseYear, int NumOfSeasons, int episodesTotal,
                std::string mainPlot, std::string mainCharacters, std::string streaming, float score);
        
        Register(Register* r);

        Register(int id, Register* r);

        int getRegisterId() const;
        std::string getRegisterName() const;
        int getRegisterReleaseYear() const;
        int getRegisterNumOfSeasons() const;
        int getRegisterEpisodesTotal() const;
        std::string getRegisterMainPlot() const;
        std::string getRegisterMainCharacters() const;
        std::string getRegisterStreaming() const;
        float getRegisterScore() const;

        void setRegisterId(int id);
        void setRegisterName(std::string name);
        void setRegisterReleaseYear(int releaseYear);
        void setRegisterNumOfSeasons(int numOfSeasons);
        void setRegisterEpisodesTotal(int episodesTotal);
        void setRegisterMainPlot(std::string mainPlot);
        void setRegisterMainCharacters(std::string mainCharacters);
        void setRegisterStreaming(std::string streaming);
        void setRegisterScore(float score);

        virtual ~Register();
};

#endif
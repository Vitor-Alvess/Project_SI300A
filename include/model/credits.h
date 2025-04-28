#include "menu.h"
#include <vector>

class credits: public Menu{
    private:
        std::string message;
        void setMessage(std::string message);
    public:
        credits(std::vector<std::string> &options, std::string title, std::string choice_msg = "Pressione qualquer tecla...");
        std::string getMessage();
        void printMessage(std::string message);
        virtual ~credits();
};
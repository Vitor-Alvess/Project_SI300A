#include "menu.h"
#include <vector>

using namespace std;

class credits: public Menu{
    private:
        string message;
        void setMessage(string message);
    public:
        credits(vector<string> &options, string title, string choice_msg = "Pressione qualquer tecla...");
        string getMessage();
        void printMessage(string message);
        virtual ~credits();
};
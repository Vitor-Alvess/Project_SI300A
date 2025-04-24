#include "menu.h"
#include <vector>
using namespace std;

class mainMenu: public Menu{
    private:
        string message;
        bool firstWelcome;
        void setMessage(string message);
    public:
        mainMenu(vector<string> &options, string title, string choice_msg = "Opcao: ");
        virtual ~mainMenu();
        string getMessage();
        void printMessage(string message, bool firstWelcome);
};

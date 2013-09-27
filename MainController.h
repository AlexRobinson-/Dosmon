#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <string>
#include <vector>

/*  */
#include "User.h"
#include "Controller.h"

class MainController: public Controller
{
    public:
        /* CON/DECON */
        MainController();
        ~MainController();

        std::string performAction(std::string = "Main", std::string = "null");
        std::string mainMenu();

        void setUpController(User*);
        void startController(std::string = "Main");
    protected:
    private:
        void loadMenus();
        std::vector<std::string> mainMenuActions;
};

#endif // MAINCONTROLLER_H

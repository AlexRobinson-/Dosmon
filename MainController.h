#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <string>

/*  */
#include "User.h"
#include "Controller.h"

class MainController: public Controller
{
    public:
        /* CON/DECON */
        MainController();
        ~MainController();

        std::string performAction(std::string = "Main", std::string = "Main");
        std::string mainMenu();

        void setUpController(User*);
        void startController(std::string = "Main");
    protected:
    private:
};

#endif // MAINCONTROLLER_H

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
        MainController(User*, std::string = "Main");
        MainController(std::string = "Main");
        ~MainController();

        void performAction(std::string = "Main");
        void mainMenu();
    protected:
    private:
};

#endif // MAINCONTROLLER_H

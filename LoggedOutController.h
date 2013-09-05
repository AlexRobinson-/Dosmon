#ifndef LOGGEDOUTCONTROLLER_H
#define LOGGEDOUTCONTROLLER_H

#include <string>

#include "Controller.h"

class LoggedOutController: public Controller
{
    public:
        /* CON/DECON */
        LoggedOutController(std::string = "Main");
        virtual ~LoggedOutController();

        void performAction(std::string = "Main");
        void mainMenu();

        void createAccount();
        void loginScreen();
    protected:
    private:
};

#endif // LOGGEDOUTCONTROLLER_H

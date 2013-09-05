#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <string>

#include "User.h"
#include "MainController.h"

class AccountController: public Controller
{
    public:
        /* CON/DECON */
        AccountController(User*, std::string = "Main");
        virtual ~AccountController();
        void performAction(std::string = "Main");
        void mainMenu();
    protected:
    private:
};

#endif // ACCOUNTCONTROLLER_H

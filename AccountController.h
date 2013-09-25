#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <string>

#include "User.h"
#include "MainController.h"

class AccountController: public Controller
{
    public:
        /* CON/DECON */
        AccountController();
        virtual ~AccountController();

        /* METHODS */
        void setUpController(User*);
        void startController(std::string = "Main");
        std::string performAction(std::string = "Main", std::string = "Main");
        std::string mainMenu();
        void changeUsername();
        void changePassword();
        void changeMonsterName();
    protected:
    private:
};

#endif // ACCOUNTCONTROLLER_H

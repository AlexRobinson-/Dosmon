#ifndef LOGGEDOUTCONTROLLER_H
#define LOGGEDOUTCONTROLLER_H

#include <string>

#include "Controller.h"

class User;
class UserMonster;
class LoggedOutView;

class LoggedOutController: public Controller
{
    public:
        /* CON/DECON */
        LoggedOutController(User*);
        virtual ~LoggedOutController();

        std::string performAction(std::string = "Main");
        std::string mainMenu();

        std::string createAccount();
        std::string loginScreen();

        void setUpController();
        void startController(std::string = "Main");
    protected:
    private:
        std::string nextScreen = "Main";
        User* user;
        UserMonster* userMonster;
        User tmpUser;
        LoggedOutView* loggedOutView;
};

#endif // LOGGEDOUTCONTROLLER_H

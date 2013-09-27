#ifndef LOGGEDOUTCONTROLLER_H
#define LOGGEDOUTCONTROLLER_H

#include <string>
#include <vector>

#include "Controller.h"

class User;
class UserMonster;
class LoggedOutView;

class LoggedOutController: public Controller
{
    public:
        /* CON/DECON */
        LoggedOutController();
        virtual ~LoggedOutController();

        /* CONTROLLER METHODS */
        std::string performAction(std::string = "Main", std::string = "null");
        std::string mainMenu();
        void setUpController(User*);
        void startController(std::string = "Main");

        /* METHODS */
        std::string createAccount();
        std::string loginScreen();

    protected:
    private:
        /* CONTROLLER METHODS */
        void loadMenus();

        /* ATTRIBUTES */
        std::string nextScreen = "Main";
        std::vector<std::string> mainMenuActions;
        User* user;
        UserMonster* userMonster;
        User tmpUser;
        LoggedOutView* loggedOutView;
};

#endif // LOGGEDOUTCONTROLLER_H

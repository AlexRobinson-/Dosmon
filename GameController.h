#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <string>

class MainController;
class LoggedOutController;
class AccountController;
class BattleController;
class User;

class GameController
{
    public:
        /* CON/DECON */
        GameController(User*);
        virtual ~GameController();

        /* METHODS */
        bool loadScreen(std::string);

    protected:
    private:

        /* METHODS */
        void destroyPrevious();
        int getScreenId(std::string);
        void loadScreen(int);
        void run();

        /* CONTROLLER METHODS */
        std::string loadMainController();
        std::string loadLoggedOutController();
        std::string loadAccountController();
        std::string loadBattleController();

        /* ATTRIBUTES */
        int currentScreen;
        int loadingScreen;

        User* user;

        MainController* mainController;
        LoggedOutController* loggedOutController;
        AccountController* accountController;
        BattleController* battleController;
};

#endif // GAMECONTROLLER_H

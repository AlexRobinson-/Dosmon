#include "GameController.h"

/* CONTROLLERS */
#include "MainController.h"
#include "LoggedOutController.h"
#include "AccountController.h"
#include "BattleController.h"

#include <array>
#include <string>
#include <algorithm>

#include <iostream>

using namespace std;

/* CON/DECON */

GameController::GameController(User* user)
{
    this->user = user;
    cout << "in game controller " << this->user->getUsername() << endl;
}

GameController::~GameController()
{
    //dtor
}

/* METHODS */

void GameController::run()
{
    bool running = true;
    while(running)
    {
        destroyPrevious();
        loadScreen(0);
    }
}

bool GameController::loadScreen(string screen)
{
    int screenId = getScreenId(screen);

    if(screenId == -1)
    {
        return false;
    }else
    {
        loadingScreen = screenId;
    }
    destroyPrevious();
    loadScreen(screenId);
    return true;
}

/* PRIVATE METHODS */

int GameController::getScreenId(string screenName)
{
    /*
        0       Main
        1       Logged out
        2       Account
        3       Battle
    */
    cout << "Trying to load " << screenName << endl;
    string screens[4] = {"main", "loggedOut", "account", "battle"};
    for(int counter = 0; counter < (sizeof(screens) / sizeof(int)); counter++)
    {
        if(screens[counter] == screenName)
        {
            cout << "Found at position " << counter << endl;
            return counter;
        }
    }
    return -1;
}

void GameController::loadScreen(int screenId)
{
    /*
        0       Main
        1       Logged out
        2       Account
        3       Battle
    */
    currentScreen = loadingScreen;
    string nextScreen = "";

    switch(screenId)
    {
    case 0:
        nextScreen = loadMainController();
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }

    loadingScreen = getScreenId(nextScreen);
}

string GameController::loadMainController()
{
    MainController tmpController;
    mainController = &tmpController;
    tmpController.setUpController(user);
    tmpController.startController();
    return "";
//    return tmpController.startController();
}


/*
void GameController::loadAccountController()
{
    AccountController tmpController;
    accountController = &tmpController;
    tmpController.setUpController();
    tmpController.startController();
}
*/


void GameController::destroyPrevious()
{
    /*
        0       Main
        1       Logged out
        2       Account
        3       Battle
    */
    /*
    switch(screenId)
    {
    case 0:
        loadMainController();
        break;
    case 1:
        cout << "About to load" << endl;
        loadLoggedOutController();
        break;
    case 2:
        break;
    case 3:
        break;

    }
    */
}

#include "AccountController.h"
using namespace std;
#include <iostream>

/* MODELS */
#include "User.h"

/* CONTROLLERS */
#include "MainController.h"

/* VIEWS */
#include "BasicView.h"

/* CON/DECON */

AccountController::AccountController()
{

}

AccountController::~AccountController()
{
    //dtor
}

/* METHODS */
void AccountController::setUpController(User* userObject)
{
    this->user = userObject;
}

void AccountController::startController(string nextScreen)
{
    bool onScreen = true;
    while(onScreen == true)
    {
        nextScreen = performAction(nextScreen);
        if(nextScreen == "Back")
        {
            onScreen = false;
        }
    }
}

string AccountController::performAction(string action, string nextScreen)
{
    if(action == "Main")
    {
        nextScreen = mainMenu();
    }else if(action == "Change name")
    {
        changeUsername();
    }else if(action == "Change password")
    {
        changePassword();
    }else if(action == "Change monster name")
    {
        changeMonsterName();
    }
    user->save();
    return nextScreen;
}

string AccountController::mainMenu()
{
    BasicView basicView;
    basicView.assignRefToUser(this->user);
    basicView.setTitle("Account");

    vector<string> actions(4);
    actions.at(0) = "Change name";
    actions.at(1) = "Change password";
    actions.at(2) = "Change monster name";
    actions.at(3) = "Back";
    basicView.setActions(actions);

    basicView.loadBasic();

    int userinput;
    userinput = requestInput("Please enter in some stuff: ");
    return basicView.getActions().at(userinput);
}

void AccountController::changeUsername()
{
    string username = requestStringInput("Please enter your new name: ");
    user->setName(username);
}

void AccountController::changePassword()
{
    string password = requestStringInput("Please enter your new password: ");
    user->setPassword(password);
}

void AccountController::changeMonsterName()
{
    string monsterName = requestStringInput("Please enter a new name for your monster: ");
    user->getMonster()->setMonsterName(monsterName);
}

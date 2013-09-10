#include "AccountController.h"

#include <iostream>

/* MODELS */
#include "User.h"

/* CONTROLLERS */
#include "MainController.h"

/* VIEWS */
#include "BasicView.h"

using namespace std;

AccountController::AccountController(User* userObject, string action)
{
    this->user = userObject;
    performAction(action);
}

AccountController::~AccountController()
{
    //dtor
}

void AccountController::performAction(string action)
{
    if(action == "Main")
    {
        mainMenu();
    }else if(action == "Account")
    {

    }else if(action == "Logout")
    {
        cout << "Logged out" << endl;
    }else if(action == "Back")
    {
        MainController mainController(this->user);
    }
}

void AccountController::mainMenu()
{
    BasicView basicView;
    basicView.assignRefToUser(this->user);
    basicView.setTitle("Account");

    vector<string> actions(3);
    actions.at(0) = "Change username";
    actions.at(1) = "Change password";
    actions.at(2) = "Back";
    basicView.setActions(actions);

    basicView.load();

    int userinput;
    userinput = requestInput("Please enter in some stuff: ");
    performAction(basicView.getActions().at(userinput));
}

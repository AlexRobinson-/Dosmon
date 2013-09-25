#include "LoggedOutController.h"
#include <string>
#include <iostream>

/* CONTROLLERS */
#include "MainController.h"

/* VIEWS */
#include "LoggedOutView.h"

/* HELPERS */
#include "UserAttributeHelper.h"

/* MODELS */
#include "UserMonster.h"
#include "User.h"

using namespace std;

/* CON/DECON */
LoggedOutController::LoggedOutController(User* user)
{
    this->user = user;
}

LoggedOutController::~LoggedOutController()
{
    //dtor
}

/* SET UP METHODS */

void LoggedOutController::startController(string action)
{
    LoggedOutView loggedOutView;
    this->loggedOutView = &loggedOutView;
    bool loggedOut = true;
    while(loggedOut)
    {
        nextScreen = performAction(nextScreen);
        if(nextScreen == "loggedIn")
        {
            loggedOut = false;
        }
    }
}

string LoggedOutController::performAction(string action)
{
    if(action == "Main") // Displays main menu
    {
        return mainMenu();
    }else if(action == "Login")
    {
        return loginScreen();
    }else if(action == "Create account")
    {
       return createAccount();
    }
    else if(action == "Forgot Password") // Open account page
    {
       // forgotPassword();
    }
    else if(action == "Close")
    {
        cout << "" << endl;
        delete this;
    }
}

string LoggedOutController::mainMenu()
{
    loggedOutView->setTitle("Dosmon V1.0 BETA"); // Set the title of the screen

    /* MENU */
    vector<string> actions(4);
    actions.at(0) = "Login";
    actions.at(1) = "Create account";
    actions.at(2) = "Forgot password";
    actions.at(3) = "Close";
    loggedOutView->setActions(actions); // Set the actions of the screen

    loggedOutView->load(); // Display the screen to the page

    int userinput;
    userinput = requestInput("Please enter in some stuff: ", actions.size()); // Get input (menu option) from the user
    return loggedOutView->getActions().at(userinput);
}

string LoggedOutController::createAccount()
{
    bool nameSet = false;
    bool passSet = false;

    string username = requestStringInput("Please enter your username: ");
    string password = requestStringInput("Please enter your password: ");
    string name = requestStringInput("Please enter your name: ");
    string monsterName = requestStringInput("Please choose a name for your monster: ");

    this->user->setUsername(username);
    this->user->setName(name);
    this->user->setPassword(password);

    this->user->getMonster()->setLevel(1, false);
    this->user->getMonster()->setHealth(this->user->getMonster()->getMaxHealth());
    this->user->getMonster()->setAttack(1);
    this->user->getMonster()->setStatPoints(5, false);
    this->user->getMonster()->setExperience(0, false);
    this->user->setCoins(5, false);
    this->user->getMonster()->setMonsterName(monsterName);

    this->user->save();
    loggedOutView->printWelcomeMessage(user);

    return "loggedIn";
}

string LoggedOutController::loginScreen()
{
    string username = requestStringInput("Please enter your username: ");
    string password = requestStringInput("Please enter your password: ");

    if(this->user->attemptLogin(username, password))
    {
        return "loggedIn";
    }else
    {
        cout << "Incorrect details" << endl;
        return "Main";
    }

}

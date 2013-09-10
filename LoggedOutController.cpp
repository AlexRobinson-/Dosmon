#include "LoggedOutController.h"
#include <string>
#include <iostream>

/* CONTROLLERS */
#include "MainController.h"
#include "UserMonster.h"

/* VIEWS */
#include "LoggedOutView.h"

/* HELPERS */
#include "UserAttributeHelper.h"

using namespace std;

/* CON/DECON */
LoggedOutController::LoggedOutController(string action)
{
    performAction(action);
}

LoggedOutController::~LoggedOutController()
{
    //dtor
}

void LoggedOutController::performAction(string action)
{
    if(action == "Main") // Displays main menu
    {
        mainMenu();
    }else if(action == "Login")
    {
        loginScreen();
    }else if(action == "Create account")
    {
       createAccount();
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

void LoggedOutController::mainMenu()
{
    LoggedOutView loggedOutView;
    loggedOutView.setTitle("Dosmon V1.0 BETA"); // Set the title of the screen

    /* MENU */
    vector<string> actions(4);
    actions.at(0) = "Login";
    actions.at(1) = "Create account";
    actions.at(2) = "Forgot password";
    actions.at(3) = "Close";
    loggedOutView.setActions(actions); // Set the actions of the screen

    loggedOutView.load(); // Display the screen to the page

    int userinput;
    userinput = requestInput("Please enter in some stuff: "); // Get input (menu option) from the user
    performAction(loggedOutView.getActions().at(userinput)); // Open the menu that the user requested
}

void LoggedOutController::createAccount()
{
    bool nameSet = false;
    bool passSet = false;

    string username = requestStringInput("Please enter your username: ");
    string password = requestStringInput("Please enter your password: ");

    User user;
    user.setUsername(username);
    user.setPassword(password);
    UserMonster monster;
    user.setMonster(&monster);

    user.getMonster()->setLevel(1);
    user.getMonster()->setMaxHealth(UserAttributeHelper::calculateMaxHealth(1));
    user.getMonster()->setHealth(user.getMonster()->getMaxHealth());
    user.getMonster()->setAttack(1);
    user.getMonster()->setStatPoints(5);
    user.getMonster()->setExperience(0);
    user.getMonster()->setMaxExperience(UserAttributeHelper::calculateMaxHealth(1));

    user.save();

    cout << "***********************" << endl;
    cout << "** WELCOME TO DOSMON **" << endl;
    cout << "***********************" << endl << endl;
    cout << "Username:      " << user.getUsername() << endl;
    cout << "Password:      " << user.getPassword() << endl;
    cout << "Level:         " << user.getMonster()->getLevel() << endl;
    cout << "Health:        " << user.getMonster()->getHealth() << " / " << user.getMonster()->getMaxHealth() << endl;
    cout << "Attack:        " << user.getMonster()->getAttack() << endl;
    cout << "Stat points:   " << user.getMonster()->getStatPoints() << endl;

    MainController mainController = MainController(&user);
}

void LoggedOutController::loginScreen()
{
    string username = requestStringInput("Please enter your username: ");
    string password = requestStringInput("Please enter your password: ");

    User user;
    UserMonster monster;
    user.setMonster(&monster);
    if(user.attemptLogin(username, password))
    {
        MainController mainController = MainController(&user);
    }else
    {
        cout << "Incorrect details" << endl;
        mainMenu();
    }


}

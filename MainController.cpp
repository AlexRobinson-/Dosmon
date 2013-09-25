// Header file
#include "MainController.h"

// Standard C++ includes
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* MODELS */
#include "User.h"
#include "AIMonster.h"
#include "AIMonsterGenerator.h"

/* VIEWS */
#include "BasicView.h"

/* CONTROLLERS */
#include "AccountController.h"
#include "LoggedOutController.h"
#include "BattleController.h"
#include "ShopController.h"

using namespace std;

/* CON/DECON */

/**
MainController constructor
default action = menu

*/
MainController::MainController()
{

}

MainController::~MainController()
{
    //dtor
}

/* SET UP METHODS */

void MainController::setUpController(User* userObject)
{
    this->user = userObject;
}

void MainController::startController(string nextScreen)
{
    bool loggedIn = true;
    while(loggedIn)
    {
        nextScreen = performAction(nextScreen);
        if(nextScreen == "Logout")
        {
            loggedIn = false;
        }else
        {
            cout << "loggedIn = true" << endl;
        }
    }
}

/* METHODS */

string MainController::performAction(string action, string nextScreen)
{
    if(action == "Main") // Displays main menu
    {
        nextScreen = mainMenu();
    }else if(action == "Battle")
    {
       AIMonster aiMonster;
       AIMonsterGenerator::generateMonster(&aiMonster, this->user->getMonster());
       BattleController bcontroller(user, &aiMonster);
    }else if(action == "Items")
    {
        cout << endl;/* List current items and give option to use them */
    }
    else if(action == "Account") // Open account page
    {
        AccountController accountController;
        accountController.setUpController(this->user);
        accountController.startController();
    }
    else if(action == "Points")
    {
        /* Lists player points and gives the option to use them */
    }
    else if(action == "Revive")
    {
        /* Might take this out, will revive a monster if the monster has fainted */
        cout << "Reciving monster" << endl;
        user->getMonster()->setHealth(user->getMonster()->getMaxHealth());
    }
     else if(action == "Shop")
    {
        ShopController shopController;
        shopController.setUpController(user);
        shopController.startController();
    }
    user->save();
    return nextScreen;
}

string MainController::mainMenu()
{
    BasicView basicView;
    basicView.assignRefToUser(this->user); // Give BasicView access to the user object
    basicView.setTitle("Main Menu"); // Set the title of the screen

    /* MENU */
    vector<string> actions(7);
    actions.at(0) = "Battle";
    actions.at(1) = "Items";
    actions.at(2) = "Account";
    actions.at(3) = "Points";
    actions.at(4) = "Revive";
    actions.at(5) = "Shop";
    actions.at(6) = "Logout";
    basicView.setActions(actions); // Set the actions of the screen

    basicView.loadBasic(); // Display the screen to the page

    int userinput;
    userinput = requestInput("Please enter in some stuff: ", 7); // Get input (menu option) from the user

    return basicView.getActions().at(userinput); // Return the menu that the user requested
}

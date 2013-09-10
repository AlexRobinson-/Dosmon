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

using namespace std;

/**
MainController constructor
default action = menu

*/
MainController::MainController(User* userObject, string action)
{
    this->user = userObject;
    performAction(action);
}

MainController::~MainController()
{
    //dtor
}

void MainController::performAction(string action)
{
    if(action == "Main") // Displays main menu
    {
        mainMenu();
    }else if(action == "Battle")
    {
        /* May need to create a monster to battle, or tell BattleController to and initiate battle */
        //BattleController battleController;

        AIMonster aiMonster = AIMonsterGenerator::generateMonster(this->user->getMonster());

        BattleController battleController = BattleController(this->user->getMonster(), &aiMonster);
    }else if(action == "Items")
    {
        cout << endl;/* List current items and give option to use them */
    }
    else if(action == "Account") // Open account page
    {
        AccountController accountController(this->user);
    }
    else if(action == "Points")
    {
        /* Lists player points and gives the option to use them */
    }
    else if(action == "Revive")
    {
        /* Might take this out, will revive a monster if the monster has fainted */
    }
    else if(action == "Logout")
    {
        cout << "Logged out" << endl;
        /* Change this->user to a guest account */

        /* Instead of 'delete this', go to logged out screen */
        LoggedOutController loggedOutController;
        delete this;
    }
}

void MainController::mainMenu()
{
    BasicView basicView;
    basicView.assignRefToUser(this->user); // Give BasicView access to the user object
    basicView.setTitle("Main Menu"); // Set the title of the screen

    /* MENU */
    vector<string> actions(6);
    actions.at(0) = "Battle";
    actions.at(1) = "Items";
    actions.at(2) = "Account";
    actions.at(3) = "Points";
    actions.at(4) = "Revive";
    actions.at(5) = "Logout";
    basicView.setActions(actions); // Set the actions of the screen

    basicView.load(); // Display the screen to the page

    int userinput;
    userinput = requestInput("Please enter in some stuff: "); // Get input (menu option) from the user
    performAction(basicView.getActions().at(userinput)); // Open the menu that the user requested
}

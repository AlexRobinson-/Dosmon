#include "ShopController.h"

#include "User.h"

#include "BasicView.h"

#include <iostream>

using namespace std;

/* CON/DECON */

ShopController::ShopController()
{
    //ctor
}

ShopController::~ShopController()
{
    //dtor
}

/* SET UP METHODS */

void ShopController::setUpController(User* userObject)
{
    this->user = userObject;
}

void ShopController::startController(string nextScreen)
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

/* METHODS */

string ShopController::performAction(string action, string nextScreen)
{
    if(action == "Main") // Displays main menu
    {
        nextScreen = mainMenu();
    }
    user->save();
    return nextScreen;
}

string ShopController::mainMenu()
{
    BasicView basicView;
    basicView.assignRefToUser(this->user); // Give BasicView access to the user object
    basicView.setTitle("Shop"); // Set the title of the screen

    /* MENU */
    vector<string> actions(6);
    actions.at(0) = "Weak Potion (+15 health)";
    actions.at(1) = "Strong Potion (+50 health)";
    actions.at(2) = "Amazing Potion (100% health)";
    actions.at(3) = "Attack Boost (+2 Attack, 2 turns)";
    actions.at(4) = "Shield (+50 attack)";
    actions.at(5) = "Back";
    basicView.setActions(actions); // Set the actions of the screen

    basicView.loadFancy(1); // Display the screen to the page

    int userinput;
    userinput = requestInput("What would you like to do? "); // Get input (menu option) from the user
    return basicView.getActions().at(userinput); // Return the menu that the user requested
}


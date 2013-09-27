#include "ShopController.h"

#include "User.h"

#include "BasicView.h"

#include <iostream>

using namespace std;

/* CON/DECON */

/**
 * ShopController constructor
 *
 * @author Alex Robinson
 */
ShopController::ShopController()
{
    //ctor
}

/**
 * ShopController destructor
 *
 * @author Alex Robinson
 */
ShopController::~ShopController()
{
    //dtor
}

/* SET UP METHODS */

/**
 * Sets up the ShopController class
 *
 * Accepts a User pointer as a parameter and sets the class variable user to the pointer.
 *
 * @param User* userObject pointer to the main User object
 *
 * @return void
 *
 * @author Alex Robinson
 */
void ShopController::setUpController(User* userObject)
{
    this->user = userObject;
}

/**
 * Starts/opens the Controller (screen)
 *
 * Accepts which screen to load initially, default is the "Main" screen.
 * The screen will keep refreshing, calling the performAction(string) method requesting for which screen to load next,
 * until "Back" is returned in which case it stops the method and in result stops the class, allowing the main game loop
 * to continue.
 *
 * @param string nextScreen determines which screen to load first
 *
 * @return void
 *
 * @author Alex Robinson
 */
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

/**
 * Loads the current screen and returns which screen to load next
 *
 * Accepts the current screen to load and gives the option for the next screen to load, this is to override whatever screen
 * would normally be opened next.
 *
 * @param string action
 * @param nextScreen nextScreen
 *
 * @return string This is the next action/screen to load/perform
 *
 * @author Alex Robinson
 */
string ShopController::performAction(string action, string nextScreen)
{
    string localNextScreen = "Main";
    if(action == "Main") // Displays main menu
    {
        localNextScreen = mainMenu();
    }

    if(nextScreen == "null")
    {
        nextScreen = localNextScreen;
    }

    user->save();
    return nextScreen;
}

/**
 * Displays the "Main Menu"
 *
 * @return string next screen example "Main"
 *
 * @author Alex Robinson
 */
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


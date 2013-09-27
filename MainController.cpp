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
 * MainController constructor
 *
 * @author Alex Robinson
 */
MainController::MainController()
{

}

/**
 * Loads the current screen and returns which screen to load next
 *
 * @author Alex Robinson
 */
MainController::~MainController()
{
    //dtor
}

/* SET UP METHODS */

/**
 * Sets up the MainController class
 *
 * Accepts a User pointer as a parameter and sets the class variable user to the pointer.
 *
 * @param User* userObject pointer to the main User object
 *
 * @return void
 *
 * @author Alex Robinson
 */
void MainController::setUpController(User* userObject)
{
    this->user = userObject;
    loadMenus();
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
string MainController::performAction(string action, string nextScreen)
{
    string localNextScreen = "Main";
    if(action == "Main") // Displays main menu
    {
        localNextScreen = mainMenu();
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

    if(nextScreen == "null")
    {
        nextScreen = localNextScreen;
    }

    cout << nextScreen << " " << localNextScreen << endl;

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
string MainController::mainMenu()
{
    BasicView basicView;
    basicView.assignRefToUser(this->user); // Give BasicView access to the user object
    basicView.setTitle("Main Menu"); // Set the title of the screen

    basicView.setActions(mainMenuActions); // Set the actions of the screen

    basicView.loadBasic(); // Display the screen to the page

    int userinput;
    userinput = requestInput("Please enter in some stuff: ", 7); // Get input (menu option) from the user

    return basicView.getActions().at(userinput); // Return the menu that the user requested
}

/**
 * Loads all of the relevant menus for the controller
 *
 * @return void
 *
 * @author Alex Robinson
 */
void MainController::loadMenus()
{
    vector<string> actions(7);
    actions.at(0) = "Battle";
    actions.at(1) = "Items";
    actions.at(2) = "Account";
    actions.at(3) = "Points";
    actions.at(4) = "Revive";
    actions.at(5) = "Shop";
    actions.at(6) = "Logout";
    this->mainMenuActions = actions;
}

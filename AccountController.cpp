#include "AccountController.h"

/* C++ INCLUDES */
#include <iostream>

using namespace std;

/* MODELS */
#include "User.h"

/* CONTROLLERS */
#include "MainController.h"

/* VIEWS */
#include "BasicView.h"

/* CON/DECON */

/**
 * AccountController constructor
 *
 * @author Alex Robinson
 */
AccountController::AccountController()
{

}

/**
 * AccountController destructor
 *
 * @author Alex Robinson
 */
AccountController::~AccountController()
{
    //dtor
}

/* METHODS */

/**
 * Sets up the AccountController class
 *
 * Accepts a User pointer as a parameter and sets the class variable user to the pointer.
 *
 * @param User* userObject pointer to the main User object
 *
 * @return void
 *
 * @author Alex Robinson
 */
void AccountController::setUpController(User* userObject)
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
string AccountController::performAction(string action, string nextScreen)
{
    string localNextScreen = "Main";
    if(action == "Main")
    {
        localNextScreen = mainMenu();
    }else if(action == "Change name")
    {
        changeName();
    }else if(action == "Change password")
    {
        changePassword();
    }else if(action == "Change monster name")
    {
        changeMonsterName();
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

/**
 * Requests the user to enter in a new name, saves the name in the object (not in a text file).
 * To save the user with the new details, call user.save().
 *
 * @return void
 *
 * @author Alex Robinson
 */
void AccountController::changeName()
{
    string username = requestStringInput("Please enter your new name: ");
    user->setName(username);
}

/**
 * Requests the user to enter in a new password, saves the password in the object (not in a text file).
 * To save the user with the new details, call user.save().
 *
 * @return void
 *
 * @author Alex Robinson
 */
void AccountController::changePassword()
{
    string password = requestStringInput("Please enter your new password: ");
    user->setPassword(password);
}

/**
 * Requests the user to enter a new name for their Monster, saves the name in the object (not in a text file).
 * To save the user with the new details, call user.save().
 *
 * @return void
 *
 * @author Alex Robinson
 */
void AccountController::changeMonsterName()
{
    string monsterName = requestStringInput("Please enter a new name for your monster: ");
    user->getMonster()->setMonsterName(monsterName);
}

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

/**
 * LoggedOutController constructor
 *
 * @author Alex Robinson
 */
LoggedOutController::LoggedOutController()
{

}

/**
 * LoggedOutController destructor
 *
 * @author Alex Robinson
 */
LoggedOutController::~LoggedOutController()
{
    //dtor
}

/* SET UP METHODS */

/**
 * Sets the required values for the LoggedOutController
 *
 * @param User* user Points to the main user object
 *
 * @return void
 *
 * @author Alex Robinson
 */
void LoggedOutController::setUpController(User* user)
{
    this->user = user;
}

/**
 * Starts/opens the Controller (screen)
 *
 * Main loop for the LoggedOut screen, will continue looping until the next screen is "loggedIn", in other words, you will be on this screen
 * until you log in.
 *
 * @param action default = "Main"
 *
 * @return void
 *
 * @author Alex Robinson
 */
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
string LoggedOutController::performAction(string action, string nextScreen)
{
    string localNextScreen = "Main";
    if(action == "Main") // Displays main menu
    {
        localNextScreen = mainMenu();
    }else if(action == "Login")
    {
        localNextScreen = loginScreen();
    }else if(action == "Create account")
    {
       localNextScreen = createAccount();
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

    if(nextScreen == "null")
    {
        nextScreen = localNextScreen;
    }

    return nextScreen;
}

/**
 * Displays the "Main Menu"
 *
 * @return string next screen example "Main"
 *
 * @return string
 *
 * @author Alex Robinson
 */
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

/**
 * Creates a user account
 *
 * Requests the user to enter in a username, password, name and monsterName and creates the User account.
 *
 * @return string next screen, will display "loggedIn" if account creation was successful, "Main" if not successful
 *
 * @author Alex Robinson
 */
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

/**
 * Displays the login screen
 *
 * Asks the user to type in their username and password, responds with the appropriate action
 *
 * @return string next screen, will display "loggedIn" if login was successful, "Main" if not successful
 *
 * @author Alex Robinson
 */
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

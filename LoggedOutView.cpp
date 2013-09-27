#include "LoggedOutView.h"
#include <iostream>
#include <string>

using namespace std;

#include "User.h"
#include "Monster.h"

/**
 * LoggedOutView constructor
 *
 * @author Alex Robinson
 */
LoggedOutView::LoggedOutView()
{
    //ctor
}

/**
 * LoggedOutView destructor
 *
 * @author Alex Robinson
 */
LoggedOutView::~LoggedOutView()
{
    //dtor
}

/**
 * Prints the basic (most used) view for the LoggedOutView
 *
 * @return void
 *
 * @author Alex Robinson
 */
void LoggedOutView::load()
{
    printLineBreak();
    printTitle();
    printActions();
}

/**
 * Prints the welcome message for when the User first signs up
 *
 * This method could definitely be prettied up
 *
 * @param User* user
 *
 * @return void
 *
 * @author Alex Robinson
 */
void LoggedOutView::printWelcomeMessage(User* user)
{
    printBlockNote("WELCOME TO DOSMON");
    cout << "Username:      " <<  user->getUsername() << endl;
    cout << "Name:          " <<  user->getName() << endl;
    cout << "Password:      " <<  user->getPassword() << endl;
    cout << "Level:         " <<  user->getMonster()->getLevel() << endl;
    cout << "Health:        " <<  user->getMonster()->getHealth() << " / " <<  user->getMonster()->getMaxHealth() << endl;
    cout << "Attack:        " <<  user->getMonster()->getAttack() << endl;
    cout << "Stat points:   " <<  user->getMonster()->getStatPoints() << endl;
    pressEnterToContinue();
}

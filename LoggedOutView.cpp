#include "LoggedOutView.h"
#include <iostream>
#include <string>

using namespace std;

#include "User.h"
#include "Monster.h"

LoggedOutView::LoggedOutView()
{
    //ctor
}

LoggedOutView::~LoggedOutView()
{
    //dtor
}

void LoggedOutView::load()
{
    printLineBreak();
    printTitle();
    printActions();
}

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

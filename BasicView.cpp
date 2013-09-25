#include "BasicView.h"
#include <iostream>
#include <iterator>

#include "User.h";
#include "UserMonster.h";
#include "AIMonster.h";

using namespace std;

BasicView::BasicView()
{
    //ctor
}

BasicView::~BasicView()
{
    //dtor
}

/**
Passes through the reference to the User object so we can deal with the user object directly.
*/
void BasicView::assignRefToUser(User* user)
{
    this->user = user;
}

void BasicView::loadBasic(int columns)
{
    printVerticalWhiteSpace();
    if(noteActive())
    {
        cout << getNote() << endl << endl;
    }
    printTitle();
    printLineBreak();
    printAccountInfoBar(this->user->getName(), this->user->getMonster()->getMonsterName(), this->user->getMonster()->getLevel());
    printAttributeBar(this->user->getMonster()->getHealth(), this->user->getMonster()->getMaxHealth(), "Health");
    printAttributeBar(this->user->getMonster()->getExperience(), this->user->getMonster()->getMaxExperience(), "Exp");
    printLineBreak(' ');
    printActions(columns);
}

void BasicView::loadFancy(int columns)
{
    printVerticalWhiteSpace();
    if(noteActive())
    {
        cout << getNote() << endl << endl;
    }
    printBlockNote("The Awesome Store", '*', 1, 2, 2);
    printLineBreak(' ');
    printLineBreak();
    printAccountInfoBar(this->user->getName(), this->user->getMonster()->getMonsterName(), this->user->getMonster()->getLevel());
    printAttributeBar(this->user->getMonster()->getHealth(), this->user->getMonster()->getMaxHealth(), "Health");
    printAttributeBar(this->user->getMonster()->getExperience(), this->user->getMonster()->getMaxExperience(), "Exp");
    printLineBreak(' ');
    printActions(columns);
}

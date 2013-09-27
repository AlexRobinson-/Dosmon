#include "BasicView.h"
#include <iostream>
#include <iterator>

#include "User.h";
#include "UserMonster.h";
#include "AIMonster.h";

using namespace std;

/* CON/DECON */

/**
 * BasicView constructor
 *
 * @author Alex Robinson
 */
BasicView::BasicView()
{
    //ctor
}

/**
 * BasicView destructor
 *
 * @author Alex Robinson
 */
BasicView::~BasicView()
{
    //dtor
}

/**
 * Assigns a local pointer to the original User object for easy access
 *
 * @param User* user
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BasicView::assignRefToUser(User* user)
{
    this->user = user;
}

/**
 * Loads the basic/most used (at the moment) view
 *
 * @param int columns Default = 2, how many columns to print the actions/menu items in
 *
 * @return void
 *
 * @author Alex Robinson
 */
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

/**
 * Loads a 'fancy' view, which really just means a pretty title.
 *
 * Customisation for the title will be implemented soon
 *
 * @param int columns Default = 2, how many columns to print the actions/menu items in
 *
 * @return void
 *
 * @author Alex Robinson
 */
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

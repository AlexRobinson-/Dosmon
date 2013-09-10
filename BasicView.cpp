#include "BasicView.h"
#include <iostream>
#include <iterator>

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

void BasicView::load()
{
    printLineBreak('-', 80);
    printAttributeBar(this->user->getMonster()->getHealth(), this->user->getMonster()->getMaxHealth(), "Health");
    printAttributeBar(this->user->getMonster()->getExperience(), this->user->getMonster()->getMaxExperience(), "Exp");
    printTitle();
    printActions();

}

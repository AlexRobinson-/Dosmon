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
    printAttributeBar(this->user->getHealth(), this->user->getMaxHealth(), "Health");
    printAttributeBar(this->user->getExperience(), this->user->getMaxExperience(), "Exp");
    cout << this->user->getUsername() << endl;
    printTitle();
    printActions();

}

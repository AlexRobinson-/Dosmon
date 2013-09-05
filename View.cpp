#include "View.h"
#include <string>
#include <iostream>
#include<vector>
#include <cmath>

using namespace std;

/* Con/decon */

View::View()
{
    //ctor
}

View::~View()
{
    //dtor
}

/* GETS */

/**
Returns the title
*/
string View::getTitle()
{
    return this->title;
}

/**
Returns the actions
*/
vector<string> View::getActions()
{
    return this->actions;
}

/* SETS */

void View::setTitle(string title)
{
    this->title = title;
}

void View::setActions(vector<string> actions)
{
    this->actions = actions;
}

/* PRINTS */

/**
Prints the title to the screen

Pass in false as parameter if you don't want a line break after the string
*/
void View::printTitle(bool newLine)
{
    cout << this->getTitle();

    if(newLine)
        cout << endl;
}

/**
Prints the actions to the screen

The format is:
first. second
*/
void View::printActions()
{

    /* Determine how long the longest string is */
    int maxLength = 0;
    for(int counter = 0; counter < this->getActions().size(); counter++) {
            if(this->getActions().at(counter).length() > maxLength) {
                maxLength = this->getActions().at(counter).length();
            }
    }

    /* Prints out the list items in a 2 column menu */
    int gridTracker = 0;
    for(int counter = 0; counter < this->getActions().size(); counter++)
    {
        if(gridTracker == 1) {
            cout << counter << ". " << this->getActions().at(counter) << endl;;
            gridTracker--;
        } else {
            cout << counter << ". " << this->getActions().at(counter);
            printLineBreak(' ', (maxLength + 10) - this->getActions().at(counter).length());
            gridTracker++;
        }

    }
    cout << endl;
}

void View::printLineBreak(char space, int linesAccross, bool breakChoice)
{
    for(int counter = 0;counter < linesAccross;counter++)
    {
        cout << space;
        if(breakChoice)
            cout << endl;
    }
}

void View::printAttributeBar(int currentAmount, int maxAmount, string title, int length, char filler, bool newLine)
{
    cout << currentAmount; // print currentAmount

    // Determine if the space before the attributeBar
    // This is to make sure if there is more than 1 action bar, everything should be formatted nicely
    int spaceBeforeBar = 1;
    if(currentAmount < 10)
    {
        spaceBeforeBar += 2;
    }else if(currentAmount < 100)
    {
        spaceBeforeBar += 1;
    }
    for(int spaceBeforeCounter = 0; spaceBeforeCounter < spaceBeforeBar; spaceBeforeCounter++)
    {
        cout << " ";
    }

    /* START OF ATTRIBUTE BAR */
    cout << "/";

    double healthPerChar = length;
    healthPerChar = healthPerChar / maxAmount;
    int amountOfFiller = round(healthPerChar * currentAmount);
    /* FILL IN ATTRIBUTE BAR */
    for(int fillerCounter = 0; fillerCounter < amountOfFiller; fillerCounter++)
    {
        cout << filler;
    }
    int amountOfSpace = round(healthPerChar * (maxAmount - currentAmount));
    /* FILL IN REMAINING SPACE OF ATTRIBUTE BAR - to keep everything all formatted nicely */
    for(int spaceCounter = 0; spaceCounter < amountOfSpace; spaceCounter++)
    {
        cout << " ";
    }
    /* END OF ACTION BAR */
    cout << "/ ";

    // Format space before title nicely
    int spaceBeforeTitle = 1;
    if(currentAmount < 10)
    {
        spaceBeforeTitle += 2;
    }else if(currentAmount < 100)
    {
        spaceBeforeTitle += 1;
    }
    for(int spaceBeforeCounter = 0; spaceBeforeCounter < spaceBeforeTitle; spaceBeforeCounter++)
    {
        cout << " ";
    }

    cout << title; // Print title

    // if a newLine is requested (true by default) print a new line
    if(newLine)
    {
        cout << endl;
    }

}


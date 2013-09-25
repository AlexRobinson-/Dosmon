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

/**
Returns if there is a note to be displayed
*/
bool View::noteActive()
{
    return showNote;
}

/**
Returns the note to be displayed at the top of the page
*/
std::string View::getNote()
{
    showNote = false;
    return note;
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

void View::setNote(string note)
{
    this->note = note;
    showNote = true;
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
void View::printActions(int columns)
{

    /* Determine how long the longest string is */
    int maxLength = 0;
    for(int counter = 0; counter < this->getActions().size(); counter++) {
            if(this->getActions().at(counter).length() > maxLength) {
                maxLength = this->getActions().at(counter).length();
            }
    }

    /* Prints out the list items in a 2 column menu */
    int gridTracker = 1;
    for(int counter = 0; counter < this->getActions().size(); counter++)
    {
        if(gridTracker >= columns) {
            cout << counter << ". " << this->getActions().at(counter) << endl;;
            gridTracker = 1;
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
        if(breakChoice){
            cout << endl;
        }
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

    cout << maxAmount << " " << title; // Print title

    // if a newLine is requested (true by default) print a new line
    if(newLine)
    {
        cout << endl;
    }
}

void View::printAccountInfoBar(string masterName, string monsterName, int level, bool newLine)
{
    cout << "\t\t" << masterName << endl << monsterName << "\t\tlvl " << level << endl;
}

void View::printVerticalWhiteSpace(int rows)
{
    for(int x = 0;x < rows;x++)
    {
        cout << endl;
    }
}

void View::printBlockNote(string note, char filler, int paddingVertical, int borderVertical, int borderHorizontal)
{
    /* TOP BORDER */
    for(int verticalBorderTopCounter = 0; verticalBorderTopCounter < borderVertical; verticalBorderTopCounter++)
    {
        printLineBreak(filler);
    }
    /* TOP PADDING */
    for(int verticalPaddingTopCounter = 0; verticalPaddingTopCounter < paddingVertical; verticalPaddingTopCounter++)
    {
        printMiddleOfBlockNote("", '*', borderHorizontal);
    }
    /* TEXT IN MIDDLE OF BLOCK NOTE */
    printMiddleOfBlockNote(note, filler, borderHorizontal);
    /* BOTTOM PADDING */
    for(int verticalPaddingBottomCounter = 0; verticalPaddingBottomCounter < paddingVertical; verticalPaddingBottomCounter++)
    {
        printMiddleOfBlockNote("", '*', borderHorizontal);
    }
    /* BOTTOM BORDER */
    for(int verticalBorderBottomCounter = 0; verticalBorderBottomCounter < borderVertical; verticalBorderBottomCounter++)
    {
        printLineBreak(filler);
    }
}

void View::printMiddleOfBlockNote(string note, char filler, int borderHorizontal)
{
    int spacingBefore = 0;
    int spacingAfter = 0;
    if(note.length() % 2 == 1)
    {
        spacingBefore = (80 - note.length() - 1) / 2 - borderHorizontal;
        spacingAfter = (80 - note.length() + 1) / 2 - borderHorizontal;
    }else
    {
        spacingBefore = (80 - note.length()) / 2 - borderHorizontal;
        spacingAfter = spacingBefore;
    }

    printLineBreak(filler, borderHorizontal);
    printLineBreak(' ', spacingBefore);
    cout << note;
    printLineBreak(' ', spacingAfter);
    printLineBreak(filler, borderHorizontal);
}

/* METHODS */

void View::pressEnterToContinue()
{
    cout << "Press enter to continue..." << endl;
    cin.get();
}

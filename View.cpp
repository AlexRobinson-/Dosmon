#include "View.h"
#include <string>
#include <iostream>
#include<vector>
#include <cmath>

using namespace std;

int View::screenWidth = 80;

/* CON/DECON */

/**
 * View constructor
 *
 * @author Alex Robinson
 */
View::View()
{
    //ctor
}

/**
 * View destructor
 *
 * @author Alex Robinson
 */
View::~View()
{
    //dtor
}

/* GETS */

/**
 * Returns the current title
 *
 * @return string
 *
 * @author Alex Robinson
 */
string View::getTitle()
{
    return this->title;
}

/**
 * Returns the current actions
 *
 * @return vector<string>
 *
 * @author Alex Robinson
 */
vector<string> View::getActions()
{
    return this->actions;
}

/**
 * Returns if there is currently a note ready to be shown
 *
 * The usefulness of the note feature is in question, this method may be removed in the future
 *
 * @return bool
 *
 * @author Alex Robinson
 */
bool View::noteActive()
{
    return showNote;
}

/**
 * Returns the current note
 *
 * Also sets the boolean showNote to false, only allowed a note to be shown once
 *
 * @return string
 *
 * @author Alex Robinson
 */
std::string View::getNote()
{
    showNote = false;
    return note;
}

/* SETS */

/**
 * Sets the title for the screen
 *
 * @param string title
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::setTitle(string title)
{
    this->title = title;
}

/**
 * Sets the actions for the screen
 *
 * @param vector<string> actions
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::setActions(vector<string> actions)
{
    this->actions = actions;
}

/**
 * Sets the note for the screen
 *
 * Also sets the boolean showNote to true, which will notify the next print method to display the note
 *
 * @param string note
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::setNote(string note)
{
    this->note = note;
    showNote = true;
}

/* PRINTS */

/**
 * Prints the title to the screen
 *
 * Pass in false as the paramter if you do not want a line break after the title has been printed (the boolean is true as the default)
 *
 * @param bool newLine Default = true
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::printTitle(bool newLine)
{
    cout << this->getTitle();

    if(newLine)
        cout << endl;
}

/**
 * Prints out the actions in as many columns as requested
 *
 * Although you can pass in as many columns as you like, 2 columns is nice. The option to change how many columns is more if you want to print out
 * the actions in 1 column, but hey, do what you want.
 *
 * @param int columns
 *
 * @return void
 *
 * @author Alex Robinson
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

    /* Prints out the list of items in a x column menu */
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

/**
 * Prints a line break
 *
 * Used mostly to print a line accross the screen, however you can use it for whatever you want to.
 * You are able to change the character you want to do the line with, how long the line will be, if you want the line to be a vertical line
 * (a break after each character) or if you want a break to be after the line.
 * Please note: if the line fills up the entire width of the screen, the linebreak after everything is not neccesary and is set to false as default
 * for this reason. If you were however printing a custom line break with a shorter width, setting the boolean breakAfterAll to true may be a good idea
 * depending on what you are using the line break for.
 *
 * @param char space The character to fill the lineBreak with, default = '-'
 * @param int linesAccross How long the lineBreak will be, default = View::screenWidth
 * @param bool breakAfterEach Set to true if you want a vertical line, default = false
 * @param bool breakAfterAll Set to true if you want a break after the vertical line, read the method description for an important note on this
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::printLineBreak(char space, int linesAccross, bool breakAfterEach, bool breakAfterAll)
{
    for(int counter = 0;counter < linesAccross;counter++)
    {
        cout << space;
        if(breakAfterEach){
            cout << endl;
        }
    }
    if(breakAfterAll){
            cout << endl;
        }
}

/**
 * Prints an attribute bar
 *
 * An example of an attribute bar is something like the health bar, or the experience points bar
 *
 * @param int currentAmount The current amount the User/Monster has
 * @param int maxAmount The maximum amount the User/Monster can get
 * @param string title The title of the attribute bar, usually the attribute name, for example "Health"
 * @param int length Default = 15 How long the attribute bar will be
 * @param char filler Default = '=' What the filler will be for the attribute bar
 * @param bool newLine Default = true Determines if a line break will be printed out after the attribute bar
 *
 * @return void
 *
 * @author Alex Robinson
 */
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

/**
 * Prints the account information bar
 *
 * @param string masterName The User's name
 * @param string monsterName The User's Monster's name
 * @param int level The level of the User
 * @param bool Determines if you want a linebreak after the account information bar has been printed
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::printAccountInfoBar(string masterName, string monsterName, int level, bool newLine)
{
    cout << "\t\t" << masterName << endl << monsterName << "\t\tlvl " << level;
    if(newLine)
        endl;
}

/**
 * Prints vertical white space
 *
 * Currently used to simulate staying on the one screen that changes, rather than everything printing out after each other, but by all means
 * use this for whatever you want.
 * Please note: the amount of rows is currently hardcoded into the method as the default value, this will possibly be changed to a static variable
 * that the user can change in the settings menu (which has not been implemented yet),
 *
 * @param int rows Default = 20 How many rows of white space you want to print
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::printVerticalWhiteSpace(int rows)
{
    for(int x = 0;x < rows;x++)
    {
        cout << endl;
    }
}

/**
 * Prints a customisable block note
 *
 * A block note is a note (string) centered and surrounded by a character.
 * An example of a block note is:
 *
 * **************************
 * ** Block notes are cool **
 * **************************
 *
 * The possiblility to choose how wide the block note is may be implemented in the future, at the moment it is however wide your screen size is.
 *
 * @param string note The message you want to be displayed in the middle of the block note
 * @param char filler Default = '*' What you want the border of the block note to be made up of
 * @param int paddingVertical Default = 0 How much whitespace you want vertically (above and below the note/message)
 * @param int borderVertical Default = 1 How thick you want the borders on the top and bottom of the block note to be
 * @param int borderHorizontal Default = 1 How thick you want the borders on the left and right of the block note to be. Be cautious of how wide your screen size is and how much text you have
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::printBlockNote(string note, char filler, int paddingVertical, int borderVertical, int borderHorizontal)
{
    /* TOP BORDER */
    for(int verticalBorderTopCounter = 0; verticalBorderTopCounter < borderVertical; verticalBorderTopCounter++)
    {
        printLineBreak(filler, View::screenWidth);
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
        printLineBreak(filler, View::screenWidth);
    }
}

/**
 * Prints the middle of the block note
 *
 * Centers the text to be in the middle (horizontally) of the block note and prints the borders on the far left and right sides
 *
 * @param string note The message you want to be centered between the borders
 * @param char filler Default = '*' What you want the border to be made up of
 * @param int borderHorizontal Default = 1 How thick you want the borders on the left and right of the block note to be. Be cautious of how wide your screen size is and how much text you have
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::printMiddleOfBlockNote(string note, char filler, int borderHorizontal)
{
    int spacingBefore = 0;
    int spacingAfter = 0;
    if(note.length() % 2 == 1)
    {
        spacingBefore = (View::screenWidth - note.length() - 1) / 2 - borderHorizontal;
        spacingAfter = (View::screenWidth - note.length() + 1) / 2 - borderHorizontal;
    }else
    {
        spacingBefore = (View::screenWidth - note.length()) / 2 - borderHorizontal;
        spacingAfter = spacingBefore;
    }

    printLineBreak(filler, borderHorizontal);
    printLineBreak(' ', spacingBefore);
    cout << note;
    printLineBreak(' ', spacingAfter);
    printLineBreak(filler, borderHorizontal);
}

/* METHODS */


/**
 * Requests the User to press enter
 *
 * Mostly used to make sure the User acknowledges what is currently on the screen before they continue, however use this for whatever you like.
 *
 * @return void
 *
 * @author Alex Robinson
 */
void View::pressEnterToContinue()
{
    cout << "Press enter to continue..." << endl;
    cin.get();
}

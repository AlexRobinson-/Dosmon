#include "Controller.h"
#include <iostream>
#include <string>
#include <limits>

#include "User.h"

using namespace std;

/**
 * Controller constructor
 *
 * @author Alex Robinson
 */
Controller::Controller()
{

}

/**
 * Controller destructor
 *
 * @author Alex Robinson
 */
Controller::~Controller()
{
    //dtor
}

/**
Asks the user for input

string question     default = *replace*
bool breakAfter     default = false
*/

/**
 * Asks the user for input
 *
 * Requests the user for input, if the input is more than the max input or less than 0, or if it isn't a valid int, the method will
 * continue asking the user to enter a valid input.
 *
 * @param string question
 * @param int maxInput
 * @param bool breakAfter
 *
 * @return int User's input
 *
 * @author Alex Robinson
 */
int Controller::requestInput(string question, int maxInput, bool breakAfter)
{
    //Enter text if you would like to ask a question
    if(question != "*replace*") {
        cout << question;
    }
    //Enter true if you would like a break after the requestion
    if(breakAfter) {
        cout << endl;
    }
    int getInput;
    bool keepRunning = true;
    bool validInput = true;
    while(keepRunning)
    {
        validInput = true;
        if(! (cin >> getInput))
        {
           validInput = false;
           cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin.clear();
        }
        if(maxInput > -1 && getInput > maxInput)
        {
           validInput = false;
        }
        if(getInput < 0)
        {
            validInput = false;
        }
        if(validInput)
        {
            keepRunning = false;
        }else
        {
            cout << "Please enter in a valid input" << endl << endl;
        }
    }

    cin.ignore();
    return getInput;
}

/**
Asks the user for input
string question     default = *replace*
bool breakAfter     default = false
*/
/**
 * Requests the user to enter in a string
 *
 * Will continue asking the user for a valid input until one is provided
 *
 * @param string question
 * @param bool breakAfter
 *
 * @return string User's input
 *
 * @author Alex Robinson
 */
string Controller::requestStringInput(string question, bool breakAfter)
{
    //Enter text if you would like to ask a question
    if(question != "*replace*") {
        cout << question;
    }
    //Enter true if you would like a break after the requestion
    if(breakAfter) {
        cout << endl;
    }
    string getInput;
   if(! (cin >> getInput) )
   {
       cin.clear();
       cout << "Please enter in a valid input" << endl << endl;
       requestInput(question, breakAfter);
   }
    cin.ignore();
    return getInput;
}

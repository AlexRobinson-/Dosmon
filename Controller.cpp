#include "Controller.h"
#include <iostream>
#include <string>
#include <limits>

#include "User.h"

using namespace std;

Controller::Controller()
{

}

void Controller::performAction(string action)
{

}

Controller::~Controller()
{
    //dtor
}

/**
Asks the user for input

string question     default = *replace*
bool breakAfter     default = false
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

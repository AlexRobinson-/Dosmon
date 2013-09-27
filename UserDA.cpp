#include "UserDA.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>     /* atoi */

using namespace std;

/* CON/DECON */

/**
 * UserDA constructor + intial start up method
 *
 * Sets the userObject the data access is for, the extension the User file is stored in.
 * The file name is a combernation of the pre-set userFolder, the User's username and the extension.
 *
 * @param User* userObject
 * @param string extension Default = ".txt"
 *
 * @author Alex Robinson
 */
UserDA::UserDA(User* userObject, string extension)
{
    this->user      = userObject;
    this->extension = extension;
    this->fileName  = userFolder + this->user->getUsername() + extension;
}

/**
 * UserDA destructor
 *
 * @author Alex Robinson
 */
UserDA::~UserDA()
{
    //dtor
}

/* PUBLIC METHODS */

/**
 * Returns the value of the attribute requested for the User that should have already beeen specified in the userObject pointer that was retrieved in the constructor
 *
 * @param string attribute
 *
 * @return string
 *
 * @author Alex Robinson
 */
string UserDA::getAttribute(string attribute)
{
    ifstream myfile (fileName.c_str());
    string readLine;
    //cout << "Opening file " << fileName << endl;
    if( myfile.is_open() )
    {
        while ( myfile.good() )
        {
          getline (myfile,readLine);
          vector<string> currentLine = splitLine(readLine);
          if(attribute == currentLine.at(0) )
          {
              myfile.close();
              return currentLine.at(1);
          }
          //cout << "Did not find " << currentLine.at(0) << endl;
        }
        myfile.close();
    }else
    {
        return "Error: File did not open";
    }
    return "Error: Reached end of function";
}

/**
 * Saves all of the User's attributes into a text file
 *
 * Returns true is successful, false if unsuccessful
 *
 * @return bool
 *
 * @author Alex Robinson
 */
bool UserDA::saveUser()
{
    ofstream myfile (fileName.c_str());
    string readPassword;
    if (myfile.is_open())
    {
        myfile << "name:"   << user->getName();
        myfile << "\n"; // new line
        myfile << "password:"   << user->getPassword();
        myfile << "\n"; // new line
        myfile << "level:"      << user->getMonster()->getLevel();
        myfile << "\n"; // new line
        myfile << "health:"     << user->getMonster()->getHealth();
        myfile << "\n"; // new line
        myfile << "attack:"     << user->getMonster()->getAttack();
        myfile << "\n"; // new line
        myfile << "statpoints:" << user->getMonster()->getStatPoints();
        myfile << "\n"; // new line
        myfile << "experience:" << user->getMonster()->getExperience();
        myfile << "\n"; // new line
        myfile << "monsterName:" << user->getMonster()->getMonsterName();
        myfile << "\n"; // new line
        myfile << "coins:" << user->getCoins();

        myfile.close();
        return true;
    }else
    {
        cout << "Something went wrong" << endl;
        return false;
    }
}

/**
 * Loads the User into the given userObject
 *
 * This method is usually called after a successful login.
 *
 * @return void
 *
 * @author Alex Robinson
 */
void UserDA::loadUser()
{
    ifstream myfile (fileName.c_str());
    string readLine;
    if( myfile.is_open() )
    {
        while ( myfile.good() )
        {
          getline (myfile,readLine);
          vector<string> currentLine = splitLine(readLine);
          assignAttributeToUserObject(currentLine);
        }
        myfile.close();
    }else
    {
        cout << "Error: File did not open";
    }
}

/* PRIVATE METHODS */

/**
 * Assists in reading the User file
 *
 * As the attributes names and values are stored in the text file using a set seperator, this method splits the single string into the 2 seperate
 * values.
 *
 * @param string line
 * @param string seperator
 *
 * @return vector<string>
 *
 * @author Alex Robinson
 */
vector<string> UserDA::splitLine(string line, string seperator)
{
    vector<string> splitLine(2);
    int breaker = line.find(seperator);
    int firstCut = breaker;
    int secondCut = breaker + 1;
    splitLine.at(0) = line.substr(0, firstCut);
    splitLine.at(1) = line.substr(secondCut, line.length() - 1);
    return splitLine;
}

/**
 * Assists in the loading of a User, this sets the given attribute to the User's object
 *
 * Uses the first value of the vector (.at(0)) to get the attribute name, sets the second value (.at(1)) which is the attribute value to the
 * relevant attribute in the User object.
 *
 * @param vector<string> attributeHolder
 *
 * @return void
 *
 * @author Alex Robinson
 */
void UserDA::assignAttributeToUserObject(vector<string> attributeHolder)
{
    if(attributeHolder.at(0) == "name")
    {
        user->setName(attributeHolder.at(1));
    }else if(attributeHolder.at(0) == "password")
    {
        user->setPassword(attributeHolder.at(1));
    }else if(attributeHolder.at(0) == "level")
    {
        int attribute = atoi(attributeHolder.at(1).c_str());
        user->getMonster()->setLevel(attribute, false);
    }else if(attributeHolder.at(0) == "health")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->getMonster()->setHealth(attribute);
    }else if(attributeHolder.at(0) == "attack")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->getMonster()->setAttack(attribute);
    }else if(attributeHolder.at(0) == "statpoints")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->getMonster()->setStatPoints(attribute);
    }else if(attributeHolder.at(0) == "experience")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->getMonster()->setExperience(attribute, false);
    }else if(attributeHolder.at(0) == "monsterName")
    {
        user->getMonster()->setMonsterName(attributeHolder.at(1));
    }else if(attributeHolder.at(0) == "coins")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->setCoins(attribute, false);
    }
}

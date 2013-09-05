#include "UserDA.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>     /* atoi */

using namespace std;

/* CON/DECON */

UserDA::UserDA(User* userObject, string extension)
{
    this->user      = userObject;
    this->extension = extension;
    this->fileName  = userFolder + this->user->getUsername() + extension;
}

UserDA::~UserDA()
{
    //dtor
}

/* PUBLIC METHODS */

/**
Returns the attribute requested
*/
string UserDA::getAttribute(string attribute)
{
    ifstream myfile (fileName.c_str());
    string readLine;
    cout << "Opening file " << fileName << endl;
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
          cout << "Did not find password " << currentLine.at(0) << endl;
        }
        myfile.close();
    }else
    {
        return "Error: File did not open";
    }
    return "Error: Reached end of function";
}

/**
Saves all of the users details to a text file
*/
bool UserDA::saveUser()
{
    ofstream myfile (fileName.c_str());
    string readPassword;
    if (myfile.is_open())
    {
        myfile << "username:"   << user->getUsername();
        myfile << "\n"; // new line
        myfile << "password:"   << user->getPassword();
        myfile << "\n"; // new line
        myfile << "health:"     << user->getHealth();
        myfile << "\n"; // new line
        myfile << "level:"      << user->getLevel();
        myfile << "\n"; // new line
        myfile << "attack:"     << user->getAttack();
        myfile << "\n"; // new line
        myfile << "statpoints:" << user->getStatPoints();
        myfile << "\n"; // new line
        myfile << "experience:" << user->getExperience();

        myfile.close();
        return true;
    }else
    {
        cout << "Something went wrong" << endl;
        return false;
    }
}

void UserDA::loadUser()
{
    ifstream myfile (fileName.c_str());
    string readLine;
    cout << "Opening file " << fileName << endl;
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

void UserDA::assignAttributeToUserObject(vector<string> attributeHolder)
{
    if(attributeHolder.at(0) == "username")
    {
        user->setUsername(attributeHolder.at(1));
    }else if(attributeHolder.at(0) == "password")
    {
        user->setPassword(attributeHolder.at(1));
    }else if(attributeHolder.at(0) == "level")
    {
        int attribute = atoi(attributeHolder.at(1).c_str());
        user->setLevel(attribute);
    }else if(attributeHolder.at(0) == "health")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->setHealth(attribute);
    }else if(attributeHolder.at(0) == "attack")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->setAttack(attribute);
    }else if(attributeHolder.at(0) == "statpoints")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->setStatPoints(attribute);
    }else if(attributeHolder.at(0) == "experience")
    {
        int attribute = atoi (attributeHolder.at(1).c_str());
        user->setExperience(attribute);
    }
}

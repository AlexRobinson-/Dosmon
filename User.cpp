#include "User.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atoi */

#include "UserDA.h"

#include "UserAttributeHelper.h"
#include "UserMonster.h"

using namespace std;

/* CON/DECON */

/**
 * User constructor
 *
 * @author Alex Robinson
 */
User::User()
{

}

/**
 * User destructor
 *
 * @author Alex Robinson
 */
User::~User()
{
    //dtor
}

/* SETS */

/**
 * Sets the username for the User
 *
 * @param string username
 *
 * @return void
 *
 * @author Alex Robinson
 */
void User::setUsername(string username)
{
    this->username = username;
}

/**
 * Sets the name for the User
 *
 * @param string name
 *
 * @return void
 *
 * @author Alex Robinson
 */
void User::setName(string name)
{
    this->name = name;
}

/**
 * Sets the password for the User
 *
 * @param string password
 *
 * @return void
 *
 * @author Alex Robinson
 */
void User::setPassword(string password)
{
    this->password = password;
}

/**
 * Sets the pointer to the UserMonster object (The User's monster)
 *
 * @param UserMonster* userMonster
 *
 * @return void
 *
 * @author Alex Robinson
 */
void User::setMonster(UserMonster* userMonster)
{
    this->monster = userMonster;
}

/**
 * Sets the coins for the User
 *
 * Pass in false as the second parameter to set the coins (usually done at initial load), default value is true
 * If the value is true the coins will be incremented by whatever value was passed in.
 * It is a good idea to pass in a negative number to take coins from the User, positive to give coins to the User.
 *
 * @param int coins
 * @param bool increment
 *
 * @return void
 *
 * @author Alex Robinson
 */
void User::setCoins(int coins, bool increment)
{
    if(increment)
    {
        this->coins += coins;
    }else
    {
        this->coins = coins;
    }
}

/* GETS */

/**
 * Returns the username
 *
 * @return string
 *
 * @author Alex Robinson
 */
string User::getUsername()
{
    return this->username;
}

/**
 * Returns the name
 *
 * @return string
 *
 * @author Alex Robinson
 */
string User::getName()
{
    return this->name;
}

/**
 * Returns the password
 *
 * @return string
 *
 * @author Alex Robinson
 */
string User::getPassword()
{
    return this->password;
}

/**
 * Returns the pointer to the User's Monster's object
 *
 * @return UserMonster*
 *
 * @author Alex Robinson
 */
UserMonster* User::getMonster()
{
    return this->monster;
}

/**
 * Returns how many coins the User has
 *
 * @return string
 *
 * @author Alex Robinson
 */
int User::getCoins()
{
    return this->coins;
}

/* METHODS */

/**
 * Attempts to log the User in
 *
 * Sets the username and password to the current User object.
 * Passes a reference to it's self (this) to a UserDA object. the UserDA method getAttribute is then used to test
 * if the password entered in matches the one in file. This method will also set up the initial values for the User,
 * which requires contacting the UserAttributeHelper classes.
 * If the passwords match the User logged in and the boolean true is returned.
 * Obviously false is returned if the password is incorrect or if any other errors occur.
 *
 * At the moment passing in an extension is optional (default is set in the header file), this is to support handing
 * legacy files in the future and to help with the overall flexibility of the game.
 *
 * @param string username
 * @param string password
 * @param string extension
 *
 * @return bool
 *
 * @author Alex Robinson
 */
bool User::attemptLogin(string username, string password, string extension)
{
    setUsername(username);
    setPassword(password);

    UserDA userDA = UserDA(this);
    if(userDA.getAttribute("password") == password)
    {
        userDA.loadUser();
        getMonster()->setMaxHealth(UserAttributeHelper::calculateMaxHealth(getMonster()->getLevel()));
        getMonster()->setMaxExperience(UserAttributeHelper::calculateMaxExperience(getMonster()->getLevel()));
        return true;
    }else
    {
        return false;
    }
}

/**
 * Saves the User to a text file
 *
 * Calls the UserDA method saveUser(). Although it is optional to pass in an extension, this is not used at the moment
 * and might never be implemented.
 *
 * A boolean is returned signalling if the save was successful or not (true is obviously successful, whereas false
 * means unsuccessful).
 *
 * @param string extension
 *
 * @return bool
 *
 * @author Alex Robinson
 */
bool User::save(string extension)
{
    User *user = new User(*this);
    UserDA userDA = UserDA(this);
    userDA.saveUser();
    return true;
}

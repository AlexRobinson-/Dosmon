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

User::User()
{

}

User::~User()
{
    //dtor
}

/* SETS */

void User::setUsername(string username)
{
    this->username = username;
}

void User::setPassword(string password)
{
    this->password = password;
}

void User::setMonster(UserMonster* userMonster)
{
    this->monster = userMonster;
}

/* GETS */

string User::getUsername()
{
    return this->username;
}

string User::getPassword()
{
    return this->password;
}

UserMonster* User::getMonster()
{
    return this->monster;
}

/* METHODS */

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

bool User::save(string extension)
{
    User *user = new User(*this);
    UserDA userDA = UserDA(this);
    userDA.saveUser();
    return true;
}

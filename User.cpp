#include "User.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atoi */

#include "UserDA.h"

#include "UserAttributeHelper.h"

using namespace std;

/* CON/DECON */

User::User()
{
    //ctor
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

void User::setLevel(int level)
{
    this->level = level;
}

void User::setHealth(int health)
{
    this->health = health;
}

void User::setMaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}

void User::setAttack(int attack)
{
    this->attack = attack;
}

void User::setStatPoints(int statPoints)
{
    this->statPoints = statPoints;
}

void User::setExperience(int experience)
{
    this->experience = experience;
}

void User::setMaxExperience(int maxExperience)
{
    this->maxExperience = maxExperience;
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

int User::getLevel()
{
    return level;
}

int User::getHealth()
{
    return health;
}

int User::getMaxHealth()
{
    return maxHealth;
}

int User::getAttack()
{
    return attack;
}

int User::getStatPoints()
{
    return statPoints;
}

int User::getExperience()
{
    return experience;
}

int User::getMaxExperience()
{
    return maxExperience;
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
        setMaxHealth(UserAttributeHelper::calculateMaxHealth(getLevel()));
        setMaxExperience(UserAttributeHelper::calculateMaxExperience(getLevel()));
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

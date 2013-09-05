#include "Monster.h"

#include <string>

using namespace std;

/* CON/DECON */

Monster::Monster()
{
    //ctor
}

Monster::~Monster()
{
    //dtor
}

/* SETS */

void Monster::setMonsterName(string monsterName)
{
    this->monsterName = monsterName;
}

void Monster::setLevel(int level)
{
    this->level = level;
}

void Monster::setHealth(int health)
{
    this->health = health;
}

void Monster::setMaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}

void Monster::setAttack(int attack)
{
    this->attack = attack;
}

void Monster::setStatPoints(int statPoints)
{
    this->statPoints = statPoints;
}

void Monster::setExperience(int experience)
{
    this->experience = experience;
}

void Monster::setMaxExperience(int maxExperience)
{
    this->maxExperience = maxExperience;
}

/* GETS */

string Monster::getMonsterName()
{
    return monsterName;
}

int Monster::getLevel()
{
    return level;
}

int Monster::getHealth()
{
    return health;
}

int Monster::getMaxHealth()
{
    return maxHealth;
}

int Monster::getAttack()
{
    return attack;
}

int Monster::getStatPoints()
{
    return statPoints;
}

int Monster::getExperience()
{
    return experience;
}

/*int User::getMaxExperience()
{
    return maxExperience;
}*/


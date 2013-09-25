#include "Monster.h"

#include <string>
#include <cmath>
#include <ctime>
#include <random>

#include "BattleMove.h"

#include <iostream>

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

void Monster::setLevel(int level, bool increment)
{
    if(increment)
    {
        this->level += level;
    }else
    {
        this->level = level;
    }
    loadLevelAttributes();
}

void Monster::setHealth(int tmpHealth)
{

    if(tmpHealth < 0){
        tmpHealth = 0;
    }else if(tmpHealth > getMaxHealth())
    {
        tmpHealth = getMaxHealth();
    }
    this->health = tmpHealth;
}

void Monster::setMaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}

void Monster::setAttack(int attack)
{
    this->attack = attack;
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

/* METHODS */

/* PROTECTED METHODS */
int Monster::calculateAttack()
{
    srand(time(0));
    double randomNumber = rand()%(5-1)+1;

    if(randomNumber < 3)
    {
        randomNumber = 1;
    }else if(randomNumber < 5)
    {
        randomNumber = 3;
    }
    cout << "randomNumber = " << randomNumber << endl;
    int calculateAttackHealth = floor( (1.3 * pow(getLevel(), 1.3) * ( 1.4*(randomNumber + (getAttack() / 105))) ));

    int highest = 0;
    if(calculateAttackHealth < 10 && calculateAttackHealth > 2)
    {
        highest = 3;
    }else
    {
        highest = 10;
    }
    calculateAttackHealth += rand()%(highest-(0-highest))+(0-highest);
    if(calculateAttackHealth < 0)
    {
        calculateAttackHealth *= -1;
    }
    return -calculateAttackHealth;
}

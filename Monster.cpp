#include "Monster.h"

#include <string>
#include <cmath>
#include <ctime>
#include <random>

#include "BattleMove.h"

#include <iostream>

using namespace std;

/* CON/DECON */

/**
 * Monster constructor
 *
 * @author Alex Robinson
 */
Monster::Monster()
{
    //ctor
}

/**
 * Monster destructor
 *
 * @author Alex Robinson
 */
Monster::~Monster()
{
    //dtor
}

/* SETS */

/**
 * Sets the Monster's name
 *
 * @param string monsterName
 *
 * @return void
 *
 * @author Alex Robinson
 */
void Monster::setMonsterName(string monsterName)
{
    this->monsterName = monsterName;
}

/**
 * Sets the level of the Monster
 *
 * Pass in false as the second parameter to set the level, default value is true which simulates levelling up
 *
 * @param int level
 * @param bool increment Default = true
 *
 * @return void
 *
 * @author Alex Robinson
 */
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

/**
 * Sets the health of the Monster
 *
 * @param int tmpHealth
 *
 * @return void
 *
 * @author Alex Robinson
 */
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

/**
 * Sets the maximum health of the Monster
 *
 * Possibly useless (due to this being a calculated value), needs evaluation
 *
 * @param int maxHealth
 *
 * @return void
 *
 * @author Alex Robinson
 */
void Monster::setMaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}

/**
 * Sets the attack for the Monster
 *
 * Attack points increase how much the Monster deals damage while in Battle
 *
 * @param int attack
 *
 * @return void
 *
 * @author Alex Robinson
 */
void Monster::setAttack(int attack)
{
    this->attack = attack;
}

/* GETS */

/**
 * Returns the Monster's name
 *
 * @return string
 *
 * @author Alex Robinson
 */
string Monster::getMonsterName()
{
    return monsterName;
}

/**
 * Returns the Monster's level
 *
 * @return int
 *
 * @author Alex Robinson
 */
int Monster::getLevel()
{
    return level;
}

/**
 * Returns the Monster's health
 *
 * @return int
 *
 * @author Alex Robinson
 */
int Monster::getHealth()
{
    return health;
}

/**
 * Returns the Monster's maximum possible health
 *
 * @return int
 *
 * @author Alex Robinson
 */
int Monster::getMaxHealth()
{
    return maxHealth;
}

/**
 * Returns how many attack points the Monster has
 *
 * @return int
 *
 * @author Alex Robinson
 */
int Monster::getAttack()
{
    return attack;
}

/* METHODS */

/* PROTECTED METHODS */

/**
 * Calculates and returns how much damage the Monster deals while in battle
 *
 * Needs to be reviewed, I'm sure we could come up with a much better way of doing this.
 *
 * @return int
 *
 * @author Alex Robinson
 */
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

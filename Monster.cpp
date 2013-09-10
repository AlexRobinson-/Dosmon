#include "Monster.h"

#include <string>

#include "BattleMove.h"

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
BattleMove* Monster::requestBattleMove()
{
    BattleMove battleMove;
    return &battleMove;
}

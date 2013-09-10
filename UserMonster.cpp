#include "UserMonster.h"

#include "BattleMove.h"

#include <iostream>

using namespace std;

/* CON/DECON */

UserMonster::UserMonster()
{
    //ctor
}

UserMonster::~UserMonster()
{
    //dtor
}

/* SETS */

void UserMonster::setStatPoints(int statPoints)
{
    this->statPoints = statPoints;
}

void UserMonster::setExperience(int experience)
{
    this->experience = experience;
}

void UserMonster::setMaxExperience(int maxExperience)
{
    this->maxExperience = maxExperience;
}

/* GETS */

int UserMonster::getStatPoints()
{
    return statPoints;
}

int UserMonster::getExperience()
{
    return experience;
}

int UserMonster::getMaxExperience()
{
    return maxExperience;
}

/* METHODS */

BattleMove* UserMonster::requestBattleMove()
{
    string in;
    cout << "What would you like to do? ";
    cin >> in;
    BattleMove battleMove;
    battleMove.setPerformingMonster(0);
    battleMove.setReceivingMonster(1);
    battleMove.setHealth(-2);
    cout << "set battleMove health: " << battleMove.getHealth() << endl;
    return &battleMove;
}

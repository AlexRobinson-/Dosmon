#include "UserMonster.h"

#include "BattleMove.h"
#include "UserAttributeHelper.h"
#include "BasicView.h"

#include <iostream>
#include <cmath>
#include <sstream>

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

void UserMonster::setStatPoints(int statPoints, bool increment)
{
    if(increment)
    {
        this->statPoints += statPoints;
    }else
    {
        this->statPoints = statPoints;
    }
}

void UserMonster::setExperience(int experience, bool increment)
{
    if(increment)
    {
        this->experience += experience;
    }else
    {
        this->experience = experience;
    }

    while(getExperience() >= getMaxExperience())
    {
        this->experience = getExperience() - getMaxExperience();
        setLevel(1);
        BasicView bv;
        bv.printLineBreak('*');
        bv.printMiddleOfBlockNote("Congratulations, you levelled up!");
        stringstream tmpLevel;
        tmpLevel << getLevel();
        bv.printMiddleOfBlockNote("Level " + tmpLevel.str());
        bv.printLineBreak('*');
        bv.pressEnterToContinue();
    }
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

BattleMove UserMonster::requestBattleMove(string action)
{
    BattleMove battleMove;
    battleMove.setPerformingMonster(0);

    if(action == "Attack")
    {
        int rand = /* RANDOM NUMBER */ 2;
        int calculateAttackHealth = calculateAttack();
        battleMove.setHealth(calculateAttackHealth);
        battleMove.setReceivingMonster(1);
    }else if(action == "Heal")
    {
        battleMove.setHealth(2);
        battleMove.setReceivingMonster(0);
    }

    return battleMove;
}

void UserMonster::loadLevelAttributes()
{
    setMaxHealth(UserAttributeHelper::calculateMaxHealth(getLevel()));
    setMaxExperience(UserAttributeHelper::calculateMaxExperience(getLevel()));
    setStatPoints(UserAttributeHelper::calculateStatPoints(getLevel()));
}

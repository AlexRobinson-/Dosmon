#include "UserMonster.h"

#include "BattleMove.h"
#include "UserAttributeHelper.h"
#include "BasicView.h"

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

/* CON/DECON */

/**
 * UserMonster constructor
 *
 * @author Alex Robinson
 */
UserMonster::UserMonster()
{
    //ctor
}

/**
 * UserMonster destructor
 *
 * @author Alex Robinson
 */
UserMonster::~UserMonster()
{
    //dtor
}

/* SETS */

/**
 * Sets the stat points for the UserMonster
 *
 * Boolean increment is true as the default, change to false if you want to set the statPoints to the given value (for example the initial set on load up).
 * Otherwise leave the parameter as true and pass in the amount you want to change the stat points by.
 * Passing in a positive number will add stat points, a negative number will take away the given int from the stat points.
 *
 * @param int statPoints
 * @param bool increment
 *
 * @return void
 *
 * @author Alex Robinson
 */
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

/**
 * Sets the experience points for the UserMonster
 *
 * Boolean increment is true as the default, change to false if you want to set the experience points to the given value (for example the initial set on load up).
 * Otherwise leave the parameter as true and pass in the amount you want to change the experience points by.
 * Passing in a positive number will add experience points, a negative number will take away the given int from the experience points.
 *
 * This method will also check to see if the user has reached their max experience points for this level and continue levelling the UserMonster up
 * and levelling the UserMonster up until their experience points are less than the max experience points.
 * A block note will also be printed explaining that the user has levelled up (this may be moved to the setLevel() method.
 *
 * @param int experience
 * @param bool increment
 *
 * @return void
 *
 * @author Alex Robinson
 */
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

/**
 * Sets the max experience for the UserMonster
 *
 * This method is under review as the max experience is a calculated value and doesn't neccessarily need to be stored in the object
 *
 * @param int experience
 * @param bool increment
 *
 * @return void
 *
 * @author Alex Robinson
 */
void UserMonster::setMaxExperience(int maxExperience)
{
    this->maxExperience = maxExperience;
}

/* GETS */

/**
 * Returns how many stat points the UserMonster has
 *
 * @return int
 *
 * @author Alex Robinson
 */
int UserMonster::getStatPoints()
{
    return statPoints;
}

/**
 * Returns how many experience points the UserMonster has
 *
 * @return int
 *
 * @author Alex Robinson
 */
int UserMonster::getExperience()
{
    return experience;
}

/**
 * Returns the maximum experience for the current level for the UserMonster
 *
 * This method is under review as the max experience is a calculated value and doesn't neccessarily need to be stored in the object
 *
 * @return int
 *
 * @author Alex Robinson
 */
int UserMonster::getMaxExperience()
{
    return maxExperience;
}

/* METHODS */

/**
 * Generates and returns a BattleMove dependant on the action provided
 *
 * Takes 2 options at the moment, Attack and Heal.
 * For the action Attack, the calculateAttack() method is called to generate how much damage the UserMonster will deal.
 * The action Heal is still under development, at the moment it will always heal 2 health points.
 *
 * @param string action
 *
 * @return BattleMove
 *
 * @author Alex Robinson
 */
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

/**
 * Loads the level based attributes and assigns them to the UserMonster
 *
 * These values at the moment include max health, max experience and stat points.
 * Statpoints us under review as the user may just receive 5 per level up, but again, this is yet to be decided.
 *
 * @return void
 *
 * @author Alex Robinson
 */
void UserMonster::loadLevelAttributes()
{
    setMaxHealth(UserAttributeHelper::calculateMaxHealth(getLevel()));
    setMaxExperience(UserAttributeHelper::calculateMaxExperience(getLevel()));
    setStatPoints(UserAttributeHelper::calculateStatPoints(getLevel()));
}

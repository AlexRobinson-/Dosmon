#include "AIMonster.h"

#include "BattleMove.h"
#include "UserAttributeHelper.h"

#include <iostream>

using namespace std;

/* CON/DECON */

/**
 * AIMonster constructor
 *
 * @author Alex Robinson
 */
AIMonster::AIMonster()
{
    //ctor
}

/**
 * AIMonster destructor
 *
 * @author Alex Robinson
 */
AIMonster::~AIMonster()
{
    //dtor
}

/* METHODS */

/**
 * Calls all relevant methods to set up level dependant attributes (max health)
 *
 * @return void
 *
 * @author Alex Robinson
 */
void AIMonster::loadLevelAttributes()
{
    setMaxHealth(UserAttributeHelper::calculateMaxHealth(getLevel()));
}

/**
 * Requests the AIMonster for a BattleMove
 *
 * TODO
 *
 * Here is where AI logic will need to be implemented, the AIMonster will need to calculate whether attacking, healing or
 * using an item is the best course of action and then carry out with that move.
 * At the moment, the AIMonster will always attack.
 *
 * @param string action Used to override certain elements
 *
 * @return BattleMove Object containing the move attributes
 *
 * @author Alex Robinson
 */
BattleMove AIMonster::requestBattleMove(string action)
{
    BattleMove battleMove;
    battleMove.setPerformingMonster(1);
    battleMove.setReceivingMonster(0);
    battleMove.setHealth(calculateAttack());
    return battleMove;
}

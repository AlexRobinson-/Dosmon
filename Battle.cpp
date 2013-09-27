#include "Battle.h"

/* CON/DECON */

/**
 * Battle constructor
 *
 * @author Alex Robinson
 */
Battle::Battle()
{
    //ctor
}

/**
 * Battle destructor
 *
 * @author Alex Robinson
 */
Battle::~Battle()
{
    //dtor
}

/* SETS */

/**
 * Sets who's turn it is, using 0 or 1 to represent which monster
 *
 * 0 = UserMonster
 * 1 = AIMonster
 *
 * @param int turn
 *
 * @return void
 *
 * @author Alex Robinson
 */
void Battle::setTurn(int turn)
{
    this->turnTracker = turn;
}

/* GETS */

/**
 * Returns who's turn it is
 *
 * 0 = UserMonster
 * 1 = AIMOnster
 *
 * @return int
 *
 * @author Alex Robinson
 */
int Battle::getTurn()
{
    return this->turnTracker;
}

/* METHODS */

/**
 * Decides who should go first
 *
 * TO DO
 *
 * This should be a random function to determine who should go first, at the moment the user will always go first.
 *
 * @return void
 *
 * @author Alex Robinson
 */
void Battle::decideBattleOrder()
{
    this->turnTracker = 0;
}

/**
 * Simple toggle to switch to the next Monster's turn
 *
 * 0 = UserMonster
 * 1 = AIMonster
 *
 * @return void
 *
 * @author Alex Robinson
 */
void Battle::updateTurn()
{
    if(this->turnTracker == 0)
    {
        ++this->turnTracker;
    }else if(this->turnTracker == 1)
    {
        --this->turnTracker;
    }
}

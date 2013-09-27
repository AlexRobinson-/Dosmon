#include "BattleMove.h"

/* CON/DECON */

/**
 * BattleMove constructor
 *
 * @author Alex Robinson
 */
BattleMove::BattleMove()
{
    //ctor
}

/**
 * BattleMove destructor
 *
 * @author Alex Robinson
 */
BattleMove::~BattleMove()
{
    //dtor
}

/* SETS */

/**
 * Sets who the performing monster is
 *
 * The performing monster for example would be the attacking monster.
 *
 * @param int performingMonster
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleMove::setPerformingMonster(int performingMonster)
{
    this->performingMonster = performingMonster;
}

/**
 *
 */
void BattleMove::setReceivingMonster(int receivingMonster)
{
    this->receivingMonster = receivingMonster;
}

/**
 * Sets the health for the BattleMove
 *
 * If the value is a positive (+) value, it will heal the receiving monster.
 * If the value is a negative (-) value, it will attack/harm the receiving monster.
 *
 * @param int health
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleMove::setHealth(int health)
{
    this->health = health;
}

/* GETS */

/**
 * Returns the performing monster
 *
 * @return int
 *
 * @author Alex Robinson
 */
int BattleMove::getPerformingMonster()
{
    return this->performingMonster;
}

/**
 * Returns the receiving monster
 *
 * @return int
 *
 * @author Alex Robinson
 */
int BattleMove::getReceivingMonster()
{
    return this->receivingMonster;
}

/**
 * Returns the health attribute of the BattleMove
 *
 * @return int
 *
 * @author Alex Robinson
 */
int BattleMove::getHealth()
{
    return this->health;
}

#include "BattleUserVsComp.h"

#include "UserMonster.h"
#include "AIMonster.h"

#include <iostream>
#include <cmath>

#include "BattleMove.h"
#include "Battle.h"

using namespace std;

/* CON/DECON */

/**
 * BattleUserVsComp constrcutor
 *
 * @author Alex Robinson
 */
BattleUserVsComp::BattleUserVsComp()
{
    //ctor
}

/**
 * BattleUserVsComp destructor
 *
 * @author Alex Robinson
 */
BattleUserVsComp::~BattleUserVsComp()
{
    //dtor
}

/* SETS */

/**
 * Sets the pointer to the UserMonster object
 *
 * @param UserMonster* userMonster Points to the original UserMonster object
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleUserVsComp::setUserMonster(UserMonster* userMonster)
{
    this->userMonster = userMonster;
}

/**
 * Sets the pointer to the AIMonster object
 *
 * @param AIMonster* aiMonster Points to the original AIMonster object
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleUserVsComp::setAIMonster(AIMonster* aiMonster)
{
    this->aiMonster = aiMonster;
}

/* GETS */

/**
 * Returns a pointer to the UserMonster object
 *
 * @return UserMonster*
 *
 * @author Alex Robinson
 */
UserMonster* BattleUserVsComp::getUserMonster()
{
    return this->userMonster;
}

/**
 * Returned a pointer to the AIMonster object
 *
 * @return AIMonster*
 *
 * @author Alex Robinson
 */
AIMonster* BattleUserVsComp::getAIMonster()
{
    return this->aiMonster;
}

/* METHODS */

/**
 * Method under review, we may not need this method anymore
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleUserVsComp::nextMove()
{
    /*
    BattleMove *battleMove;
    if(this->getTurn() == 0)
    {
        battleMove = this->getUserMonster()->requestBattleMove();
    }else if(this->getTurn() == 1)
    {
        battleMove = this->getAIMonster()->requestBattleMove();
    }
    updateTurn();
    executeBattleMove(*battleMove);
    */
}

/**
 * Loads the current screen and returns which screen to load next
 *
 * Accepts the current screen to load and gives the option for the next screen to load, this is to override whatever screen
 * would normally be opened next.
 *
 * @param BattleMove* battleMove
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleUserVsComp::executeBattleMove(BattleMove* battleMove)
{
    if(battleMove->getReceivingMonster() == 0)
    {
        int tempHealth = this->getUserMonster()->getHealth() + battleMove->getHealth();
        this->getUserMonster()->setHealth(tempHealth);
    }else if(battleMove->getReceivingMonster() == 1)
    {
        int tempHealth = this->getAIMonster()->getHealth() + battleMove->getHealth();
        this->getAIMonster()->setHealth(tempHealth);
    }else
    {
        cout << "Something went wrong, receivingMonster = " << battleMove->getReceivingMonster() << endl;
    }
}

/**
 * Calculates the amount of experience to give the User if they win the Battle
 *
 * @return int Experience points
 *
 * @author Alex Robinson
 */
int BattleUserVsComp::calculateExperiencePoints()
{
    int exp = pow(expLevel, getUserMonster()->getLevel()) * pow(expDiff, getUserMonster()->getLevel() - getAIMonster()->getLevel());
    cout << "EXP = " << exp << endl;
    return exp;
}

/* PRIVATE METHODS */



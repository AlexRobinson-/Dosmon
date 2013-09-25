#include "BattleUserVsComp.h"

#include "UserMonster.h"
#include "AIMonster.h"

#include <iostream>
#include <cmath>

#include "BattleMove.h"
#include "Battle.h"

using namespace std;

/* CON/DECON */

BattleUserVsComp::BattleUserVsComp()
{
    //ctor
}

BattleUserVsComp::~BattleUserVsComp()
{
    //dtor
}

/* SETS */
void BattleUserVsComp::setUserMonster(UserMonster* userMonster)
{
    this->userMonster = userMonster;
}

void BattleUserVsComp::setAIMonster(AIMonster* aiMonster)
{
    this->aiMonster = aiMonster;
}

/* GETS */

UserMonster* BattleUserVsComp::getUserMonster()
{
    return this->userMonster;
}

AIMonster* BattleUserVsComp::getAIMonster()
{
    return this->aiMonster;
}

/* METHODS */

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

int BattleUserVsComp::calculateExperiencePoints()
{
    int exp = pow(expLevel, getUserMonster()->getLevel()) * pow(expDiff, getUserMonster()->getLevel() - getAIMonster()->getLevel());
    cout << "EXP = " << exp << endl;
    return exp;
}

/* PRIVATE METHODS */



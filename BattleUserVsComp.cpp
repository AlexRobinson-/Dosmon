#include "BattleUserVsComp.h"

#include "UserMonster.h"
#include "AIMonster.h"

#include <iostream>

class BattleMove;
class Battle;

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
    BattleMove *battleMove;
    cout << "Current turn: " << this->getTurn() << endl;
    if(this->getTurn() == 0)
    {
        battleMove = this->getUserMonster()->requestBattleMove();
    }else if(this->getTurn() == 1)
    {
        battleMove = this->getAIMonster()->requestBattleMove();
    }
    updateTurn();
    executeBattleMove(*battleMove);

}

/* PRIVATE METHODS */

void BattleUserVsComp::executeBattleMove(BattleMove battleMove)
{
    if(battleMove.getReceivingMonster() == 0)
    {
        int tempHealth = this->getUserMonster()->getHealth() + battleMove.getHealth();
        this->getAIMonster()->setHealth(tempHealth);
    }else if(battleMove.getReceivingMonster() == 1)
    {
        int tempHealth = this->getAIMonster()->getHealth() + battleMove.getHealth();
        this->getAIMonster()->setHealth(tempHealth);
        cout << "Set AIMonster health: " << this->getAIMonster()->getHealth() << endl << "tempHealth = " << tempHealth << endl << endl;
    }else
    {
        cout << "Something went wrong, receivingMonster = " << battleMove.getReceivingMonster() << endl;
    }
}

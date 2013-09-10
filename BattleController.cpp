#include "BattleController.h"

#include <iostream>

#include "UserMonster.h"
#include "AIMonster.h"
#include "BattleMove.h"
#include "BattleUserVsComp.h"

using namespace std;

/* CON/DECON */
BattleController::BattleController(UserMonster* userMonster, AIMonster* aiMonster)
{
    cout << "about to set aiMonster: " << aiMonster->getHealth() << " " << userMonster->getHealth() << endl;
    BattleUserVsComp tempBattleObject;
    this->battleObject = &tempBattleObject;
    this->battleObject->setUserMonster(userMonster);
    this->battleObject->setAIMonster(aiMonster);
    this->battleObject->decideBattleOrder();

    battle();
}

BattleController::~BattleController()
{
    //dtor
}

/* METHODS */

void BattleController::decideBattleOrder()
{

}
bool BattleController::battle()
{
    cout << "Battle began" << endl;
    while(this->battleObject->getUserMonster()->getHealth() > 0 && this->battleObject->getAIMonster()->getHealth() > 0)
    {
        cout << "aiMonster: " << this->battleObject->getAIMonster()->getHealth() << " > 0" << endl;
        this->battleObject->nextMove();
    }
    cout << "Battle finished!" << endl;
    return false;
}

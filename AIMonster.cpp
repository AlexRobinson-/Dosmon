#include "AIMonster.h"

#include "BattleMove.h"
#include "UserAttributeHelper.h"

#include <iostream>

using namespace std;

AIMonster::AIMonster()
{
    //ctor
}

AIMonster::~AIMonster()
{
    //dtor
}

void AIMonster::loadLevelAttributes()
{
    setMaxHealth(UserAttributeHelper::calculateMaxHealth(getLevel()));
}

BattleMove AIMonster::requestBattleMove(string action)
{
    BattleMove battleMove;
    battleMove.setPerformingMonster(1);
    battleMove.setReceivingMonster(0);
    battleMove.setHealth(calculateAttack());
    return battleMove;
}

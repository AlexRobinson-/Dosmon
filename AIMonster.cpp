#include "AIMonster.h"

#include "BattleMove.h"

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

BattleMove* AIMonster::requestBattleMove()
{
    BattleMove battleMove;
    battleMove.setPerformingMonster(0);
    battleMove.setReceivingMonster(1);
    battleMove.setHealth(-2);
    return &battleMove;
}

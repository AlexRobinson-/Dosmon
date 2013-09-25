#include "AIMonsterGenerator.h"

#include "AIMonster.h";
#include "UserMonster.h";

#include <iostream>

using namespace std;

/* CON/DECON */

AIMonsterGenerator::AIMonsterGenerator()
{
    //ctor
}

AIMonsterGenerator::~AIMonsterGenerator()
{
    //dtor
}

/* METHODS */

void AIMonsterGenerator::generateMonster(AIMonster* aiMonster, UserMonster* monsterToBattle)
{
    aiMonster->setLevel(monsterToBattle->getLevel(), false);
    aiMonster->setAttack(monsterToBattle->getAttack());
    aiMonster->setHealth(monsterToBattle->getMaxHealth());
    aiMonster->setMonsterName("A monster");
}

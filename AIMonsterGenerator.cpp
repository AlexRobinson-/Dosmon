#include "AIMonsterGenerator.h"

#include "AIMonster.h";
#include "UserMonster.h";

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

AIMonster AIMonsterGenerator::generateMonster(UserMonster* monsterToBattle)
{
    AIMonster aiMonster;
    aiMonster.setLevel(monsterToBattle->getLevel());
    aiMonster.setAttack(monsterToBattle->getAttack());
    aiMonster.setHealth(monsterToBattle->getMaxHealth());
    aiMonster.setMaxHealth(monsterToBattle->getMaxHealth());
    aiMonster.setMonsterName("A monster");
    return aiMonster;
}

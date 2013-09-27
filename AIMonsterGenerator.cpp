#include "AIMonsterGenerator.h"

#include "AIMonster.h";
#include "UserMonster.h";

#include <iostream>

using namespace std;

/* CON/DECON */

/**
 * AIMonsterGenerator constructor
 *
 * @author Alex Robinson
 */
AIMonsterGenerator::AIMonsterGenerator()
{
    //ctor
}

/**
 * AIMonster destructor
 *
 * @author Alex Robinson
 */
AIMonsterGenerator::~AIMonsterGenerator()
{
    //dtor
}

/* METHODS */

/**
 * Generates an AIMonster, who's attributes will be based on the monster it is to be battling
 *
 * @param AIMonster* aiMonster Points to the object to assign all of the values to
 * @param UserMonster* monsterToBattle Points to the Monster object the AIMonster will be battling
 *
 * @return void
 *
 * @author Alex Robinson
 */
void AIMonsterGenerator::generateMonster(AIMonster* aiMonster, UserMonster* monsterToBattle)
{
    aiMonster->setLevel(monsterToBattle->getLevel(), false);
    aiMonster->setAttack(monsterToBattle->getAttack());
    aiMonster->setHealth(monsterToBattle->getMaxHealth());
    aiMonster->setMonsterName("A monster");
}

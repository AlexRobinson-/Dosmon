#include "BattleMove.h"

/* CON/DECON */

BattleMove::BattleMove()
{
    //ctor
}

BattleMove::~BattleMove()
{
    //dtor
}

/* SETS */

void BattleMove::setPerformingMonster(int performingMonster)
{
    this->performingMonster = performingMonster;
}

void BattleMove::setReceivingMonster(int receivingMonster)
{
    this->receivingMonster = receivingMonster;
}

void BattleMove::setHealth(int health)
{
    this->health = health;
}

/* GETS */

int BattleMove::getPerformingMonster()
{
    return this->performingMonster;
}

int BattleMove::getReceivingMonster()
{
    return this->receivingMonster;
}

int BattleMove::getHealth()
{
    return this->health;
}

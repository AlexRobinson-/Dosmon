#include "Battle.h"

/* CON/DECON */
Battle::Battle()
{
    //ctor
}

Battle::~Battle()
{
    //dtor
}

/* SETS */
void Battle::setTurn(int turn)
{
    this->turnTracker = turn;
}

/* GETS */
int Battle::getTurn()
{
    return this->turnTracker;
}

/* METHODS */
void Battle::decideBattleOrder()
{
    this->turnTracker = 0;
}

void Battle::updateTurn()
{
    if(this->turnTracker == 0)
    {
        ++this->turnTracker;
    }else if(this->turnTracker == 1)
    {
        --this->turnTracker;
    }
}

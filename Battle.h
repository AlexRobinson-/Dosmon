#ifndef BATTLE_H
#define BATTLE_H

#include "BattleAttack.h"
#include "UserMonster.h"
#include "AIMonster.h"

class Battle
{
    public:
        /* CON/DECON */
        Battle();
        virtual ~Battle();

        /* SETS */
        void setTurn(int);

        /* GETS */
        int getTurn();

        /* METHODS */
        void decideBattleOrder();
        void updateTurn();
    protected:
    private:
        /* ATTRIBUTES */
        int turnTracker;

};

#endif // BATTLE_H

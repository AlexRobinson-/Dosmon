#ifndef AIMONSTER_H
#define AIMONSTER_H

#include "Monster.h"
#include "BattleMove.h"


class AIMonster: public Monster
{
    public:
        /* CON/DECON */
        AIMonster();
        virtual ~AIMonster();

        /* METHODS */
        BattleMove* requestBattleMove();

    protected:
    private:
};

#endif // AIMONSTER_H

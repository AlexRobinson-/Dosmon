#ifndef BATTLEUSERVSCOMP_H
#define BATTLEUSERVSCOMP_H

#include "Battle.h"
class BattleMove;
class UserMonster;
class AIMonster;

class BattleUserVsComp: public Battle
{
    public:
        /* CON/DECON */
        BattleUserVsComp();
        virtual ~BattleUserVsComp();

        /* SETS */
        void setUserMonster(UserMonster*);
        void setAIMonster(AIMonster*);

        /* GETS */
        UserMonster* getUserMonster();
        AIMonster* getAIMonster();

        /* METHODS */
        void nextMove();

    protected:
    private:
        /* METHODS */
        void executeBattleMove(BattleMove);

        /* ATTRIBUTES */
        UserMonster* userMonster;
        AIMonster* aiMonster;
};

#endif // BATTLEUSERVSCOMP_H

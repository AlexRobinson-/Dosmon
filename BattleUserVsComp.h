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
        void executeBattleMove(BattleMove*);
        int calculateExperiencePoints();

    protected:
    private:
        /* METHODS */


        /* ATTRIBUTES */
        UserMonster* userMonster;
        AIMonster* aiMonster;

        const double expLevel = 1.3;
        const double expDiff = 1.4;
        const double minDiff = -5;
        const double levelUpExp = 1.4;
        const double minExp = 3;
};

#endif // BATTLEUSERVSCOMP_H

#ifndef USERMONSTER_H
#define USERMONSTER_H

#include "Monster.h"
#include "BattleMove.h"

/**
UserMonster

- This is the user's monster

*/

class UserMonster: public Monster
{
    public:
        /* CON/DECON */
        UserMonster();
        virtual ~UserMonster();

        /* SETS */
        void setStatPoints(int);
        void setExperience(int);
        void setMaxExperience(int);

        /* GETS */
        int getStatPoints();
        int getExperience();
        int getMaxExperience();

        /* METHODS */
        BattleMove* requestBattleMove();
    protected:
    private:
        /* ATTRIBUTES */
        int statPoints;
        int experience;
        int maxExperience;
};

#endif // USERMONSTER_H

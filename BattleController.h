#ifndef BATTLECONTROLLER_H
#define BATTLECONTROLLER_H

#include "UserMonster.h"
#include "AIMonster.h"
#include "BattleUserVsComp.h"

/**
BattleHandler

- Takes in the 2 monster objects
- Controls the role based battle system

*/

class BattleController
{
    public:
        /* CON/DECON */
        BattleController(UserMonster*, AIMonster*);
        virtual ~BattleController();

        /* METHODS */
        void decideBattleOrder();
        bool battle();
    protected:
    private:
        BattleUserVsComp* battleObject;
};

#endif // BATTLECONTROLLER_H

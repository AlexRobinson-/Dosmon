#ifndef BATTLECONTROLLER_H
#define BATTLECONTROLLER_H

#include "Controller.h"

#include <vector>
#include <string>

class UserMonster;
class AIMonster;
class BattleUserVsComp;
class BattleView;
class BattleMove;

/**
BattleHandler

- Takes in the 2 monster objects
- Controls the role based battle system

*/

class BattleController: public Controller
{
    public:
        /* CON/DECON */
        BattleController(User*, AIMonster*);
        virtual ~BattleController();

        /* METHODS */
        void decideBattleOrder();
        void performAction(std::string);
        int battle();
        BattleMove decideUserMove(BattleView*);

        /* ATTRIBUTES */

    protected:
    private:
        std::vector<std::string> chooseBattleMoveMenu;
        std::vector<std::string> moveOnFromCurrent;

        BattleUserVsComp* battleObject;
        AIMonster* tmpAIMonster;
        BattleView* battleView;
};

#endif // BATTLECONTROLLER_H

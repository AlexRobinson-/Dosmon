#ifndef BATTLEVIEW_H
#define BATTLEVIEW_H

#include "View.h"

class UserMonster;
class AIMonster;
class User;
class BattleMove;

class BattleView: public View
{
    public:
        /* CON/DECON */
        BattleView();
        virtual ~BattleView();

        void assignRefToUser(User*);
        void assignRefToAIMonster(AIMonster*);
        void attachBattleMove(BattleMove*);
        void displayMenuView();
        void displayMoveResultView();
        void displayBattleResults(int, int = 0);
    protected:
    private:
        /* METHODS */
        void displayBattleMove();
        void displayBattleViewHeader();

        /* ATTRIBUTES */
        User* user;
        AIMonster* aiMonster;

        BattleMove* battleMove = 0;

        bool battleMoveAttached = false;
};

#endif // BATTLEVIEW_H

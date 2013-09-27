#include "BattleController.h"

#include <iostream>
#include <vector>
#include <limits>

/* MODELS */
#include "UserMonster.h";
#include "AIMonster.h";
#include "BattleMove.h";
#include "BattleUserVsComp.h";
#include "AIMonsterGenerator.h";

/* VIEWS */
#include "BattleView.h";

/* CONTROLLERS */
#include "MainController.h";

/* ATTRIBUTES */

using namespace std;


/* CON/DECON */
/**
 * BattleController constructor
 *
 * Sets up the Battle System, accepts a pointer to the User and the AIMonster the user will be battling.
 * Creates the BattleObject, sets initial values and calls the battle() method which contains the main battle loop.
 *
 * @param User* user
 * @param AIMonster* aiMonster
 *
 * @author Alex Robinson
 */

BattleController::BattleController(User* user, AIMonster* aiMonster)
{
    BattleUserVsComp tempBattleObject;
    this->battleObject = &tempBattleObject;
    this->user = user;
    this->battleObject->setUserMonster(user->getMonster());
    this->battleObject->setAIMonster(aiMonster);
    this->battleObject->decideBattleOrder();
    BattleView battleView;
    this->battleView = &battleView;
    int loser = battle();

    if(loser == 1)
    {
        int exp = battleObject->calculateExperiencePoints();
        this->battleView->displayBattleResults(loser, exp);
        battleObject->getUserMonster()->setExperience(exp, true);
    }else
    {
        this->battleView->displayBattleResults(loser);
    }
}

/**
 * BattleController destructor

 *
 * @author Alex Robinson
 */
BattleController::~BattleController()
{
    //dtor
}

/* METHODS */

/**
 *
 */
void BattleController::performAction(string action)
{

}

/**
 * Requests the user for their next move/action
 *
 * Accepts the current BattleView as a pointer as a dirty work around for keeping the GUI object.
 *
 * @param BattleView* battleView
 *
 * @return BattleMove Contains the move/action information for the user's move.
 *
 * @author Alex Robinson
 */
BattleMove BattleController::decideUserMove(BattleView* battleView)
{
    /* MENU */
    vector<string> actions(4);
    actions.at(0) = "Attack";
    actions.at(1) = "Heal";
    actions.at(2) = "Use Item";
    actions.at(3) = "Flee";

    battleView->setActions(actions);

    battleView->displayMenuView();

    int userInput;
    string action = actions.at(requestInput("What would you like to do?"));
    BattleMove battleMove;
    if(action == "User Item")
    {
        // go to use item view
    }else if(action == "flee")
    {
        // exit battle
    }else
    {
        battleMove = user->getMonster()->requestBattleMove(action);
    }
    return battleMove;
}

/**
 * The main battle loop
 *
 * While both monster's health is more than 0, continue requesting a battle moves from the User and the AIMonster in
 * an alternating manner. The results are returned in an int.
 * 0 = User has lost
 * 1 = AIMonster has lost
 * 2 = Error has occured
 * 3 = Draw
 *
 * @return int The loser of the battle
 *
 * @author Alex Robinson
 */
int BattleController::battle()
{
    battleView->assignRefToUser(this->user);
    battleView->assignRefToAIMonster(this->battleObject->getAIMonster());
    while(battleObject->getUserMonster()->getHealth() > 0 && battleObject->getAIMonster()->getHealth() > 0)
    {
        BattleMove battleMove;
        if(battleObject->getTurn() == 0)
        {
            battleMove = decideUserMove(battleView);
            battleView->setNote(battleObject->getUserMonster()->getMonsterName() + "'s turn");
        }else if(battleObject->getTurn() == 1)
        {
            battleMove = battleObject->getAIMonster()->requestBattleMove();
            battleView->setNote(battleObject->getAIMonster()->getMonsterName() + "'s turn");
        }
        battleView->attachBattleMove(&battleMove);
        battleObject->updateTurn();
        battleObject->executeBattleMove(&battleMove);

        battleView->displayMoveResultView();
        battleView->pressEnterToContinue();
    }

    if(battleObject->getUserMonster()->getHealth() < 1 && battleObject->getAIMonster()->getHealth() < 1)
    {
        // draw (both lose)
        return 3;
    }
    if(battleObject->getUserMonster()->getHealth() < 1)
    {
        return 0;
    }else if(battleObject->getAIMonster()->getHealth() < 1)
    {
        return 1;
    }else
    {
        // error
        return 2;
    }
}

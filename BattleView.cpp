#include "BattleView.h"

#include "AIMonster.h"
#include "UserMonster.h"
#include "User.h"
#include "BattleView.h"

#include <iostream>

using namespace std;

/* CON/DECON */

/**
 * BattleView constructor
 *
 * @author Alex Robinson
 */
BattleView::BattleView()
{
    //ctor
}

/**
 * BattleView destructor
 *
 * @author Alex Robinson
 */
BattleView::~BattleView()
{
    //dtor
}

/* SETS */

/**
 * Assigns a local pointer to the original User object for easy access
 *
 * @param User* user
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleView::assignRefToUser(User* user)
{
    this->user = user;
}

/**
 * Assigns a local pointer to the original AIMonster object for easy access
 *
 * @param AIMonster* aiMonster
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleView::assignRefToAIMonster(AIMonster* aiMonster)
{
    this->aiMonster = aiMonster;
}

/**
 * Assigns a local pointer to the original BattleMove object for easy access
 *
 * Also sets the battleMoveAttached to true, to alert the printing methods that a BattleMove has been executed and needs to be
 * shown
 *
 * @param BattleMove* battleMove
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleView::attachBattleMove(BattleMove* battleMove)
{
    battleMove = battleMove;
    this->battleMoveAttached = true;
}

/* METHODS */

/**
 * Prints the menu view, which will print out what actions the User can choose
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleView::displayMenuView()
{
    displayBattleViewHeader();
    printActions();
}

/**
 * Prints the BattleMove view, which shows details on what the most recent BattleMove has done
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleView::displayMoveResultView()
{
    displayBattleViewHeader();
    displayBattleMove();
}

/* PRIVATE METHODS */

/**
 * The actual process and method for printing out the BattleMove
 *
 * This method will only print out the past BattleMethod if a BattleMove has been attached.
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleView::displayBattleMove()
{
    if(this->battleMove == 0)
    {
        cout << "Error: no battle move attached" << endl;
    }

    if(this->battleMove->getPerformingMonster() == 0)
    {
        cout << this->user->getMonster()->getMonsterName();
    }else if(this->battleMove->getPerformingMonster() == 1)
    {
        cout << this->aiMonster->getMonsterName();
    }else
    {
        cout << endl << "Error: no performing monster found" << endl;
    }

    if(this->battleMove->getHealth() < 0)
    {
        cout << " attacked";
    }else if(this->battleMove->getHealth() > 0)
    {
        cout << " healed";
    }else
    {
        cout << " missed";
    }

    if(this->battleMove->getReceivingMonster() == this->battleMove->getPerformingMonster())
    {
        cout << " itsself";
    }
    else if(this->battleMove->getReceivingMonster() == 0)
    {
        cout << " " << this->user->getMonster()->getMonsterName();
    }else if(this->battleMove->getReceivingMonster() == 1)
    {
        cout << " " << aiMonster->getMonsterName();
    }else
    {
        cout << endl << "Error: no receiving monster found" << endl;
    }

    cout << ", " << battleMove->getHealth() << " health" << endl;

    battleMoveAttached = false;
}

/**
 * Prints out the header for the Battle View
 *
 * This includes the attribute bars for the AIMonster and the UserMonster plus all of the usual stuff
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleView::displayBattleViewHeader()
{
    printVerticalWhiteSpace();
    if(noteActive())
    {
        cout << getNote() << endl;
    }
    printTitle();
    printLineBreak();
    printAccountInfoBar("Wild Dosmon", aiMonster->getMonsterName(), aiMonster->getLevel());
    printAttributeBar(aiMonster->getHealth(), aiMonster->getMaxHealth(), "Health");
    printLineBreak(' ');
    printAccountInfoBar(this->user->getName(), this->user->getMonster()->getMonsterName(), this->user->getMonster()->getLevel());
    printAttributeBar(this->user->getMonster()->getHealth(), this->user->getMonster()->getMaxHealth(), "Health");
    printAttributeBar(this->user->getMonster()->getExperience(), this->user->getMonster()->getMaxExperience(), "Exp");
    printLineBreak(' ');
}

/**
 * Prints out the battle results
 *
 * If the User wins, the experience points gained will need be passed in through the second parameter. Currently there is
 * no other use for the second parameter
 *
 * @param int loser 0 = you lost, 1 = AIMonster lost, 2 = error, 3 = draw
 * @param int extra
 *
 * @return void
 *
 * @author Alex Robinson
 */
void BattleView::displayBattleResults(int loser, int extra)
{
    printVerticalWhiteSpace();
    if(loser == 0)
    {
        cout << "You lost!" << endl;
    }else if(loser == 1)
    {
        printBlockNote("Congratulations! You Won!!");
        cout << "You gained " << extra << "xp!" << endl;
        printAttributeBar((this->user->getMonster()->getExperience() + extra), this->user->getMonster()->getMaxExperience(), "Exp");
    }else if(loser == 3)
    {
        cout << "Draw" << endl;
    }else if(loser == 2)
    {
        cout << "Error: Something went wrong, check out the battle() method" << endl;
    }
    pressEnterToContinue();
}

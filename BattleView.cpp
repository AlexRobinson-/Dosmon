#include "BattleView.h"

#include "AIMonster.h"
#include "UserMonster.h"
#include "User.h"
#include "BattleView.h"

#include <iostream>

using namespace std;

/* CON/DECON */

BattleView::BattleView()
{
    //ctor
}

BattleView::~BattleView()
{
    //dtor
}

/* SETS */

void BattleView::assignRefToUser(User* user)
{
    this->user = user;
}

void BattleView::assignRefToAIMonster(AIMonster* aiMonster)
{
    this->aiMonster = aiMonster;
}

void BattleView::attachBattleMove(BattleMove* battleMoved)
{
    battleMove = battleMoved;
    this->battleMoveAttached = true;
}

/* METHODS */

void BattleView::displayMenuView()
{
    displayBattleViewHeader();
    printActions();
}

void BattleView::displayMoveResultView()
{
    displayBattleViewHeader();
    displayBattleMove();
}

/* PRIVATE METHODS */

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
    }else if(loser == 4)
    {
        cout << "Error: Something went wrong, check out the battle() method" << endl;
    }
    pressEnterToContinue();
}

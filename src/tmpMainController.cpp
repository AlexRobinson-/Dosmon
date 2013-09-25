// Header file
#include "MainController.h"

// Standard C++ includes
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* MODELS */
#include "User.h"
#include "AIMonster.h"
#include "AIMonsterGenerator.h"

/* VIEWS */
#include "BasicView.h"

/* CONTROLLERS */
#include "AccountController.h"
#include "LoggedOutController.h"
#include "BattleController.h"

using namespace std;

/* CON/DECON */

/**
MainController constructor
default action = menu

*/
MainController::MainController()
{

}

MainController::~MainController()
{
    //dtor
}

/* SET UP METHODS */

void MainController::setUpController(User* userObject)
{

}

string MainController::startController(string action)
{
  while(mainIsOpen)
  {
      nextScreen = performAction(nextScreen);
        if(nextScreen == "loggedIn")
        {
            loggedOut =[] false;
        }
  }
}

/* METHODS */

string MainController::performAction(string action)
{

}

void MainController::mainMenu()
{

}

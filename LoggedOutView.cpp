#include "LoggedOutView.h"
#include <iostream>
#include <string>

using namespace std;

LoggedOutView::LoggedOutView()
{
    //ctor
}

LoggedOutView::~LoggedOutView()
{
    //dtor
}

void LoggedOutView::load()
{
    for(int counter = 0;counter < 80;counter++)
    {
        cout << "-";
    }
    printTitle();
    printActions();

}

#include <iostream>
#include <fstream>

/* Models */
#include "User.h"

/* Controllers */
#include "MainController.h"
#include "LoggedOutController.h"

using namespace std;

int main()
{
    /**
    TODO

    If statement here to see if user is still logged in
        If the user is logged in open the main controller
        If the user isn't logged in open the logged out controller

    */
        if(false) {
            User user;
            user.setUsername("This is the username");
            MainController main = MainController(&user);
        }else {
            LoggedOutController loggedOut;
    }

    return 0;
}

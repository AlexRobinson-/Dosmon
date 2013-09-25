#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "User.h"


class Controller
{
    public:
        /* CON/DECON */
        Controller();
        virtual ~Controller();
        void performAction(std::string = "Main");
        int requestInput(std::string = "*replace*", int = -1, bool = false);
        std::string requestStringInput(std::string = "*replace*", bool = false);
        int stringToNumber(std::string);
    protected:
        User* user;
    private:


};

#endif // CONTROLLER_H

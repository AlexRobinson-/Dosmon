#ifndef USERHANDLER_H
#define USERHANDLER_H

/* MODELS */
#include "User.h"

/**
UserHandler

- Registers new accounts
- Logs in users

*/

class UserHandler
{
    public:
        /* CON/DECON */
        UserHandler();
        virtual ~UserHandler();

        bool checkUserExists(std::string);
        void createUser(User);
    protected:
    private:
};

#endif // USERHANDLER_H

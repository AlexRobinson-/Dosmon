#ifndef USER_H
#define USER_H
#include <string>

#include "UserMonster.h"

/**
User

- Handles pre-existing users
- The object that will be used while the game is running/logged in
- Can update/change username and password
- Stores items
- Stores monster id - more information might be needed
*/

class User
{
    public:
        /* CON/DECON */
        User();
        virtual ~User();

        /* SETS */
        void setUsername(std::string);
        void setPassword(std::string);
        void setMonster(UserMonster*);


        /* GETS */
        std::string getUsername();
        std::string getPassword();
        UserMonster* getMonster();

        /* METHODS */
        bool attemptLogin(std::string, std::string, std::string = ".txt");
        bool save(std::string = ".txt");

        /* ATTRIBUTES */

    protected:
    private:
        std::string username = "NOT SET";
        std::string password = "NOT SET";

        UserMonster* monster;
        //todo items
};

#endif // USER_H

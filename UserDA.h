#ifndef USERDA_H
#define USERDA_H

#include <vector>
#include <string>

#include "User.h"


class UserDA
{
    public:
        /* CON/DECON */
        UserDA(User*, std::string = ".txt");
        virtual ~UserDA();

        /* METHODS */
        std::string getAttribute(std::string);
        bool saveUser();
        void loadUser();

        /* ATTRIBUTES */


    protected:
    private:
        /* METHODS */
        std::vector<std::string> splitLine(std::string, std::string = ":");
        void assignAttributeToUserObject(std::vector<std::string>);
        /* ATTRIBUTES */
        std::string extension; // file extension to save to
        const std::string userFolder = "users/"; // location of file storage
        std::string fileName;
        User* user; // User object to get data from

};

#endif // USERDA_H

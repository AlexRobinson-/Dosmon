#ifndef LOGGEDOUTVIEW_H
#define LOGGEDOUTVIEW_H

#include "View.h"

class User;

class LoggedOutView: public View
{
    public:
        LoggedOutView();
        virtual ~LoggedOutView();

        void load();
        void printWelcomeMessage(User*);
    protected:
    private:
};

#endif // LOGGEDOUTVIEW_H

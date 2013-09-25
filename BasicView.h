#ifndef BASICVIEW_H
#define BASICVIEW_H

#include "View.h"

class User;

class BasicView: public View
{
    public:
        /* CON/DECON */
        BasicView();
        virtual ~BasicView();

        void assignRefToUser(User*);

        void loadBasic(int columns = 2);
        void loadFancy(int columns = 2);
    protected:
    private:
        User* user;

};

#endif // BASICVIEW_H

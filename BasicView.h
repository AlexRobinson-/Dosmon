#ifndef BASICVIEW_H
#define BASICVIEW_H
#include <string>
#include <map>

#include "View.h"
#include "User.h"

class BasicView: public View
{
    public:
        /* CON/DECON */
        BasicView();
        virtual ~BasicView();

        void assignRefToUser(User*);
        void load();

    protected:
    private:
        User* user;

};

#endif // BASICVIEW_H

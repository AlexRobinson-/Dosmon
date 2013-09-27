#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include <string>

#include "Controller.h"

class User;

class ShopController: public Controller
{
    public:
        /* CON/DECON */
        ShopController();
        virtual ~ShopController();

        /* METHODS */
        void setUpController(User*);
        void startController(std::string = "Main");

        std::string performAction(std::string = "Main", std::string = "null");
        std::string mainMenu();
    protected:
    private:
};

#endif // SHOPCONTROLLER_H

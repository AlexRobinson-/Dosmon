#ifndef USERATTRIBUTEHELPER_H
#define USERATTRIBUTEHELPER_H


class UserAttributeHelper
{
    public:
        /* CON/DECON */
        UserAttributeHelper();
        virtual ~UserAttributeHelper();

        /* METHODS */
        static int calculateMaxHealth(int);
        static int calculateMaxExperience(int);
    protected:
    private:
};

#endif // USERATTRIBUTEHELPER_H

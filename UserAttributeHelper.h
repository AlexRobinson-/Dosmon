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
        static int calculateStatPoints(int);

        const double expLevel = 1.3;
        const double expDiff = 1.4;
        const double minDiff = -5;
        const double levelUpExp = 1.4;
        const double minExp = 3;

    protected:
    private:
};

#endif // USERATTRIBUTEHELPER_H

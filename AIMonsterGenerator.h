#ifndef AIMONSTERGENERATOR_H
#define AIMONSTERGENERATOR_H

class UserMonster;
class AIMonster;

/**
AIMonsterGenerator

- Generates an AIMonster level based on the user current level
- According to the level will random the attribute points with how many a user has received by said level
- Randomly decide if a monster gets an item
    - quantity
    - type

*/

class AIMonsterGenerator
{
    public:
        /* CON/DECON */
        AIMonsterGenerator();
        virtual ~AIMonsterGenerator();

        /* METHODS */
        static AIMonster generateMonster(UserMonster*);
    protected:
    private:
};

#endif // AIMONSTERGENERATOR_H

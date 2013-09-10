#ifndef MONSTER_H
#define MONSTER_H
#include <string>

class BattleMove;

class Monster
{
    public:
        /* CON/DECON */
        Monster();
        virtual ~Monster();

        /* SETS */
        void setMonsterName(std::string);
        void setLevel(int);
        void setHealth(int);
        void setMaxHealth(int);
        void setAttack(int);

        /* GETS */
        std::string getMonsterName();
        int getLevel();
        int getHealth();
        int getMaxHealth();
        int getAttack();

        /* METHODS */
        virtual BattleMove* requestBattleMove() = 0;

    protected:
    private:
        /* ATTRIBUTES */
        std::string monsterName;
        int level;
        int health;
        int maxHealth;
        int attack;
};

#endif // MONSTER_H

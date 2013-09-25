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
        void setLevel(int, bool = true);
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
        virtual BattleMove requestBattleMove(std::string = "null") = 0;
        virtual void loadLevelAttributes() = 0;

    protected:
        int calculateAttack();
    private:
        /* ATTRIBUTES */
        std::string monsterName;
        int level;
        int health;
        int maxHealth;
        int attack;
};

#endif // MONSTER_H

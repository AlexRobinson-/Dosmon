#ifndef MONSTER_H
#define MONSTER_H
#include <string>

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
        void setStatPoints(int);
        void setExperience(int);
        void setMaxExperience(int);

        /* GETS */
        std::string getMonsterName();
        int getLevel();
        int getHealth();
        int getMaxHealth();
        int getAttack();
        int getStatPoints();
        int getExperience();
        int getMaxExperience();

    protected:
    private:
        /* ATTRIBUTES */
        std::string monsterName;
        int level;
        int health;
        int maxHealth;
        int attack;
        int statPoints;
        int experience;
        int maxExperience;
};

#endif // MONSTER_H

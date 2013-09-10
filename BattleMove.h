#ifndef BATTLEMOVE_H
#define BATTLEMOVE_H


class BattleMove
{
    public:
        /* CON/DECON */
        BattleMove();
        virtual ~BattleMove();

        /* SETS */
        void setPerformingMonster(int);
        void setReceivingMonster(int);
        void setHealth(int);

        /* GETS */
        int getPerformingMonster();
        int getReceivingMonster();
        int getHealth();
    protected:
    private:
        int performingMonster;
        int receivingMonster;
        int health;

};

#endif // BATTLEMOVE_H

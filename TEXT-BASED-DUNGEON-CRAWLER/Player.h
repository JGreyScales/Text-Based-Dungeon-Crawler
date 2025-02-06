#pragma once

#include "items.h"


class Player {
protected:
    unsigned short hp;
    short meleeAttack;
    unsigned short moveDistance;
    //item playerItems[30];

    unsigned int _x;
    unsigned int _y;

    Player(unsigned short HP, short meleeAttack, unsigned short moveDistance);

public:
    void printPlayer();
    unsigned int getX();
    unsigned int getY();
    void setX(unsigned int);
    void setY(unsigned int);

    virtual ~Player();
    virtual void testMethod();
    virtual void displayStats(int);
};

class Warrior : public Player {
public:
    Warrior();
    virtual void testMethod() override;
    void onlyWarrior();
};

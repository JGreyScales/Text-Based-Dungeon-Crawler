#pragma once

#include "items.h"

#include <iostream>

class Player {
protected:
    unsigned short hp;
    short meleeAttack;
    unsigned short moveDistance;
    //item playerItems[30];

    unsigned int x;
    unsigned int y;

    Player(unsigned short HP, short meleeAttack, unsigned short moveDistance);

public:
    void printPlayer();
    unsigned int getX();
    unsigned int getY();
    void setX(unsigned int);
    void setY(unsigned int);

    virtual ~Player();
    virtual void testMethod();
    // https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
    virtual void displayStats();
};

class Warrior : public Player {
public:
    Warrior();
    virtual void testMethod() override;
    void onlyWarrior();
};

#pragma once

class Player {
protected:
    unsigned short hp;
    short meleeAttack;
    unsigned short moveDistance;
    item playerItems[30];

    Player(unsigned short HP, short meleeAttack, unsigned short moveDistance);

public:
    virtual ~Player();
    virtual void testMethod();
    // https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
    void displayStates();
};

class Warrior : public Player {
public:
    Warrior();
    virtual void testMethod() override;
    void onlyWarrior();
};

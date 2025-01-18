#pragma once
class Player {
protected:
	unsigned short hp;
	short meleeAttack;
	unsigned short moveDistance;

	Player(unsigned short HP, short meleeAttack, unsigned short moveDistance);
public:
	virtual ~Player();
	virtual void testMethod();
};


class Warrior : public Player {
public:
	Warrior();
	virtual void testMethod() override;
	void onlyWarrior();
};
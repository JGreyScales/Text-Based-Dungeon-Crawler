#include "Player.h"
class Player {
protected:
	unsigned short hp;
	short meleeAttack;
	unsigned short moveDistance;

	Player(unsigned short HP, short meleeAttack, unsigned short moveDistance) : 
	hp(HP), meleeAttack(meleeAttack), moveDistance(moveDistance) {}
public:
	virtual ~Player() {}
	virtual void testMethod() {};
};


class Warrior : public Player {
public:
	Warrior() : Player(20, 5, 1) {}
	void testMethod() override { return; };
	void onlyWarrior() { return; };
};
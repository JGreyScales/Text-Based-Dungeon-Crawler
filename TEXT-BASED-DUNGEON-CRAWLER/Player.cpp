#include "Player.h"

Player::Player(unsigned short HP, short meleeAttack, unsigned short moveDistance)
    : hp(HP), meleeAttack(meleeAttack), moveDistance(moveDistance) {}

Player::~Player() {}

void Player::testMethod() {
    // Implement test method logic here if needed
}

Warrior::Warrior() : Player(20, 5, 1) {}

void Warrior::testMethod() {
    // Override testMethod if needed
}

void Warrior::onlyWarrior() {
    // Implement onlyWarrior logic here
}

#include "ui.h"


Player::Player(unsigned short HP, short meleeAttack, unsigned short moveDistance)
    : hp(HP), meleeAttack(meleeAttack), moveDistance(moveDistance), _x(0), _y(0) {}

Player* initPlayer(unsigned char type)
{
    // create the player based on user input
    switch (type)
    {
    case 1:
        Player* player = new Warrior();
        return player;
    default:
        break;
    }
    return NULL;
}

unsigned int Player::getX()
{
    return _x;
}

unsigned int Player::getY()
{
    return _y;
}

void Player::setX(unsigned int x)
{
    _x = x;
}

void Player::setY(unsigned int y)
{
    _y = y;
}

Player::~Player() {
    memset(this, 0, sizeof(Player));
}

void Player::testMethod() {
    // Implement test method logic here if needed
}


void Player::displayStats(int line) {
    std::cout << u8" █";
    // this will be called after print terrain
    switch (line)
    {
    case 0:
        std::cout << u8"████████████████████████";
        return;
    case 1:
        std::cout << " HP: " << this->hp << "               ";
        break;
    case 2:
        std::cout << " Move Distance: " << this->moveDistance << "     ";
        break;
    case 3:
        std::cout << " Melee Damage: " << this->meleeAttack << "      ";
        break;
    default:
        return;
        break;
        
    }
    std::cout << u8" █";
    return;
}

unsigned char Player::getPlayerMovement()
{
    // 0x1 to check for toggle
    // 0x8000 to check for press
    bool keypressed = false;
    unsigned char returnV = 0;
    while (!keypressed) {
        if (GetKeyState('A') & 0x8000) {
            keypressed = true;
            returnV = 1;
        }
        else if (GetKeyState('W') & 0x8000) {
            keypressed = true;
            returnV = 2;
        }
        else if (GetKeyState('S') & 0x8000) {
            keypressed = true;
            returnV = 3;
        }
        else if (GetKeyState('D') & 0x800) {
            keypressed = true;
            returnV = 4;
        }
    }
    // grab player movement, and return the int'ed key value
    return returnV;
}

Warrior::Warrior() : Player(20, 5, 1) {}

void Warrior::testMethod() {
    // Override testMethod if needed
}

void Warrior::onlyWarrior() {
    // Implement onlyWarrior logic here
}




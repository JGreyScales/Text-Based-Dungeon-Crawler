#include "room.h"


Room::Room() {
    _lX = 0;
    _lY = 0;
    _uX = 0;
    _uY = 0;
    _generatedItemCount = 0;
    item roomItems;
}


void Room::setLX(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    _lX = a;
    return;
}

void Room::setLY(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    _lY = a;
    return;
}

void Room::setUX(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    _uX = a;
    return;
}

void Room::setUY(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    _uY = a;
    return;
}


int Room::getLX() {
    return _lX;
}

int Room::getLY() {
    return _lY;
}

int Room::getUX() {
    return _uX;
}

int Room::getUY() {
    return _uY;
}

int Room::getGeneratedItemCount() {
    return _generatedItemCount;
}

item Room::getItemAtIndex(int x) {
    if (x < 0 || x > ROOM_MAX_ITEMS - 1) {
        return _roomItems[0]; // failure
    }

    return _roomItems[x];
}



void Room::generateRoomItems() {
    // purge room items & delete all data
    //memset(_roomItems&, 0, sizeof(_roomItems));

    _generatedItemCount = rand() % 8 + 2;
    unsigned char ticker = 0;
    while (ticker < _generatedItemCount) {
        unsigned int choosenItem = rand() % 2;
        switch (choosenItem) {
        case 0:
            _roomItems[ticker] = healthPotion();
            break;
        case 1:
            _roomItems[ticker] = strengthPotion();
            break;
        default:
            std::cout << "error generating item";
            return;
        }
        ticker++;
    }
    return;
}

int Room::getRandomXWithinRoom() {
    return randomBetween(_lX + 1, _uX - 1);
}

int Room::getRandomYWithinRoom() {
    return randomBetween(_lY + 1, _uY - 1);
}
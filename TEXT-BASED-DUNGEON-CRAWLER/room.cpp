#include "room.h"


room::room() {
    _lX = 0;
    _lY = 0;
    _uX = 0;
    _uY = 0;
    item roomItems;
}


void room::setLX(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    _lX = a;
    return;
}

void room::setLY(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    _lY = a;
    return;
}

void room::setUX(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    _uX = a;
    return;
}

void room::setUY(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    _uY = a;
    return;
}


int room::getLX() {
    return _lX;
}

int room::getLY() {
    return _lY;
}

int room::getUX() {
    return _uX;
}

int room::getUY() {
    return _uY;
}



void generateRoomItems(room Primary) {
    unsigned int roomItemGenCount = rand() % 8 + 2;
    while (roomItemGenCount-- > 0) {

    }
    return;
}
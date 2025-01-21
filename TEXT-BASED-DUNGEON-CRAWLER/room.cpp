#include "room.h"
#include <climits>

room::room() {
    lX = 0;
    lY = 0;
    uX = 0;
    uY = 0;
}


void room::setLX(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    lX = a;
    return;
}

void room::setLY(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    lY = a;
    return;
}

void room::setUX(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    uX = a;
    return;
}

void room::setUY(int a) {
    if (a < 0 || a > INT_MAX)
        return;
    uY = a;
    return;
}


int room::getLX() {
    return lX;
}

int room::getLY() {
    return lY;
}

int room::getUX() {
    return uX;
}

int room::getUY() {
    return uY;
}
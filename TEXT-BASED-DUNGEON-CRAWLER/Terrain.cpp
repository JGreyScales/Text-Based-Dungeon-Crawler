#include "Terrain.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <ctime>
#include <climits>
#include <math.h>

#define EMPTY "\033[48;5;15m";
#define RESET "\033[0m";

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



room Terrain::generateRandomRoom() {
    room newRoom = room();
    while (true) {
        newRoom.setLY(rand() % 48);
        newRoom.setLX(rand() % 150);
        int roomWidth = rand() % 3 + 8;
        int roomHeight = rand() % 3 + 8;
        newRoom.setUY(newRoom.getLY() + roomHeight);
        newRoom.setUX(newRoom.getLX() + roomWidth);

        if (canPlaceRoom(newRoom.getLY(), newRoom.getLX(), roomWidth, roomHeight)) {
            placeRoom(newRoom.getLY(), newRoom.getLX(), roomWidth, roomHeight);
            return newRoom;
        }
    }
}

bool Terrain::canPlaceRoom(int y, int x, int roomWidth, int roomHeight) {
    if (y + roomHeight > 50|| x + roomWidth > 150) return false;
    for (int tmpY = y - 1; tmpY <= roomHeight + y; tmpY++) {
        for (int tmpX = x - 1; tmpX <= roomWidth + x; tmpX++) {
            if (this->terrainMap[tmpY][tmpX] == 'E') return false;
        }
    }
    return true;
}

void Terrain::placeRoom(int y, int x, int roomWidth, int roomHeight) {
    for (int tmpY = y; tmpY < roomHeight + y; tmpY++) {
        for (int tmpX = x; tmpX < roomWidth + x; tmpX++) {
            this->terrainMap[tmpY][tmpX] = 'E';
        }
    }
    return;
}


void Terrain::connectAllRooms(room rooms[11]) {
    for (int i = 1; i < 10; i++) {
        connectRoom(rooms[i - 1], rooms[i], 0, 0, 0, 0);
    }
    return;
}


bool Terrain::connectRoom(room primary, room secondary, int px = 0, int py = 0, int sx = 0, int sy = 0) {
    if (px == 0 && py == 0) {
        px = randomBetween(primary.getLX(), primary.getUX());
        py = randomBetween(primary.getLY(), primary.getUY());

        sx = randomBetween(secondary.getLX(), secondary.getUX());
        sy = randomBetween(secondary.getLY(), secondary.getUY());
    }


    // check what direction secondary is from primary & move accordingly
    // the player cant move diagonal, so can only move 1 direction at a time
    if (px < sx) {
        px++;
    }
    else if (py < sy) {
        py++;
    }
    else if (px > sx) {
        px--;
    } // py > sy
    else {
        py--;
    }

    if (px < 0 || py < 0) {
        return false;
    }

    if (py == sy && px == sx) {
        // we would have been in the center of the object; so it really doesn't matter
        // to set the current pos to E
        return true;
    }
    else if (connectRoom(primary, secondary, px, py, sx, sy)) {
        terrainMap[py][px] = 'E';
    }
    return true;
}

void Terrain::printTerrain() {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 150; x++) {
            if (terrainMap[y][x] == 'E') {
                std::cout << EMPTY;
            }
            std::cout << terrainMap[y][x] << RESET;
        }
        std::cout << std::endl;
    }
    return;
}

Terrain::Terrain() {
    memset(this, 0, sizeof(Terrain));
    memset(terrainMap, 'X', sizeof(terrainMap));

    srand(static_cast<unsigned int>(time(NULL)));
    int roomNumber = rand() % 7 + 5;
    int ticker = 0;
    while (ticker < roomNumber) {
        rooms[ticker] = generateRandomRoom();
        ticker++;
        srand(static_cast<unsigned int>(time(NULL)));
    }
    connectAllRooms(rooms);
    printTerrain();
    return;
}

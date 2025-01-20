#include "Terrain.h"
#include <string>
#include <iostream>
#include <ctime>

#define EMPTY "\033[48;5;15m";
#define RESET "\033[0m";

room::room() {
    lX = 0;
    lY = 0;
    uX = 0;
    uY = 0;
}


void room::setLX(int a) {
    lX = a;
}

void room::setLY(int a) {
    lY = a;
}

void room::setUX(int a) {
    uX = a;
}

void room::setUY(int a) {
    uY = a;
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

        if (canPlaceRoom(newRoom.getLY(), newRoom.getLX(), roomWidth, roomHeight)) {
            placeRoom(newRoom.getLY(), newRoom.getLX(), roomWidth, roomHeight);
            return newRoom;
        }
    }
}

bool Terrain::canPlaceRoom(int y, int x, int roomWidth, int roomHeight) {
    if (y + roomWidth > 50|| x + roomHeight > 150) return false;
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
    printTerrain();
    return;
}

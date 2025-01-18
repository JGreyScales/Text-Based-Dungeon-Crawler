#include "Terrain.h"
#include <string>
#include <iostream>
#include <ctime>

#define EMPTY "\033[48;5;15m";
#define RESET "\033[0m";

void Terrain::generateRandomRoom() {
    while (true) {
        int roomWidth = rand() % 3 + 8;
        int roomHeight = rand() % 3 + 8;
        int y = rand() % 48;
        int x = rand() % 150;
        if (canPlaceRoom(y, x, roomWidth, roomHeight)) {
            placeRoom(y, x, roomWidth, roomHeight);
            return;
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
    for (int x = 0; x < 50; x++) {
        for (int y = 0; y < 150; y++) {
            if (terrainMap[x][y] == 'E') {
                std::cout << EMPTY;
            }
            std::cout << terrainMap[x][y] << RESET;
        }
        std::cout << std::endl;
    }
    return;
}

Terrain::Terrain() {
    memset(terrainMap, 'X', sizeof(terrainMap));
    
    srand(static_cast<unsigned int>(time(NULL)));
    int roomNumber = rand() % 7 + 5;
    std::cout << roomNumber << std::endl;
    while (roomNumber > 0) {
        generateRandomRoom();
        roomNumber--;
        srand(static_cast<unsigned int>(time(NULL)));
    }
    printTerrain();
    return;
}

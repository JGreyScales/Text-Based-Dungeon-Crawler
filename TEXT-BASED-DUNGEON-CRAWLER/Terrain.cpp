#include "Terrain.h"

#define PLAYER "\033[38;5;196m\033[48;5;15m";
#define EMPTY "\033[48;5;15m";
#define RESET "\033[0m";

room Terrain::generateRandomRoom() {
    room newRoom = room();
    int failures = 0;

    //return newRoom;
    while (true) {
        newRoom.setLY(rand() % 40 + 1);
        newRoom.setLX(rand() % 140 + 1);
        int roomWidth = rand() % 3 + 8;
        int roomHeight = rand() % 3 + 8;
        newRoom.setUY(newRoom.getLY() + roomHeight);
        newRoom.setUX(newRoom.getLX() + roomWidth);

        if (canPlaceRoom(newRoom.getLY(), newRoom.getLX(), roomWidth, roomHeight)) {
            placeRoom(newRoom.getLY(), newRoom.getLX(), roomWidth, roomHeight);
            return newRoom;
        }
        else if (failures > 25) {
            newRoom.setLY(25);
            newRoom.setLX(50);
            newRoom.setUY(newRoom.getLY() + roomHeight);
            newRoom.setUX(newRoom.getLX() + roomWidth);
            placeRoom(newRoom.getLY(), newRoom.getLX(), roomWidth, roomHeight);
            return newRoom;
        }
        failures++;
    }
}

bool Terrain::canPlaceRoom(int y, int x, int roomWidth, int roomHeight) {
    if (y + roomHeight > 49 || x + roomWidth > 149) return false;
    for (int tmpY = y; tmpY < roomHeight + y; tmpY++) {
        for (int tmpX = x; tmpX < roomWidth + x; tmpX++) {
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


bool Terrain::connectAllRooms(int depth = 0) {
    for (unsigned int i = 1; i < generatedRoomCount; i++) {
        if (!connectRoom(rooms[i - 1], rooms[i], 0, 0, 0, 0, 0)) {
            i--;
        }
    }
    return true;
}


bool Terrain::connectRoom(room primary, room secondary, int px = 0, int py = 0, int sx = 0, int sy = 0, int depth = 0) {

    if (depth > 500) {
        return false;
    }
    if (px == 0 && py == 0) {
        px = randomBetween(primary.getLX() + 1, primary.getUX() - 1);
        py = randomBetween(primary.getLY() + 1, primary.getUY() - 1);

        sx = randomBetween(secondary.getLX() + 1, secondary.getUX() - 1);
        sy = randomBetween(secondary.getLY() + 1, secondary.getUY() - 1);
    }

    // check what direction secondary is from primary & move accordingly
    // the player cant move diagonal, so can only move 1 direction at a time
    int choice = INT_MAX;
    if (depth < 100) {
        choice = rand() % 6;
    }


    switch (choice)
    {
    case 1:
        if (py < 49)
            px++;
        break;
    case 2:
        if (px < 149)
            py++;
        break;
    case 3:
        if (px > 0)
            px--;
        break;
    case 4:
        if (py > 0)
            py--;
        break;
    default:
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
        };
    }

    if (px < 0) {
        px = 0;
    } else if (py < 0){
        py = 0;
    }
    else if (px > 149) {
        px = 149;
    }
    else if (py > 49) {
        py = 49;
    }

    if (py == sy && px == sx) {
        terrainMap[py][px] = 'E';
        return true;
    }
    else if (connectRoom(primary, secondary, px, py, sx, sy, depth + 1)) {
        terrainMap[py][px] = 'E';
        return true;
    }
    return false;
}

void Terrain::spawnPlayer(room spawnRoom) {
    int x = randomBetween(spawnRoom.getLX() + 1, spawnRoom.getUX() - 1);
    int y = randomBetween(spawnRoom.getLY() + 1, spawnRoom.getUY() - 1);
    terrainMap[y][x] = 'P';
    return;
}

void Terrain::fillRoomsWithItems() {
    unsigned itemCount = rand() % 5 + 5;
    while (itemCount-- > 0) {

    }
    return;
}

void Terrain::printTerrain(Player* playerChar) {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 150; x++) {
            if (terrainMap[y][x] == 'E') {std::cout << EMPTY;}
            else if (terrainMap[y][x] == 'P') {std::cout << PLAYER;}
            std::cout << terrainMap[y][x] << RESET;
        }

        playerChar->displayStats(y);

        std::cout << std::endl;
    }
    return;
}

Terrain::Terrain(Player* userChar) {
    srand(static_cast<unsigned int>(time(NULL)));
    //memset(this, 0, sizeof(Terrain));
    do {
        memset(terrainMap, 'X', sizeof(terrainMap));

        generatedRoomCount = rand() % 5 + 6;
        unsigned int ticker = 0;
        while (ticker < generatedRoomCount) {
            rooms[ticker] = generateRandomRoom();
            ticker++;
        }
    } while (!connectAllRooms());

    //fillRoomsWithItems();
    spawnPlayer(rooms[0]);
    return;
}

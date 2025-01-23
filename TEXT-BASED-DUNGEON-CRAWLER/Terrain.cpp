#include "Terrain.h"

#define PLAYER "\033[38;5;196m\033[48;5;15m";
#define EMPTY "\033[48;5;15m";
#define RESET "\033[0m";

room Terrain::generateRandomRoom() {
    room newRoom = room();

    //return newRoom;
    while (true) {
        newRoom.setLY(rand() % 48 + 1);
        newRoom.setLX(rand() % 148 + 1);
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
    if (y + roomHeight > 49|| x + roomWidth > 149) return false;
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
    for (unsigned int i = 1; i < generatedRoomCount; i++) {
        if (!connectRoom(rooms[i - 1], rooms[i], 0, 0, 0, 0, 0)) {
            i--;
        }
    }
    return;
}


bool Terrain::connectRoom(room primary, room secondary, int px = 0, int py = 0, int sx = 0, int sy = 0, int depth = 0) {

    if (depth > 1000) {
        return false;
    }
    if (px == 0 && py == 0) {
        px = randomBetween(primary.getLX(), primary.getUX());
        py = randomBetween(primary.getLY(), primary.getUY());

        sx = randomBetween(secondary.getLX(), secondary.getUX());
        sy = randomBetween(secondary.getLY(), secondary.getUY());
    }

    // check what direction secondary is from primary & move accordingly
    // the player cant move diagonal, so can only move 1 direction at a time
    switch (rand() % 9999)
    {
    case 1:
        px++;
        break;
    case 2:
        py++;
        break;
    case 3:
        px--;
        break;
    case 4:
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

    if (px < 0 || py < 0 || px > 149 || py > 49) {
        return false;
    }

    if (py == sy && px == sx) {
        // we would have been in the center of the object; so it really doesn't matter
        // to set the current pos to E
        return true;
    }
    else if (connectRoom(primary, secondary, px, py, sx, sy, depth + 1)) {
        terrainMap[py][px] = 'E';
        return true;
    }
    return false;
}

void Terrain::spawnPlayer(room spawnRoom) {
    int x = randomBetween(spawnRoom.getLX(), spawnRoom.getUX());
    int y = randomBetween(spawnRoom.getLY(), spawnRoom.getUY());
    terrainMap[y][x] = 'P';
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
    memset(this, 0, sizeof(Terrain));
    memset(terrainMap, 'X', sizeof(terrainMap));

    srand(static_cast<unsigned int>(time(NULL)));
    generatedRoomCount = rand() % 7 + 6;
    unsigned int ticker = 0;
    while (ticker < generatedRoomCount) {
        rooms[ticker] = generateRandomRoom();
        ticker++;
    }
    connectAllRooms(rooms);
    spawnPlayer(rooms[0]);
    return;
}

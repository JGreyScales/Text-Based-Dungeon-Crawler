#include "Terrain.h"

#define PLAYER "\033[38;5;196m\033[48;5;15m"
#define STRENGTH "\033[38;5;46m\033[48;5;15m"
#define HEALTH "\033[38;5;196m\033[48;5;15m"
#define EMPTY "\033[48;5;15m";
#define RESET "\033[0m";

Room* Terrain::generateRandomRoom() {
    Room* newRoom = new Room();
    newRoom->generateRoomItems();
    int failures = 0;

    //return newRoom;
    while (true) {
        newRoom->setLY(rand() % 40 + 1);
        newRoom->setLX(rand() % 140 + 1);
        int roomWidth = rand() % 3 + 8;
        int roomHeight = rand() % 3 + 8;
        newRoom->setUY(newRoom->getLY() + roomHeight);
        newRoom->setUX(newRoom->getLX() + roomWidth);

        if (canPlaceRoom(newRoom->getLY(), newRoom->getLX(), roomWidth, roomHeight)) {
            placeRoom(newRoom->getLY(), newRoom->getLX(), roomWidth, roomHeight);
            return newRoom;
        }
        else if (failures > 25) {
            newRoom->setLY(25);
            newRoom->setLX(50);
            newRoom->setUY(newRoom->getLY() + roomHeight);
            newRoom->setUX(newRoom->getLX() + roomWidth);
            placeRoom(newRoom->getLY(), newRoom->getLX(), roomWidth, roomHeight);
            return newRoom;
        }
        failures++;
    }
}

bool Terrain::canPlaceRoom(int y, int x, int roomWidth, int roomHeight) {
    if (y + roomHeight > 49 || x + roomWidth > 149) return false;
    for (int tmpY = y; tmpY < roomHeight + y; tmpY++) {
        for (int tmpX = x; tmpX < roomWidth + x; tmpX++) {
            if (isSpaceEmpty(tmpX, tmpY)) return false;
        }
    }
    return true;
}

void Terrain::placeRoom(int y, int x, int roomWidth, int roomHeight) {
    for (int tmpY = y; tmpY < roomHeight + y; tmpY++) {
        for (int tmpX = x; tmpX < roomWidth + x; tmpX++) {
            _terrainMap[tmpY][tmpX] = 'E';
        }
    }
    return;
}


bool Terrain::connectAllRooms() {
    for (unsigned int i = 1; i < _generatedRoomCount; i++) {
        if (!connectRoom(_rooms[i - 1], _rooms[i], 0, 0, 0, 0, 0)) {
            i--;
        }
    }
    return true;
}


bool Terrain::connectRoom(Room* primary, Room* secondary, int px = 0, int py = 0, int sx = 0, int sy = 0, int depth = 0) {

    // overflows stack at depth 183
    if (depth > 200) {
        return false;
    }
    if (px == 0 && py == 0) {
        px = randomBetween(primary->getLX() + 1, primary->getUX() - 1);
        py = randomBetween(primary->getLY() + 1, primary->getUY() - 1);

        sx = randomBetween(secondary->getLX() + 1, secondary->getUX() - 1);
        sy = randomBetween(secondary->getLY() + 1, secondary->getUY() - 1);
    }

    // check what direction secondary is from primary & move accordingly
    // the player cant move diagonal, so can only move 1 direction at a time
    int choice = 5;
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
        _terrainMap[py][px] = 'E';
        return true;
    }
    else if (connectRoom(primary, secondary, px, py, sx, sy, depth + 1)) {
        _terrainMap[py][px] = 'E';
        return true;
    }
    return false;
}

void Terrain::spawnPlayer(Room spawnRoom) {
    if (!spawnRoom.getLX() || !spawnRoom.getLY() || !spawnRoom.getUX() || !spawnRoom.getUY()){
        return;
    }
    int x = randomBetween(spawnRoom.getLX() + 1, spawnRoom.getUX() - 1);
    int y = randomBetween(spawnRoom.getLY() + 1, spawnRoom.getUY() - 1);
    _terrainMap[y][x] = 'P';
    return;
}

void Terrain::fillRoomsWithItems() {
    unsigned char ticker = 0;
    while (ticker < _generatedRoomCount) {
        Room* currentRoom = _rooms[ticker];
        for (int i = 0; i < currentRoom->getGeneratedItemCount(); i++) {

            int tmpX = currentRoom->getRandomXWithinRoom();
            int tmpY = currentRoom->getRandomYWithinRoom();

            // if space is empty, try again
            if (!isSpaceEmpty(tmpX, tmpY))
                continue;

            _terrainMap[tmpY][tmpX] = currentRoom->getItemAtIndex(i)->getItemLetter();
        }
        ticker++;
    }
    return;
}

bool Terrain::isSpaceEmpty(int x, int y) {
    return (_terrainMap[y][x] == 'E');
}

void Terrain::printTerrain(Player* playerChar) {
    if (NULL == playerChar) {
        exit(1);
    }
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 150; x++) {
            if (_terrainMap[y][x] == 'E') {std::cout << EMPTY;}
            else if (_terrainMap[y][x] == 'P') {std::cout << PLAYER;}
            else if (_terrainMap[y][x] == 'S') { std::cout << STRENGTH; }
            else if (_terrainMap[y][x] == 'H') { std::cout << HEALTH; }
            std::cout << _terrainMap[y][x] << RESET;
        }

        playerChar->displayStats(y);

        std::cout << std::endl;
    }
    return;
}

Terrain::Terrain(Player* userChar) {
    srand(static_cast<unsigned int>(time(NULL)));
    do {
        memset(_terrainMap, 'X', sizeof(_terrainMap));

        _generatedRoomCount = rand() % 5 + 6;
        unsigned int ticker = 0;
        while (ticker < _generatedRoomCount) {
            _rooms[ticker] = generateRandomRoom();
            ticker++;
        }
    } while (!connectAllRooms());

    fillRoomsWithItems();
    spawnPlayer(*_rooms[0]);
    return;
}

Terrain::~Terrain()
{
    for (unsigned int i = 0; i < _generatedRoomCount; i++) {
        delete _rooms[i];
    }
    memset(this, 0, sizeof(Terrain));
}

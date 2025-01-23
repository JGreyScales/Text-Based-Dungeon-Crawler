#pragma once
#include "room.h"
#include "utils.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <ctime>

/* 
X = STONE WALL
x = UNKNOWN_TILE
E = EMPTY TILE
I = UNKNOWN_ITEM
P = PLAYER
p = POTION


*/

class Terrain {
private:
	room rooms[11];
	unsigned int generatedRoomCount;
	char terrainMap[50][150];
protected:
	room generateRandomRoom();
	bool canPlaceRoom(int, int, int, int);
	void placeRoom(int, int, int, int);
	void connectAllRooms(room[11]);
	bool connectRoom(room, room, int, int, int, int, int);
	void spawnPlayer(room);
public:
	void printTerrain();
	Terrain(Player*);
};
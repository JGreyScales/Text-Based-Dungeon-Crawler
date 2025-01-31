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
	room _rooms[11];
	unsigned int _generatedRoomCount;
	char _terrainMap[50][150];

	room generateRandomRoom();
	bool canPlaceRoom(int, int, int, int);
	void placeRoom(int, int, int, int);
	bool connectAllRooms();
	bool connectRoom(room, room, int, int, int, int, int);
	void spawnPlayer(room);
	void fillRoomsWithItems();
public:
	void printTerrain(Player*);
	Terrain(Player*);
};
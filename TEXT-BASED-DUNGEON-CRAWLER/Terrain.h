#pragma once
#include "room.h"


#define MAX_ROOM_COUNT 11


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
	Room* _rooms[MAX_ROOM_COUNT];
	unsigned int _generatedRoomCount;
	char _terrainMap[50][150];

	Room* generateRandomRoom();
	bool canPlaceRoom(int, int, int, int);
	void placeRoom(int, int, int, int);
	bool connectAllRooms();
	bool connectRoom(Room*, Room*, int, int, int, int, int);
	void spawnPlayer(Room);
	void fillRoomsWithItems();
	bool isSpaceEmpty(int, int);
public:
	void printTerrain(Player*);
	Terrain(Player*);
	~Terrain();
};
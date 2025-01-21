#pragma once
#include "room.h"

/* 
X = STONE WALL
E = EMPTY TILE
P = PLAYER



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
	bool connectRoom(room, room, int, int, int, int);
	void spawnPlayer(room);
public:
	void printTerrain();
	Terrain();
};
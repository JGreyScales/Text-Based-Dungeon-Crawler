#pragma once

class room {
	int lX;
	int lY;
	int uX;
	int uY;
public:
	void setLX(int a);
	void setLY(int a);
	void setUX(int a);
	void setUY(int a);

	int getLX();
	int getLY();
	int getUX();
	int getUY();
public:
	room();
};

enum DIRECTION {SOUTH, WEST, EAST, NORTH};


class Terrain {
	room rooms[11];
	unsigned int generatedRoomCount;
	char terrainMap[50][150];
	room generateRandomRoom();
	bool canPlaceRoom(int, int, int, int);
	void placeRoom(int, int, int, int);
	void connectAllRooms(room[11]);
	bool connectRoom(room, room, int, int, int, int);
public:
	void printTerrain();
	Terrain();
};
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


class Terrain {
	room rooms[11];
	char terrainMap[50][150];
	room generateRandomRoom();
	bool canPlaceRoom(int, int, int, int);
	void placeRoom(int, int, int, int);
	void dijsktraConnect(room, room);
public:
	void printTerrain();
	Terrain();
};
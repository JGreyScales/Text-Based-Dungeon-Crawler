#pragma once
class Terrain {
	char terrainMap[50][150];
	void generateRandomRoom();
	bool canPlaceRoom(int, int, int, int);
	void placeRoom(int, int, int, int);
public:
	void printTerrain();
	Terrain();
};
#include "ui.h"

void printScreen(Terrain* map, Player* character) {
	system("CLS");
	map->printTerrain(character);
}
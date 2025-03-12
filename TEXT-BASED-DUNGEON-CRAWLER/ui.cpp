#include "ui.h"

void printScreen(Terrain* map, Player* character) {
	system("CLS");
	map->printTerrain(character);
}

void tickGame(Terrain* terrain, Player* player)
{
	printScreen(terrain, player);
	unsigned char playerMovement = player->getPlayerMovement();
}

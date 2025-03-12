#include "Terrain.h"
#include "ui.h"



int main(void) {
	system("chcp 65001");
	Player* player = initPlayer(1);
	Terrain* terrain = initTerrain(player);
	
	tickGame(terrain, player);

	delete terrain;
	delete player;
	std::cin.get();
	return 0;
}
#include "Terrain.h"
#include "ui.h"



int main(void) {
	system("chcp 65001");
	Player* player = new Warrior();
	
	Terrain* awa = new Terrain(player);
	//delete player;
	printScreen(awa, player);

	delete awa;
	delete player;
	std::cin.get();
	return 0;
}
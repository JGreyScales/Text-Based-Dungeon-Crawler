#include "Player.h"
#include "Terrain.h"
#include "ui.h"


#include <windows.h>


int main(void) {
	resizeConsole(200, 50);
	Player* player = new Warrior();
	
	Terrain* awa = new Terrain(player);
	//delete player;

	printScreen(awa, player);
	std::cin.get();
	return 0;
}
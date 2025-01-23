#include "ui.h"

#include <Windows.h>

void resizeConsole(int width, int height) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD bufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
	if (!SetConsoleScreenBufferSize(hConsole, bufferSize)) {
		std::cerr << "Error resizing screen buffer." << std::endl;
		return;
	}

	SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
	if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize)) {
		std::cerr << "Error resizing window." << std::endl;
		return;
	}
}

void setCursorPosition(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void printScreen(Terrain* map, Player* character) {
	//system("CLS");
	map->printTerrain();
	std::cout << "\033[H" << "\033[25A";

	character->displayStats();

}
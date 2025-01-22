#pragma once
#include "items.h"

#include <climits>
#include <random>

class room {
	int lX;
	int lY;
	int uX;
	int uY;
	item Items[5];
public:
	room();

	void setLX(int a);
	void setLY(int a);
	void setUX(int a);
	void setUY(int a);

	int getLX();
	int getLY();
	int getUX();
	int getUY();

	void generateRoomItems(room);
};

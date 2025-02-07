#pragma once
#include "Player.h"


#define ROOM_MAX_ITEMS 4

class Room {
	int _lX;
	int _lY;
	int _uX;
	int _uY;
	unsigned int _generatedItemCount;
	item* _roomItems[ROOM_MAX_ITEMS];
public:
	Room();
	~Room();

	void setLX(int a);
	void setLY(int a);
	void setUX(int a);
	void setUY(int a);

	int getLX();
	int getLY();
	int getUX();
	int getUY();
	int getGeneratedItemCount();
	item* getItemAtIndex(int);

	void generateRoomItems();
	int getRandomXWithinRoom();
	int getRandomYWithinRoom();

};

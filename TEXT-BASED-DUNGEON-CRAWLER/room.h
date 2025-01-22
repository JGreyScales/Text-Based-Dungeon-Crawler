#pragma once
class room {
	int lX;
	int lY;
	int uX;
	int uY;
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

	unsigned char generateRoomItems(room);
};

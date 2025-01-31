#pragma once
#include <string>


class item {
protected:
	char _name[60];
	char _description[180];
	bool _inInventory;
	unsigned char _x;
	unsigned char _y;
public:
	item(const char*,const char*);

	bool isItemInPlayerInventory();
	unsigned int getX();
	unsigned int getY();
	char* getItemName();
	char* getItemDescription();

	void setItemStatus(bool);
	void setX(unsigned char);
	void setY(unsigned char);
	void setItemName(const char*);
	void setItemDescription(const char*);
};


class healthPotion : public item {
	public:
	healthPotion();
};

class strengthPotion : public item {
public:
	strengthPotion();
};
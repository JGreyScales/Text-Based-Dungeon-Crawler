#pragma once
#include <string>


class item {
protected:
	char name[60];
	char description[180];
	bool inInventory;
	unsigned char x;
	unsigned char y;
public:
	item(const char*,const char*);
	//virtual ~item();

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

};
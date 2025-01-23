#pragma once
// item impli will be stack based

class item {
protected:
	char name[60];
	char description[180];
	bool inInventory;
	unsigned int x;
	unsigned int y;
public:
	//virtual ~item();

	bool isItemInPlayerInventory();
	unsigned int getX();
	unsigned int getY();
	char* getItemName();
	char* getItemDescription();

	void setItemStatus(bool);
	void setX(unsigned int);
	void setY(unsigned int);
	void setItemName(char[60]);
	void setItemDescription(char[180]);
};

//
//class healthPotion : public item {
//
//};
//
//class strengthPotion : public item {
//
//};
#include "items.h"


item::item(const char* name, const char* description) {
	setItemName(name);
	setItemDescription(description);
	return;
}

bool item::isItemInPlayerInventory() {
	return _inInventory;
}

unsigned int item::getX() {
	return _x;
}

unsigned int item::getY() {
	return _y;
}

char* item::getItemName() {
	return _name;
}

char* item::getItemDescription() {
	return _description;
}

void item::setItemStatus(bool status) {
	_inInventory = status;
	return;
}

void item::setX(unsigned char x) {
	_x = x;
	return;
}

void item::setY(unsigned char y) {
	_y = y;
	return;
}

void item::setItemName(const char* name) {
	strncpy_s(_name, name, sizeof(_name) - 1);
	return;
}

void item::setItemDescription(const char* description) {
	strncpy_s(_description, description, sizeof(_description) - 1);
	return;
}

healthPotion::healthPotion() : item("Health Potion", "A red potion that restores health upon consumption") {};

strengthPotion::strengthPotion() : item("Strenght potion", "A blue strength potion that increases melee power") {};
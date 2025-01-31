#include "items.h"


item::item(const char* name, const char* description) {
	setItemName(name);
	setItemDescription(description);
	return;
}

bool item::isItemInPlayerInventory() {
	return this->inInventory;
}

unsigned int item::getX() {
	return this->x;
}

unsigned int item::getY() {
	return this->y;
}

char* item::getItemName() {
	return this->name;
}

char* item::getItemDescription() {
	return this->description;
}

void item::setItemStatus(bool status) {
	this->inInventory = status;
	return;
}

void item::setX(unsigned char x) {
	this->x = x;
	return;
}

void item::setY(unsigned char y) {
	this->y = y;
	return;
}

void item::setItemName(const char* name) {
	strncpy_s(this->name, name, sizeof(this->name) - 1);
	return;
}

void item::setItemDescription(const char* description) {
	strncpy_s(this->description, description, sizeof(this->description) - 1);
	return;
}

healthPotion::healthPotion() : item("Health Potion", "A red potion that restores health upon consumption") {};

strengthPotion::strengthPotion() : item("Strenght potion", "A blue strength potion that increases melee power") {};
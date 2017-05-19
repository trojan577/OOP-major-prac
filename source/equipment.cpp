#include "equipment.h"

Weapon::Weapon(std::string name, int damage, double missChance)
{
	this->name = name;
	this->damage = damage;
	this->missChance = missChance;
}

Weapon::Weapon()
{}

void Weapon::equipt()
{

}

Knife::Knife(std::string name, std::string symbol, int damage, double missChance) : Weapon(name, damage, missChance)
{
	this->symbol = symbol;
}
Knife::Knife()
{}

std::string Knife::getSymbol()
{
	return symbol;
}
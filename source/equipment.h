#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <string>
#include <vector>

class Weapon{
public:
    Weapon();           // Constructor
    Weapon(std::string name, int damage, double missChance);
    void equipt();       // Used to change weapon being used 
protected:
    std::string name;
    int damage;
    double missChance;
};

class Knife : public Weapon{
public:
    Knife();
    Knife(std::string name, std::string symbol, int damage, double missChance);
    std::string getSymbol();
private:
	std::string symbol;
};

#endif // EQUIPMENT_H

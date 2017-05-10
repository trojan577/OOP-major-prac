#ifndef EQUIPTMENT_H
#define EQUIPTMENT_H

#include <iostream>
#include <string>
#include <vector>

class Weapon{
    std::string name;
    int damage;
    double missChance;
public:
    Weapon();           //contructor
    void equip();       //used to change weapon being used 

};

class Knife : public Weapon{

public:
    Knife();
};

#endif

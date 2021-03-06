#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "map.h"
#include "equipment.h"

class Character{
public:
    Character(int health);
                                                //pure virtual functions
    virtual int attack() = 0;
    virtual void move(char, char***) = 0;
    virtual bool miss() = 0;
protected:
    std::string name;                           // initiates starting position and health of the character
    int health;
    int positionX;
    int positionY;
};

class Player : public Character{         
    
public:
    Player(std::string name, int health);
    int isHealth();                             // tells user current health
    std::vector<std::string> isEquipment();     // returns list of items in qeuiptment vector
    int attack();                               // attacks in some way
    void move(char, char***);                   // moves charactor, may need either fucntion for each direction
                                                // or take keyvoard input as argument
    bool miss();                                // returns whther or not they hit based in missChance
    std::string getName();                      // returns the players name
    void setName(std::string);
    int getPlayerPosY();
    int getPlayerPosX();
private:
    std::vector<std::string> equipment;         // starts with weapon called Knife
                                                // buidins vecor of length 1, can increase length (unintelligible-jonathan)
    int positionY;
    int positionX;
};

class Enemy : public Character{
    int damage();
    double missChance;                          // enemies wont have specific weapons
                                                // so they have their ow damage and missChance
public:
    Enemy();                                    
    int attack();
    void move();
    bool miss();
};

#endif	// CHARACTER_H

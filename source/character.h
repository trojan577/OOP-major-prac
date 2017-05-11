#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>

class Character{
public:
	//pure virtual functions
    virtual int attack() = 0;
    virtual void move() = 0;
    virtual bool miss() = 0;
protected:
    std::string name;
    int health;
    int positionX;
    int positionY;
};

class Player : public Character{
                
    
public:
    Player();
    Player(std::string name);
    int isHealth();         	// tells user current health
    std::vector<std::string> isEquipment();  // returns list of items in qeuiptment vector
    int attack();       		// attacks in some way
    void move();        		// moves charactor, may need either fucntion for each direction
                        		// or take keyvoard input as argument
    bool miss();       			// returns whther or not they hit based in missChance
private:
	std::vector<std::string> equipment;	// starts with weapon called Knife
                						// buidins vecor of length 1, can increase length (unintelligible-jonathan)
};

class Enemy : public Character{
    int damage();
    double missChance;  // enemies wont have specific weapons
                        // so they have their ow damage and missChance
public:
    Enemy();
    int attack();
    void move();
    bool miss();
};

#endif	//CHARACTER_H

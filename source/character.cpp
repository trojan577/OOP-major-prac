#include "character.h"
#include "map.h"

Character::Character(int health) {
	if(health <= 100)
		this->health = health;
}

Player::Player(std::string name, int health) : Character(health){
	this->name = name;
	positionX = 15;
	positionY = 1;
}

int Player::attack(){
	/*
	if enemy character next to player,
	check position of enemy - find which enemy object it correlates to and deal damage

	*/
}

void Player::move(){
			//WASD movemnt keys cause easier i think and way not, AAA games do it
	char directionInput;
	std::cin >> directionInput;
	switch(directionInput){
		case 'w':
			positionY += 1;
			break;
		case 'a':
			positionX -= 1;
			break;
		case 's':
			positionY -= 1;
			break;
		case 'd':
			positionX += 1;
			break;
	}
}

bool Player::miss(){

}

int Enemy::attack(){
	/*
	if attacked or if player next to?
	*/
}

void Enemy::move(){
/*
follow?
*/
}

bool Enemy::miss(){

}

int Player::isHealth()
{
	return health;
}

std::string Player::getName()
{
	return name;
}
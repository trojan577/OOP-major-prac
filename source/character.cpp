#include "character.h"

Character::Character(int health) {
	if(health <= 100)										//initialises character health
		this->health = health;
}

Player::Player(std::string name, int health) : Character(health){
	this->name = name;										//initialises starting position
	positionX = 3;
	positionY = 3;
}

int Player::attack(){
	/*
	if enemy character next to player,
	check position of enemy - find which enemy object it correlates to and deal damage

	*/
}

void Player::move(char directionInput, char ***map){
															
	switch(directionInput){									// movement is based on WASD keys  and checking for free spaces in the direction the char is moving in
		case 'w':
			if(map[0][positionX][positionY-1] == ' ') 		// checks for empty spaces within the map
				positionY -= 1;								// if empty then character moves in the direction by one space 
			break;
		case 'a':
			if(map[0][positionX-1][positionY] == ' ')
				positionX -= 1;
			break;
		case 's':
			if(map[0][positionX][positionY+1] == ' ')
				positionY += 1;
			break;
		case 'd':
			if(map[0][positionX+1][positionY] == ' ')
				positionX += 1;
			break;
	}
}

void Player::setName(std::string name){
	this->name = name;
}

int Player::getPlayerPosY(){
	return positionY;
}

int Player::getPlayerPosX(){
	return positionX;
}

bool Player::miss(){

}

int Enemy::attack(){
	/*
	if attacked or if player next to
	then do something
	*/
}

void Enemy::move(){
/*
follow
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

#include "character.h"

Character::Character(int health) {
	if(health <= 100)
		this->health = health;
}

Player::Player(std::string name, int health) : Character(health){
	this->name = name;
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
			//WASD movemnt keys cause easier i think and way not, AAA games do it
	switch(directionInput){
		case 'w':
			if(map[0][positionX][positionY-1] == ' ')
				positionY -= 1;
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

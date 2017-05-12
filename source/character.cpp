#include "character.h"

Character::Character(int health) {
	if(health <= 100)
		this->health = health;
}

Player::Player(std::string name, int health) : Character(health)
{
	this->name = name;
}

int Player::attack()
{}

void Player::move()
{}

bool Player::miss()
{}

int Enemy::attack()
{}

void Enemy::move()
{}

bool Enemy::miss()
{}

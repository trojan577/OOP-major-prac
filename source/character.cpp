#include "character.h"

Player::Player(){}

Player::Player(std::string name)
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

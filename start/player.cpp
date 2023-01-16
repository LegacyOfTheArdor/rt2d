

#include "player.h"

Player::Player() : Entity()
{
    this->addSprite("assets/player.tga");
    this->sprite()->color = WHITE;
}

void Player::GoUp()
{
    this->position.y = this->position.y - 32;
    this->rotation.z = 0;
	this->rotation.z = 1.5 * PI;
}

void Player::GoLeft()
{
   this->position.x = this->position.x - 32; 
   this->rotation.z = 0;
   this->rotation.z = PI;      
}

void Player::GoDown()
{
   this->position.y = this->position.y + 32; 
   this->rotation.z = 0;
   this->rotation.z = 0.5 * PI; 
}

void Player::GoRight()
{
    this->position.x = this->position.x + 32;
    this->rotation.z = 0;     
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{

}
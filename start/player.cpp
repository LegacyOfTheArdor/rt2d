

#include "player.h"

Player::Player() : Entity()
{
    this->addSprite("assets/player.tga");
    
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
    if(this->position.y > 640)
    {
        this->position.y = this->position.y - 32;
    }

    if(this->position.y < 128)
    {
        this->position.y = this->position.y + 32;
    }

    if(this->position.x > 1024)
    {
        this->position.x = this->position.x - 32;
    } 

    if(this->position.x < 256)
    {
        this->position.x = this->position.x + 32;
    }
}
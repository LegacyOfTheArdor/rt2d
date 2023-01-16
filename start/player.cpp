

#include "player.h"

Player::Player() : Entity()
{
    this->addSprite("assets/player.tga");
    this->sprite()->color = WHITE;
}

void Player::GoUp()
{
    this->position.y = this->position.y - 32;
}

void Player::GoLeft()
{
   this->position.x = this->position.x - 32;     
}

void Player::GoDown()
{
   this->position.y = this->position.y + 32;
}

void Player::GoRight()
{
    this->position.x = this->position.x + 32;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{

}
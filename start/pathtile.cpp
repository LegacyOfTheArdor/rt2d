

#include "pathtile.h"

PathTile::PathTile() : Entity()
{
    this->addSprite("assets/square.tga");
    this->sprite()->color = WHITE;
}

PathTile::~PathTile()
{

}

void PathTile::update(float deltaTime)
{

}
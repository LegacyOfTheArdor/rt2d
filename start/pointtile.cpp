

#include "pointtile.h"

PointTile::PointTile() : Entity()
{
    this->addSprite("assets/star.tga");
    this->sprite()->color = WHITE;
    this->scale = Point(1.5f, 1.5f);
}

PointTile::~PointTile()
{

}

void PointTile::update(float deltaTime)
{

}
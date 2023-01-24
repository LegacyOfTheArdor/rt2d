

#include "pointtile.h"

PointTile::PointTile() : Entity()
{
    this->addSprite("assets/star.tga");
    this->sprite()->color = WHITE;
    this->scale = Point(1.5f, 1.5f);
}

 void PointTile::addNeighbour(PathTile* pt)
 {
     neighbours.push_back(pt);
 }

PointTile::~PointTile()
{

}

void PointTile::update(float deltaTime)
{
     bool owned = checkNeighbours();
     if (owned) {
        // this->sprite()->color = RGBAColor(255, 0, 0, 255);
        this->sprite()->color = neighbours[0]->sprite()->color;
     }
}

 bool PointTile::checkNeighbours()
 {
     RGBAColor checkColor = neighbours[0]->sprite()->color;
     for (int i = 0; i < neighbours.size(); i++)
     {
        RGBAColor realColor = neighbours[i]->sprite()->color;
        if (realColor != checkColor) {
            // nope
            return false;
        }
     }
     // all colours are the same so far
     return true;
 }
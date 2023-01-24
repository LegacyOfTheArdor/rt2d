
#ifndef POINTTILE_H
#define POINTTILE_H

#include <rt2d/entity.h>
#include "pathtile.h"

class PointTile : public Entity
{
public:
	
    PointTile();
    
    virtual ~PointTile();

	virtual void update(float deltaTime);

     void addNeighbour(PathTile* pt);

private:
    std::vector<PathTile*> neighbours;

    bool checkNeighbours();

};

#endif
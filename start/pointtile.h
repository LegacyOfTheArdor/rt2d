
#ifndef POINTTILE_H
#define POINTTILE_H

#include <rt2d/entity.h>

class PointTile : public Entity
{
public:
	
    PointTile();
    
    virtual ~PointTile();

	virtual void update(float deltaTime);

private:

};

#endif
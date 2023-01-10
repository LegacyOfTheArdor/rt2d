
#ifndef PATHTILE_H
#define PATHTILE_H

#include <rt2d/entity.h>

class PathTile : public Entity
{
public:
	
    PathTile();
    
    virtual ~PathTile();

	virtual void update(float deltaTime);

private:

};

#endif
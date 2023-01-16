
#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player : public Entity
{
public:
	
    Player();
    virtual ~Player();

	virtual void update(float deltaTime);

	void GoUp();
	void GoDown();
	void GoLeft();
	void GoRight();

private:

};

#endif
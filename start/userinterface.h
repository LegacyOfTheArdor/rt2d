
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <rt2d/entity.h>

class UserInterface : public Entity
{
public:
	
    UserInterface();
    virtual ~UserInterface();

	virtual void update(float deltaTime);


private:

};

#endif
/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MainGame behavior.
 */

#ifndef MAINGAME_H
#define MAINGAME_h

#include <rt2d/scene.h>


#include "pathtile.h" 
#include "pointtile.h"
#include "player.h"
#include "userinterface.h"


/// @brief The MainGame class is the Scene implementation.
class MainGame : public Scene
{
public:
	/// @brief Constructor
	MainGame();
	/// @brief Destructor
	virtual ~MainGame();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	
	bool circle2circleFloats(float x1, float y1, float x2, float y2,float radii = 32) {
		float dx = x1 - x2;
		float dy = y1 - y2;
		return (dx * dx + dy * dy) < (radii * radii);
	}
	
	std::vector<PathTile*> pathTiles;

	std::vector<PointTile*> pointTiles;

	Player* playerOne;
	Player* playerTwo;


	UserInterface* oneBoard;
	UserInterface* twoBoard;
	
	Timer t;
};


#endif ///* SCENE00_H */

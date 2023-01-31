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
#include <rt2d/text.h>

/// @brief The StartScreen class is the Scene implementation.
class StartScreen : public Scene
{
public:
	/// @brief Constructor
	StartScreen();
	/// @brief Destructor
	virtual ~StartScreen();

	bool playgame = false;
	Text startText;
	Text explain;
	Text oneExplain;
	Text twoExplain;
	
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);


private:
	
};


#endif ///* SCENE00_H */

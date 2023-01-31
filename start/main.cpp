/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>

#include "maingame.h"
#include "startscreen.h"

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;
	
	StartScreen* startscreen = new StartScreen();
	MainGame* maingame = new MainGame();

	// std::vector<SuperScene*> scenes; 
	// SuperScene* scenes = start;
	// SuperScene* scenes = game;

	// scenes.push_back(new Scene19()); // canvas diffusion-limited aggregation
	// scenes.push_back(new Scene20()); // canvas mandelbrot
	// int s = scenes.size();

	// start running with the first Scene
	int scenecounter = 0;
	int running = 1;


	
	while (running) {
		
		//if (scenecounter > s-1) { scenecounter = 0; scene->activescene = 0; }
		//if (scenecounter < 0) { scenecounter = s-1; scene->activescene = s-1; }
		if (startscreen->playgame == true)
		{
			scenecounter = 1;
		}

		if(scenecounter == 0)
		{
			core.run(startscreen);
		}
		else if(scenecounter == 1)
		{
			core.run(maingame);
		}
		//scene = scenes[scenecounter];
		 // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!startscreen->isRunning() || !maingame->isRunning()) { running = 0; } // check status of Scene every frame
	}

	// delete all scenes
	// for (int i = 0; i < s; i++) {
	// 	delete scenes[i];
	// 	scenes[i] = nullptr;
	// }
	// scenes.clear();
	delete startscreen;
	delete maingame;

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{

	// create a grid
	pathTile = std::vector<PathTile*>();
	for (size_t y = 0; y < 17; y++)
	{
		for (size_t x = 0; x < 25; x++)
		{
			if(x % 4 == 0 || y % 4 == 0)
			{
				PathTile* e = new PathTile();
				e->position.x = x * 32 + 32;
				e->position.y = y * 32 + 32;
				pathTile.push_back(e);
				this->addChild(e);
			}
			
		}
	}
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	//this->removeChild(e);

	// delete myentity from the heap (there was a 'new' in the constructor)
	//delete e;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

}

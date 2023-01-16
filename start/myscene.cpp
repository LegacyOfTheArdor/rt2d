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

	playerOne = new Player();
	playerOne->sprite()->color = RED;
	playerOne->position = Point2(256,128);

	playerTwo = new Player();
	playerTwo->sprite()->color = BLUE;
	playerTwo->position = Point2(6400, 2176);
	
	this->addChild(playerOne);
	this->addChild(playerTwo);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(playerOne);
	this->removeChild(playerTwo);


	// delete myentity from the heap (there was a 'new' in the constructor)
	delete playerOne;
	delete playerTwo;
}

void MyScene::update(float deltaTime)
{
	if(input()->getKeyDown(KeyCode::W)) 
	{
		playerOne->GoUp();
	}

	if(input()->getKeyDown(KeyCode::D)) 
	{
	 	playerOne->GoRight();
	}

	if(input()->getKeyDown(KeyCode::S)) 
	{
		playerOne->GoDown();
	}

	if(input()->getKeyDown(KeyCode::A)) 
	{
 		playerOne->GoLeft();
	}

	if(input()->getKeyDown(KeyCode::Up)) 
	{
		playerTwo->GoUp();
	}

	if(input()->getKeyDown(KeyCode::Right)) 
	{
		playerTwo->GoRight();
	}

	if(input()->getKeyDown(KeyCode::Down)) 
	{
		playerTwo->GoDown();
	}

	if(input()->getKeyDown(KeyCode::Left)) 
	{
		playerTwo->GoLeft();
	}
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

}

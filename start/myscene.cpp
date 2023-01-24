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
	pathTiles = std::vector<PathTile*>();
	for (size_t y = 0; y < 17; y++)
	{
		for (size_t x = 0; x < 25; x++)
		{
			if(x % 4 == 0 || y % 4 == 0)
			{
				PathTile* path = new PathTile();
				path->position.x = x * 32 + 256;
				path->position.y = y * 32 + 128;
				pathTiles.push_back(path);
				this->addChild(path);
			}
			
		}
	}
	
	// create a second grid
	pointTiles = std::vector<PointTile*>();
	for (size_t y = 0; y < 4; y++)
	{
		for (size_t x = 0; x < 6; x++)
		{
			
			{
				PointTile* e = new PointTile();
				e->position.x = x * 128 + 320;
				e->position.y = y * 128 + 192;
				pointTiles.push_back(e);
				this->addChild(e);
			}
			
		}
	}

	//make a list for point tile neigbours 	
	for(int i = 0; i < pointTiles.size(); i++)
	{
		for(int j = 0; j < pathTiles.size(); j++)
		{
			Point point = pointTiles[i]->position;
			Point path =  pathTiles[j]->position;
			Vector2 diff = point - path;
			float distance = diff.getLength();
			if (distance < 90) {
				pointTiles[i]->addNeighbour(pathTiles[j]);
			}
		}
	}

	// create two players
	playerOne = new Player();
	playerOne->sprite()->color = RGBAColor(0, 241, 255, 255);
	playerOne->position = Point2(256,128);

	playerTwo = new Player();
	playerTwo->sprite()->color = RGBAColor(255, 0, 255, 255);
	playerTwo->position = Point2(1024, 640);
	playerTwo->rotation.z = PI;
	
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
	static int playerTileIndex = 0;
	static int player2TileIndex = 0;

	// player is on top of which pathTile????
	for(int i = 0; i < pathTiles.size(); i++)
	{
			bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, pathTiles[i]->position.x, pathTiles[i]->position.y);
		 	if (collide)
		 	{
				pathTiles[i]->sprite()->color = RGBAColor(0, 241, 255, 255);
				playerTileIndex = i;
		 	}

		 	bool collideP2 = circle2circleFloats(playerTwo->position.x, playerTwo->position.y, pathTiles[i]->position.x, pathTiles[i]->position.y);
		 	if (collideP2)
		 	{
				pathTiles[i]->sprite()->color = RGBAColor(255, 0, 255, 255);
				player2TileIndex = i;
		 	}
	}

	for (int i = 0; i < pointTiles.size(); i++)
	{
		bool collidePoint = circle2circleFloats(playerOne->position.x, playerOne->position.y, pointTiles[i]->position.x, pointTiles[i]->position.y, 64);
		if (collidePoint)
		{
			playerOne->position = Point(pathTiles[playerTileIndex]->position.x, pathTiles[playerTileIndex]->position.y);
		}

		bool collidePointp2 = circle2circleFloats(playerTwo->position.x, playerTwo->position.y, pointTiles[i]->position.x, pointTiles[i]->position.y, 64);
		if (collidePointp2)
		{
			playerTwo->position = Point(pathTiles[player2TileIndex]->position.x, pathTiles[player2TileIndex]->position.y);
		}
	}


	// player one and two movement
	if(input()->getKeyDown(KeyCode::W)) 
	{
		playerOne->GoUp();
		
		//player on player collision
		bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, playerTwo->position.x, playerTwo->position.y );
		if (collide) 
		{
			playerOne->position.y = playerOne->position.y + 32;
		}
		
	}

	if(input()->getKeyDown(KeyCode::D)) 
	{
	 	playerOne->GoRight();

		//player on player collision
		bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, playerTwo->position.x, playerTwo->position.y );
		if (collide) 
		{
			playerOne->position.x = playerOne->position.x - 32;
		}
	}

	if(input()->getKeyDown(KeyCode::S)) 
	{
		playerOne->GoDown();

		//player on player collision
		bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, playerTwo->position.x, playerTwo->position.y );
		if (collide) 
		{
			playerOne->position.y = playerOne->position.y - 32;
		}
	}

	if(input()->getKeyDown(KeyCode::A)) 
	{
 		playerOne->GoLeft();

		//player on player collision
		bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, playerTwo->position.x, playerTwo->position.y );
		if (collide) 
		{
			playerOne->position.x = playerOne->position.x + 32;
		}
	}

	if(input()->getKeyDown(KeyCode::Up)) 
	{
		playerTwo->GoUp();

		//player on player collision
		bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, playerTwo->position.x, playerTwo->position.y );
		if (collide) 
		{
			playerTwo->position.y = playerTwo->position.y + 32;
		}
	}

	if(input()->getKeyDown(KeyCode::Right)) 
	{
		playerTwo->GoRight();

		//player on player collision
		bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, playerTwo->position.x, playerTwo->position.y );
		if (collide) 
		{
			playerTwo->position.x = playerTwo->position.x - 32;
		}
	}

	if(input()->getKeyDown(KeyCode::Down)) 
	{
		playerTwo->GoDown();

		//player on player collision
		bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, playerTwo->position.x, playerTwo->position.y );
		if (collide) 
		{
			playerTwo->position.y = playerTwo->position.y - 32;
		}
	}

	if(input()->getKeyDown(KeyCode::Left)) 
	{
		playerTwo->GoLeft();

		//player on player collision
		bool collide = circle2circleFloats(playerOne->position.x, playerOne->position.y, playerTwo->position.x, playerTwo->position.y );
		if (collide) 
		{
			playerTwo->position.x = playerTwo->position.x + 32;
		}
	}

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}


}

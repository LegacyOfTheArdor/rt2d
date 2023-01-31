#include <fstream>
#include <sstream>

#include "startscreen.h"

StartScreen::StartScreen() : Scene()
{
	// make text for when you start the game;
	Text* startText = new Text;
	Text* explain = new Text;
	Text* oneExplain = new Text;
	Text* twoExplain = new Text;

	startText->message("PRESS SPACE TO START");
	startText->position = Point2(450, 600);
	startText->scale = Point2(0.5f, 0.5f);
	this->addChild(startText);

	explain->message("SUROUND THE STARS TO GAIN POINTS BEFORE THE TIME RUNS OUT!");
	explain->position = Point2(200, 200);
	explain->scale = Point2(0.5f, 0.5f);
	this->addChild(explain);

	oneExplain->message("PLAYER ONE USES W A S D TO MOVE!");
	oneExplain->position = Point2(375, 350);
	oneExplain->scale = Point2(0.5f, 0.5f);
	this->addChild(oneExplain);

	twoExplain->message(" PLAYER TWO USES THE ARROW KEYS TO MOVE!");
	twoExplain->position = Point2(300, 400);
	twoExplain->scale = Point2(0.5f, 0.5f);
	this->addChild(twoExplain);


	
}

StartScreen::~StartScreen()
{

}


void StartScreen::update(float deltaTime)
{
    if(input()->getKeyUp(KeyCode::Space))
    {
		playgame = true;
    }

	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}
}
#include <iostream>
#include "Gameplay.h"
#include "Menu.h"
#include "Brick.h"
#include "Paddle.h"
#include "Button.h"
#include "Ball.h"

using namespace std;

void Gameplay()
{
	int randomNum = rand() % (2) + 2;
	double deltaTime = 0.0;
	bool programIsRunning = true;

	bool isGamePaused = false;

	slWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Candy Breker", false);

	int playButton = slLoadTexture("res/PLAY_BUTTON.png");
	int rulesButton = slLoadTexture("res/BUTTON_RULES.png");
	int creditsButton = slLoadTexture("res/BUTTON_CREDITS.png");
	int exitButton = slLoadTexture("res/BUTTON_EXIT.png");
	int backButtonGame = slLoadTexture("res/BUTTON_BACK.png");
	int paddleImg = slLoadTexture("res/PADDLE.png");
	int brickImg = slLoadTexture("res/BRICK.png");
	int brickTwoImg = slLoadTexture("res/brick(amarillo).png");
	int brickThreeImg = slLoadTexture("res/brick(rojo).png");
	int ballImg = slLoadTexture("res/BALL.png");
	int tittle = slLoadTexture("res/TITTLE.png");
	int backButton = slLoadTexture("res/GOBACK_BUTTON.png");
	int backgroundOne = slLoadTexture("res/BackgroundOne.png");
	int backgroundTwo = slLoadTexture("res/BackgroundTwo.png");
	int font = slLoadFont("res/MotleyForces.ttf");

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE) && programIsRunning)
	{

		deltaTime = slGetDeltaTime();
		slSetBackColor(1.0, 1.0, 1.0);
		MenuDraw(backButtonGame, font, brickThreeImg, brickTwoImg, backButton,
			     backgroundOne, backgroundTwo, tittle, playButton, rulesButton,
			     creditsButton, exitButton, paddleImg, ballImg, brickImg);

		MenuUpdate(isGamePaused, deltaTime, programIsRunning);
	}

	slClose();

}

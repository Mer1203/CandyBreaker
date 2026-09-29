#include <iostream>
#include "Gameplay.h"
#include "Menu.h"
#include "Brick.h"
#include "Paddle.h"
#include "Ball.h"

using namespace std;

void Gameplay()
{
	double deltaTime = 0.0;
	bool programIsRunning = true;

	slWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Candy Breker", false);

	int playButton = slLoadTexture("../res/PLAY_BUTTON.png");
	int rulesButton = slLoadTexture("../res/BUTTON_RULES.png");
	int creditsButton = slLoadTexture("../res/BUTTON_CREDITS.png");
	int exitButton = slLoadTexture("../res/BUTTON_EXIT.png");
	int paddleImg = slLoadTexture("../res/PADDLE.png");
	int brickImg = slLoadTexture("../res/bricks.png");
	int ballImg = slLoadTexture("../res/BALL.png");
	int tittle = slLoadTexture("../res/TITTLE.png");
	int backButton = slLoadTexture("../res/BACK_BUTTON.png");
	int backgroundOne = slLoadTexture("../res/BackgroundOne.png");
	int backgroundTwo = slLoadTexture("../res/BackgroundTwo.png");

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE) && programIsRunning)
	{
		deltaTime = slGetDeltaTime();
		slSetBackColor(1.0, 1.0, 1.0);
		cout << ball.y << endl;
		MenuDraw(backButton, backgroundOne, backgroundTwo, tittle, playButton, rulesButton, creditsButton, exitButton, paddleImg, ballImg, brickImg);
		MenuUpdate(deltaTime, programIsRunning);
	}

	slClose();

}

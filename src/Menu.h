#pragma once
#include "sl.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int TITTLE_X = 395;
const int TITTLE_Y = 480;
const int TITTLE_WIDTH = 440;
const int TITTLE_HEIGHT = 180;

enum class Screen
{
	None = 0,
	Menu,
	Play,
	Rules,
	Credits,
	Exit
};

extern Screen currentScreen;

void MenuDraw(int brickThreeImg, int brickTwoImg, int backButton, int backgroundOne, int backgroundTwo, int tittle, int playButton, int rulesButton, int creditsButton, int exitButton, int paddleImg, int ballImg, int brickImg);
void MenuUpdate(double time, bool& programIsRunning);


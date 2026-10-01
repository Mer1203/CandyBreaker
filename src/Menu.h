#pragma once
#include "sl.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int TITTLE_X = 395;
const int TITTLE_Y = 460;
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

enum class WinorLose
{
	None = 0,
	Win,
	Lose
};

extern WinorLose winOrLose;

void WinorLoseGame(bool& isGamePaused);
void MenuDraw(int backButtonGame, int font, int brickThreeImg, int brickTwoImg, int backButton,
 	          int backgroundOne, int backgroundTwo, int tittle, int playButton, 
	          int rulesButton, int creditsButton, int exitButton, 
	          int paddleImg, int ballImg, int brickImg);
void MenuUpdate(bool& isGamePaused, double time, bool& programIsRunning);


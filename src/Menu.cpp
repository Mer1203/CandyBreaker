#include "sl.h"
#include "Menu.h"
#include "Text.h"
#include "Ball.h"
#include <string>
#include "Brick.h"
#include "Paddle.h"
#include "Button.h"
#include <iostream>
#include "Collision.h"

using namespace std;
Screen currentScreen = Screen::Menu;

void MenuUpdate(double time, bool& programIsRunning)
{
	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		ChangeSceneWhenButtonPressed();
		PaddleInit();
		BallInit();
		BrickInit();

		break;
	case Screen::Play:
		BallUpdate(time);
		PaddleUpdate(time);
		CheckPaddleCollision();
		CheckBallCollision();
		CheckBallBorders();
		CheckPaddleBorders();
		ChangeSceneWhenBackButtonPressed();
		break;
	case Screen::Rules:
		ChangeSceneWhenBackButtonPressed();
		break;
	case Screen::Credits:
		ChangeSceneWhenBackButtonPressed();
		break;
	case Screen::Exit:
		programIsRunning = false;
		break;
	default:
		break;
	}
}

void MenuDraw(int font, int brickThreeImg, int brickTwoImg, int backButton, int backgroundOne, int backgroundTwo, int tittle, int playButton, int rulesButton, int creditsButton, int exitButton, int paddleImg, int ballImg, int brickImg)
{
	string textOne = "0";
	string textTwo = "0";

	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		//FONDO
		slSprite(backgroundTwo, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);
		//TITULO
		slSprite(tittle, TITTLE_X, TITTLE_Y, TITTLE_WIDTH, TITTLE_HEIGHT);
		//DIBUJADO BOTONES
		ButtonMenuDraw(playButton, rulesButton, creditsButton, exitButton);
		//COLISIONES BOTONES
		ChangeButtonColorOnCollision(positionButtonPlayY, playButton);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(positionButtonRulesY, rulesButton);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(positionButtonCreditsY, creditsButton);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(positionButtonExitY, exitButton);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		break;
	case Screen::Play:
		//Fondo:
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slSprite(backgroundOne, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);

		PaddleDraw(paddleImg);
		BallDraw(ballImg);
		BrickDraw(brickThreeImg, brickImg, brickTwoImg);
		BackButtonDraw(backButton);
		ChangeBackButtonColorOnCollision(backButton);
		GameplayText(textOne, textTwo, font);
		break;
	case Screen::Rules:
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slSprite(backgroundOne, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);
		BackButtonDraw(backButton);
		ChangeBackButtonColorOnCollision(backButton);
		break;
	case Screen::Credits:
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slSprite(backgroundOne, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);
		CreditsText(font);
		BackButtonDraw(backButton);
		ChangeBackButtonColorOnCollision(backButton);
		break;
	case Screen::Exit:
		break;
	default:
		break;
	}

	slRender();
}


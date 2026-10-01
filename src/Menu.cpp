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
WinorLose winOrLose = WinorLose::None;

void MenuUpdate(bool& isGamePaused, double time, bool& programIsRunning)
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

		if (slGetKey('P') || slGetKey('p'))
		{
			isGamePaused = !isGamePaused;
		}

		if (player.isAlive == false)
		{
			winOrLose = WinorLose::Lose;
		}
		else if (player.won == true)
		{
			winOrLose = WinorLose::Win;
		}

		if (isGamePaused == true || player.won == true || player.isAlive == false)
		{
			return;
		}

		BallUpdate(time);
		PaddleUpdate(time);
		PlayerLose();
		PlayerWin();
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

void MenuDraw(int backButtonGame,  int font, int brickThreeImg, int brickTwoImg, int backButton, int backgroundOne,
              int backgroundTwo, int tittle, int playButton, int rulesButton, int creditsButton,
	          int exitButton, int paddleImg, int ballImg, int brickImg)
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
		ChangeButtonColorOnCollision(playButton, POSITION_BUTTON_X, positionButtonPlayY, WIDTH_BUTTON, HEIGHT_BUTTON);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(rulesButton, POSITION_BUTTON_X, positionButtonRulesY, WIDTH_BUTTON, HEIGHT_BUTTON);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(creditsButton, POSITION_BUTTON_X, positionButtonCreditsY, WIDTH_BUTTON, HEIGHT_BUTTON);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(exitButton, POSITION_BUTTON_X, positionButtonExitY, WIDTH_BUTTON, HEIGHT_BUTTON);
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
		ChangeButtonColorOnCollision(BACK_BUTTON_Y, BACK_BUTTON_X, BACK_BUTTON_Y, WIDTH_BACK_BUTTON, HEIGHT_BACK_BUTTON);
		GameplayText(textOne, textTwo, font);

		switch (winOrLose)
		{
		case WinorLose::None:
			break;
		case WinorLose::Win:
			if (player.won == true)
			{
				Win(font, backButtonGame);
			}

			break;
		case WinorLose::Lose:
			if (player.isAlive == false)
			{
				Lose(font, backButtonGame);
			}
			break;
		default:
			break;
		}

		break;
	case Screen::Rules:
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slSprite(backgroundOne, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);
		RulesText(font);
		BackButtonDraw(backButton);
		ChangeButtonColorOnCollision(BACK_BUTTON_Y, BACK_BUTTON_X, BACK_BUTTON_Y, WIDTH_BACK_BUTTON, HEIGHT_BACK_BUTTON);
		break;
	case Screen::Credits:
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slSprite(backgroundOne, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);
		CreditsText(font);
		BackButtonDraw(backButton);
		ChangeButtonColorOnCollision(BACK_BUTTON_Y, BACK_BUTTON_X, BACK_BUTTON_Y, WIDTH_BACK_BUTTON, HEIGHT_BACK_BUTTON);
		break;
	case Screen::Exit:
		break;
	default:
		break;
	}

	slRender();
}

void WinorLoseGame(bool& isGamePaused)
{
	if (slGetKey('P') || slGetKey('p'))
	{
		isGamePaused = !isGamePaused;
	}

	if (player.isAlive == false || player.won == true)
	{
		currentScreen = Screen::Menu;
	}

	if (isGamePaused == true || player.won == true || player.isAlive == false)
	{
		return;
	}
}